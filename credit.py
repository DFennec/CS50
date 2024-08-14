number = input("Number: ")

if len(number) == 15 and number[0] == "3" and (number[1] == "4" or number[1] == "7"):
    print("AMEX")
elif len(number) == 16 and number[0] == "5" and (number[1] == "1" or number[1] == "2" or number[1] == "3" or number[1] == "4" or number[1] == "5"):
    print("MASTERCARD")
elif number[0] == "4" and (len(number) == 13 or len(number) == 16):
    checksum = 0
    counter = 0
    caster = ""
    while counter < len(number):

        if counter % 2 == 0:
            if len(number) == 13 and counter == 12:
                checksum += int(number[counter])
                break
            if int(number[counter])*2 > 9:
                caster = str(int(number[counter])*2)
                checksum += int(caster[0])+int(caster[1])
            else:
                checksum += int(number[counter])*2
        else:
            print(counter, "-", number[counter])
            checksum += int(number[counter])
        counter += 1
    print(checksum)
    if checksum % 10 == 0:
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
