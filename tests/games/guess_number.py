import random

def guess_number():
    # Generate a random number between 1 and 100
    number_to_guess = random.randint(1, 100)
    attempts = 0
    guessed = False

    print("Welcome to the Number Guessing Game!")
    print("I have selected a number between 1 and 100. Can you guess it?")

    while not guessed:
        # Get the user's guess
        user_guess = int(input("Enter your guess: "))
        attempts += 1

        # Check if the guess is correct
        if user_guess == number_to_guess:
            guessed = True
            print(f"Congratulations! You've guessed the number in {attempts} attempts.")
        elif user_guess < number_to_guess:
            print("Too low! Try again.")
        else:
            print("Too high! Try again.")

# Start the game
guess_number()
