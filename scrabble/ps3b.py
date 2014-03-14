from ps3a import *
import time
from perm import *
#
#
# Problem #6A: Computer chooses a word
#
#
def comp_choose_word(hand, word_list):
    
    score=0
    maxword=''
    for i in range(len(hand),0,-1):
        lis=get_perms(hand,i)
        for w in lis:
            if w in word_list:
                t=get_word_score(w, len(hand))
                if t>score:
                    maxword=w[:]
                    score=t
    if maxword=='':
        return '.'
    else:
        return(maxword)
        


def comp_play_hand(hand, word_list):
    
    total=0
    while(True):
        temp=0
        print 'Current Hand:',display_hand(hand)
        word=comp_choose_word(hand, word_list)
        print 'Comp chose',word
        if word=='.':
            break
        else:
            temp=get_word_score(word,HAND_SIZE)
            print '"',word,'" earned',temp,'points'
            total=total+temp
            hand=update_hand(hand, word)
    print 'Total score:',total

def play_game(word_list):
    
    while(True):
        c=raw_input(' Enter n for a new (random) hand \n r for the last hand again \n e to exit the game: ')
        while c!='n' and c!='r' and c!='e':
            print 'Enter again'
            c=raw_input(' Enter n for a new (random) hand \n r for the last hand again \n e to exit the game: ')
        if c=='n':
            hand1=deal_hand(HAND_SIZE)
            hand2=dict(hand1)
            play_hand(hand2,word_list)
        elif c=='r':
            hand2=dict(hand1)
            play_hand(hand2,word_list)
        else:
            print 'Thanx for playing game'
            break
        while(True):
            d=raw_input(' Enter u to play as user \n c To let computer play: ')
            if d=='u':
                break
            elif d=='c':
                hand2=dict(hand1)
                comp_play_hand(hand2, word_list)
                break
            else:
                print 'Enter again'
                    

if __name__ == '__main__':
    word_list = load_words()
    play_game(word_list)
 
    
