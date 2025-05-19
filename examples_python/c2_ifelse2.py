# Python code
guess = int(input("Input your guess for the magic number: "))
magic_number = 25
lower_bound = 20
upper_bound = 30
very_close_range = 3

if guess == magic_number:
    print("Congratulations! You've guessed the magic number!")
elif guess >= (magic_number - very_close_range) and guess <= (magic_number + very_close_range):
    print("So close! You're within ", very_close_range, " numbers of the magic number.")
elif guess < magic_number:
    print("Too low! Try guessing a higher number.")
else:
    print("Too high! Try guessing a lower number.")