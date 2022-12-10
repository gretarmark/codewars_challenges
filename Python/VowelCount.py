
# -*- coding: utf-8 -*-
"""
Created on Sat Dec 10 14:26:59 2022

@author: Grétar Már Kjartansson
"""

"""
Return the number (count) of vowels in the given string.
We will consider a, e, i, o, u as vowels for this Kata (but not y).
The input string will only consist of lower case letters and/or spaces.
"""

"""***************FUNCTIONS***********************"""
def get_count(sentence):

    count = 0
    
    for character in sentence:
        if character == "a":
            count +=1
        if character == "e":
            count += 1
        if character == "i":
            count += 1
        if character == "o":
            count += 1
        if character == "u":
            count += 1
                     
    return count


"""****************Main Code*********************"""

aa = get_count("abracadabra")

print(aa)
