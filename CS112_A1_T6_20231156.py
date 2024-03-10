# program : A board of 3 x 3 is displayed and player 1 takes odd numbers 1, 3, 5, 7, 9 and player 2 takes even numbers 0, 2, 4, 6, 8. Players take turns to write their numbers. Odd numbers start. Use each number only once. The first person to complete a line that adds up to 15 is the winner. The line can have both odd and even numbers.  the last coin wins.
# Author : Maram Esameil Abd-Elfattah
#section: s12,s22
#ID: 20231156
#version: V.01
#Date: March 3,2024

from itertools import combinations
def winnercheck(board): #defining the winner
    for combination in combinations(range(9),3):# to check if the indeces form a line
        if (int(combination[0]) - int(combination[1]) == 1 and int(combination[1]) - int(combination[2]) == 1) or (int(combination[0]) - int(combination[1]) == -1 and int(combination[1]) - int(combination[2]) == -1): #horizontal line
            if any(not board[index].isdigit() for index in combination):
                continue
            else:
                if int(board[combination[0]]) + int(board[combination[1]]) + int(board[combination[2]]) == 15:
                    return True
        elif (int(combination[0]) - int(combination[1]) == 3 and int(combination[1]) - int(combination[2]) == 3) or (int(combination[0]) - int(combination[1]) == -3 and int(combination[1]) - int(combination[2]) == -3):#vertical line
            if any(not board[index].isdigit() for index in combination):
                continue
            else:
                if int(board[combination[0]]) + int(board[combination[1]]) + int(board[combination[2]]) == 15:
                    return True
        elif (int(combination[0]) - int(combination[1]) == 4 and int(combination[1]) - int(combination[2]) == 4) or (int(combination[0]) - int(combination[1]) == -4 and int(combination[1]) - int(combination[2]) == -4):#diagonal line
            if any(not board[index].isdigit() for index in combination):
                continue
            else:
                if int(board[combination[0]]) + int(board[combination[1]]) + int(board[combination[2]]) == 15:
                    return True
        elif (int(combination[0]) - int(combination[1]) == 2 and int(combination[1]) - int(combination[2]) == 2) or (int(combination[0]) - int(combination[1]) == -2 and int(combination[1]) - int(combination[2]) == -2):#diagonal line
            if any(not board[index].isdigit() for index in combination):
                continue
            else:
                if int(board[combination[0]]) + int(board[combination[1]]) + int(board[combination[2]]) == 15:
                    return True
        else : continue
    return False


def tiecheck(board): # if there are no more empty spaces, then its a tie
    for index in board:
        if not str(index).isdigit():
            return False
    return True
while True:
    game_board = ["1️⃣", "2️⃣", "3️⃣", "4️⃣", "5️⃣", "6️⃣", "7️⃣", "8️⃣", "9️⃣"] # to replace with player input
    available = [1,2,3,4,5,6,7,8,9] # to make sure the player doesn`t use the same spot twice
    table = f"\n| {game_board[0]} | {game_board[1]} | {game_board[2]} |\n| {game_board[3]} | {game_board[4]} | {game_board[5]} |\n| {game_board[6]} | {game_board[7]} | {game_board[8]} |"
    oddplayer = [1,3,5,7,9] #player 1`s available numbers
    evenplayer = [0,2,4,6,8] #player2`s available numbers
    player = 1
    while True:
        print(table)
        if player == 1:

            move1 = input(f"player {player}, choose a number from the available number list : {oddplayer}\n")
            while not (move1.isdigit() and int(move1) in oddplayer):  # to check if the input is a valid number and available in the list of offered numbers
                move1 = input(f"invalid number, player {player}, choose a number from the available number list : {oddplayer}\n")

            place = input(f"choose which spot you want to put the number {move1}\n")
            while not (place.isdigit() and int(place) in available):  # to make sure the player doesn`t use the same spot twice and to check if the input is a number
                place = input(f"invalid spot, choose another spot in which you want to put the number {move1}\n")
            available.remove(int(place))  # remove the selected number so the player cant use it again
            game_board[int(place) - 1] = move1
            oddplayer.remove(int(move1))
            table = f"\n| {game_board[0]} | {game_board[1]} | {game_board[2]} |\n| {game_board[3]} | {game_board[4]} | {game_board[5]} |\n| {game_board[6]} | {game_board[7]} | {game_board[8]} |"
            if winnercheck(game_board):
                print("Player 1 has Won, Congrats !!")
                break
            elif tiecheck(game_board):
                print("It`s a Tie :(")
                break
        elif player == 2:
            move2 = input(f"player {player}, choose a number from the available number list : {evenplayer}\n")
            while not (move2.isdigit() and int(move2) in evenplayer):  # to check if the input is a valid number and available in the list of offered numbers
                move2 = input(f"invalid number, player {player}, choose a number from the available number list : {evenplayer}\n")
            place = input(f"choose which spot you want to put the number {move2}\n")
            while not (place.isdigit() and int(place) in available):  # to make sure the player doesn`t use the same spot twice and to check if the input is a number
                place = input(f"invalid spot, choose another spot in which you want to put the number {move2}\n")
            available.remove(int(place)) # remove the selected number so the player cant use it again
            game_board[int(place) -1] = move2
            evenplayer.remove(int(move2))
            table = f"\n| {game_board[0]} | {game_board[1]} | {game_board[2]} |\n| {game_board[3]} | {game_board[4]} | {game_board[5]} |\n| {game_board[6]} | {game_board[7]} | {game_board[8]} |"
            if winnercheck(game_board):
                print("Player 2 has Won, Congrats !!")
                break
            elif tiecheck(game_board):
                print("It`s a Tie :(")
                break
        if player == 1 : player = 2
        else : player = 1
    while True: #let the players choose if they want to play again
        choice = str(input("Do you want to play again?\nA) Play again\nB) End the game\n")).upper()
        if choice == "B":
            quit()
        elif choice != "A":
            print("Please choice between A or B")
            continue
        break