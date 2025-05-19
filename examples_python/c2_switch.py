print("""
What is your favortie color (input the number):
      1. Red
      2. Blue
      3. Green
      4. Yellow
""")

user_input = int(input())

if user_input == 1:
    print("You must like apples!\n")
elif user_input == 2:
    print("You must like looking at the sky!\n")
elif user_input == 3:
    print("You must like vegetables!\n")
elif user_input == 4:
    print("You must like looking at the Sun! (And you should probably stop...)\n")
else:
    print("I've never heard of that color...:(\n")