scores = []

for i in range(3):
    score=int(input("Score: "))
    scores.append(score)#you could also do: scores=scores+[score]

average = sum(scores)/len(scores)

print("Average:",average)

for n in scores:
    if n==0:
        print("You got marked with a zero?!")
        break
else:#if you use an else in a for loop the else will trigger after fully running through the loop condition, which can be prevented with a break
    print("No zeroes found, neat!")
