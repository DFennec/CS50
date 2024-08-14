people = [
    {"name":"Carter", "number":"600250500"},
    {"name":"David", "number":"600250500"},
    {"name":"John", "number":"9494682750"}
]#dictionaries are built by the key-value structure, just like APIs

name =input("Name: ")

for person in people:
    if person["name"] == name:
        print(f"Found {person['number']}")
        break
else:
    print("Not found")
