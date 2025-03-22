import random

def guess_word():
    words = ["mavu", "python", "java", "kotlin", "javascript", "ruby"]
    word_to_guess = random.choice(words)
    attempts = 6
    guessed_letters = set()
    correct_letters = set(word_to_guess)

    print("Welcome to the Word Guessing Game!")
    print("I have selected a programming language. Can you guess it?")

    while attempts > 0 and correct_letters:
        print("\nAttempts remaining:", attempts)
        print("Guessed letters:", " ".join(sorted(guessed_letters)))
        display_word = [letter if letter in guessed_letters else "_" for letter in word_to_guess]
        print("Word:", " ".join(display_word))

        guess = input("Enter a letter: ").lower()
        if guess in guessed_letters:
            print("You already guessed that letter. Try again.")
        elif guess in correct_letters:
            guessed_letters.add(guess)
            correct_letters.remove(guess)
            print("Good guess!")
        else:
            guessed_letters.add(guess)
            attempts -= 1
            print("Wrong guess!")

    if not correct_letters:
        print("\nCongratulations! You've guessed the word:", word_to_guess)
    else:
        print("\nGame over! The word was:", word_to_guess)

# Start the game
guess_word()
