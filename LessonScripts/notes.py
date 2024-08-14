

answer = input("What's your name? ")
print("Hello,", answer)
print("Hello, "+ answer)
print(f"Hello, {answer}")
x=int(input("x:"))#by default this would be a string, hence the cast
y=int(input("y:"))

print(int(x)+int(y))#casting in the print statement would also work

print(x+y)

#if you use a library that happens to have a function with the same name
#you can just refer to it like this: libraryname.functionname()
#as for your function you can simply call it by the name you asigned

if x<y:
    print("y is greater than x")
elif x>y:
    print("y is less than x")
else:
    print("y is equal to x")

if str(x)==str(y):#string comparison of x and y
    print("Same")
else:
    print("Different")

if x==0 or y==0:#or and and aren't written like || or && but literally in English
    print("There's a zero")
else:
    print("There are no zeroes")

if answer.lower() in ["alvaro","álvaro"]:#handling strings to standarize input
    print("name properly written")
else:
    print("you didn't write your name properly")
#loops
i=0
while i < 3:
    print("Meow")
    i+=1;
for _ in range(3):#replacing i by _ to write more pythonic code, though i is also fine
    print("Hello, world")

print("Keep python from using \\n: ", end="")

xD=int(input("   xD: "))
yD=int(input("yD: "))

z=x/y
print(z)
print(f"{z:.2f}")#truncates the result to two decimal places
