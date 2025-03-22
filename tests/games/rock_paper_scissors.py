import random

def rock_paper_scissors():
    choices = ["rock", "paper", "scissors"]
    computer_choice = random.choice(choices)
    user_choice = ""

    print("Welcome to Rock, Paper, Scissors!")
    print("Make your choice: rock, paper, or scissors")

    while user_choice not in choices:
        user_choice = input("Enter your choice: ").lower()

    print(f"Computer chose: {computer_choice}")
    print(f"You chose: {user_choice}")

    if user_choice == computer_choice:
        print("It's a tie!")
    elif (user_choice == "rock" and computer_choice == "scissors") or \
         (user_choice == "paper" and computer_choice == "rock") or \
         (user_choice == "scissors" and computer_choice == "paper"):
        print("You win!")
    else:
        print("You lose!")

# Start the game
rock_paper_scissors()
