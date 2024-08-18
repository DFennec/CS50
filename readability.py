text = input("Text: ")

letters=0
words=1
sentences=0

for characters in text:

    if characters==" "or characters=="'":
        words+=1
    elif characters!=" " and characters!="," and characters!="." and characters!="?" and characters!="!":
        letters+=1
    if characters=="." or characters=="!" or characters=="?":
        sentences+=1

L=(letters/words)*100
S=(sentences/words)*100

index = round((0.0588 * L) - (0.296 * S) - 15.8)

if index<2:
    print("Before Grade 1")
elif index>16:
    print("Grade 16+")
else:
    print("Grade",index)

