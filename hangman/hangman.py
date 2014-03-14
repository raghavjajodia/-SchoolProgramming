import random
import string

WORDLIST_FILENAME = "words.txt"

def load_words():
    print "Loading word list from file..."
    inFile = open(WORDLIST_FILENAME, 'r', 0)
    line = inFile.readline()
    wordlist = string.split(line)
    print "  ", len(wordlist), "words loaded."
    return wordlist

def choose_word(wordlist):
    return random.choice(wordlist)

wordlist = load_words()

print('welcome to the game')
word=choose_word(wordlist)
guess=8
flag=True
show=''
for i in range(len(word)):
    show=show+'-'
available=string.lowercase[:26]
while(guess>0 and flag):
    print '____________________'
    print 'You have',guess,'guesses left'
    print 'your word is',show
    print 'Available letters',available
    g=string.lower(raw_input('Your current guess is:'))
    if g in word:
        shownew=''
        for i in range(len(word)):
            if show[i]!='-':
                shownew=shownew+show[i]
            elif word[i]==g:
                shownew=shownew+g
            else:
                shownew=shownew+'-'
        show=shownew
        print 'correct guess:',show
    else:
        print 'wrong guess'
        guess=guess-1
    available=available.replace(g,'')
    if '-' not in show:
        flag=False
        print 'Congrats you win the game'
if (guess==0):
    print 'You died :P'
print 'The word was',word
print 'Thanx for playing the game'
   
    
    
