def get_int(prompt):
    return int(input(prompt))

def main():

    while True:
        try:#exception handling
            x= get_int("x: ")
            break
        except:#what the code will do if it fails
            print("Invalid input")

    while True:
        try:
            y= get_int("y: ")
            break
        except:
            print("Invalid input")

    print(x+y)

main()
