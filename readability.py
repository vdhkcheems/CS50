txt = input("Text: ")

letters = 0
sentences = 0
words = 0
for i in txt:
    if i.isalpha() == True:
        letters += 1
    elif i == "." or i == "?" or i=="!":
        sentences += 1
    elif i == " ":
        words += 1

words +=1

L = (letters/words)*100
S = (sentences/words)*100

I = 0.0588 * L - 0.296 * S - 15.8

I = round(I)

if I < 1:
    print("Before Grade 1")
elif I >= 16:
    print("Grade 16+")
else:
    print("Grade", I)