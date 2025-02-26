mywords_set = {"barca", "cityc", "parisp", "madrid" }
randomword = mywords_set.pop().lower()      
name = input("Enter your name: ").capitalize().strip()

emptyword =list()                    # an empty list to make '_'  before inserting the letters
for i in range(len(randomword)):
    emptyword += "_"

newword =""
i = 0
c=0
while i <  7:
    alpha = input("Enter a letter: ")
    if alpha in randomword:
        if alpha in emptyword:
            j = emptyword.index(alpha)
            c = randomword.index(alpha, j+1)
        else:
            c = randomword.index(alpha)  #determine the position of the letter in the random word
        emptyword[c] = alpha         # put the letter in that position in the empty word
        newword = "".join(emptyword) # transfer the (emtpy word) from a list to a string and put it in (new word)
        print(newword)
    else:
         print("Try again !")

    if newword == randomword:    
        print("Congratulations" , name , "! <3")
        break
    i +=1        # increasing the i in while loop by 1 each trial of the 7 trials    

    if i ==7 and newword != randomword :
        print("GAME OVER YA FASHELL ..") 