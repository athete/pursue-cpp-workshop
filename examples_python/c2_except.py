max_attempts = 3
magic_num = 10

for i in range(max_attempts):
    try:
        x = int(input("Enter the magic number: "))
        if x != magic_num:
            raise ValueError("That is not the magic number. Try again!")
    except:
        print(f"You have {max_attempts - i - 1} attempts left.")
        if i + 1 == max_attempts:
            print("You lost :(")