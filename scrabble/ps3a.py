

import random
import string

VOWELS = 'aeiou'
CONSONANTS = 'bcdfghjklmnpqrstvwxyz'
HAND_SIZE = 7

SCRABBLE_LETTER_VALUES = {
    'a': 1, 'b': 3, 'c': 3, 'd': 2, 'e': 1, 'f': 4, 'g': 2, 'h': 4, 'i': 1, 'j': 8, 'k': 5, 'l': 1, 'm': 3, 'n': 1, 'o': 1, 'p': 3, 'q': 10, 'r': 1, 's': 1, 't': 1, 'u': 1, 'v': 4, 'w': 4, 'x': 8, 'y': 4, 'z': 10
}


WORDLIST_FILENAME = "words.txt"

def load_words():
   
    print "Loading word list from file..."
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r', 0)
    # wordlist: list of strings
    wordlist = []
    for line in inFile:
        wordlist.append(line.strip().lower())
    print "  ", len(wordlist), "words loaded."
    return wordlist

def get_frequency_dict(sequence):
   
    
    freq = {}
    for x in sequence:
        freq[x] = freq.get(x,0) + 1
    return freq
	

def get_word_score(word, n):
   
   #TO DO
    score=0
    for c in word:
        score=score+SCRABBLE_LETTER_VALUES[c]
    score=score*len(word)
    if len(word)==n:
        score=score+50
    return score

def display_hand(hand):
   
    for letter in hand.keys():
        for j in range(hand[letter]):
             print letter,              
    print ''                              

def deal_hand(n):
   
    hand={}
    num_vowels = n / 3
    
    for i in range(num_vowels):
        x = VOWELS[random.randrange(0,len(VOWELS))]
        hand[x] = hand.get(x, 0) + 1
        
    for i in range(num_vowels, n):    
        x = CONSONANTS[random.randrange(0,len(CONSONANTS))]
        hand[x] = hand.get(x, 0) + 1
        
    return hand


def update_hand(hand, word):
  
    for c in word:
        if hand[c]>1:
            hand[c]=hand[c]-1
        else:
            del hand[c]
    return hand

def is_valid_word(word, hand, word_list):
   
    flag1=False
    flag2=True
    hand1=dict(hand)
    if word in word_list:
        flag1=True
    for c in word:
        if c in hand1.keys() and hand1[c]>0:
            hand1[c]=hand1[c]-1
        else:
            flag2=False
            break
    
    if flag1 and flag2:
        return True
    else:
        return False

def calculate_handlen(hand):
    handlen = 0
    for v in hand.values():
        handlen += v
    return handlen

def play_hand(hand, word_list):

   
    total=0
    while(True):
        temp=0
        print 'Current Hand:',display_hand(hand)
        word=raw_input('Enter word, or a "." to indicate that you are finished:')
        if word=='.':
            break
        elif (is_valid_word(word,hand, word_list)):
            temp=get_word_score(word,HAND_SIZE)
            print '"',word,'" earned',temp,'points'
            total=total+temp
            hand=update_hand(hand, word)
        else:
            print 'Invalid word, please try again.'
    print 'Total score:',total





 
