#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void menu();
int roll_a_dice();
int compute_points(int,int);


int main(){

    srand(time(NULL));
    int option,turnCounter=1,roundCounter=1,player1RoundPoint,player2RoundPoint,player1OverallPoint=0,player2OverallPoint=0;
    int dice1,dice2;
    menu();
    scanf("%d",&option);

    while(option!=1 && option!=2){
        fflush(stdin);
        printf("Please enter option either 1 or 2!\n");
        printf("Option: ");
        scanf("%d",&option);
    }

    if(option==1){
        printf("\n\nBO BING STARTS\n");
        printf("Dice are rolled by each player in order to select who will start first:\n");
        dice1=roll_a_dice();
        dice2=roll_a_dice();
        printf("Dice 1 (rolled by player 1): %d\tDice 2 (rolled by player 2): %d\n",dice1,dice2);

        while(dice1==dice2){
            printf("Equal dice by bot players! Dice are rolled again!\n");
            dice1=roll_a_dice();
            dice2=roll_a_dice();
            printf("Dice 1 (rolled by player 1): %d\tDice 2 (rolled by player 2): %d\n",dice1,dice2);
        }

        if(dice1>dice2){//player 1 starts
            printf("Player 1 is starting!\n\n");
            while(roundCounter<=3){
                printf("ROUND %d\n",roundCounter);
                printf("------------------------------------------------\n");
                printf("PLAYER 1'S TURN\n\n");

                while(turnCounter<=3){
                    printf("Dice are rolled: ");
                    dice1=roll_a_dice();
                    dice2=roll_a_dice();
                    printf("Dice 1: %d\tDice 2: %d\n",dice1,dice2);
                    player1RoundPoint=compute_points(dice1,dice2);
                    printf("Points: %d\n",player1RoundPoint);
                    player1OverallPoint+=player1RoundPoint;
                    printf("Total Points: %d\n\n",player1OverallPoint);
                    turnCounter++;
                }
                printf("PLAYER 1'S TURN IS OVER!\n");
                printf("Round %d POINTS: %d\n\n",roundCounter,player1RoundPoint);
                turnCounter=1;

                while(turnCounter<=3){
                    printf("PLAYER 2'S TURN\n");
                    printf("Dice are rolled: ");
                    dice1=roll_a_dice();
                    dice2=roll_a_dice();
                    printf("Dice 1: %d\tDice 2: %d\n",dice1,dice2);
                    player2RoundPoint=compute_points(dice1,dice2);
                    printf("Points: %d\n",player2RoundPoint);
                    player2OverallPoint+=player2RoundPoint;
                    printf("Total Points: %d\n\n",player2OverallPoint);
                    turnCounter++;
                }
                printf("PLAYER 2'S TURN IS OVER!\n");
                printf("Round %d POINTS: %d\n\n",roundCounter,player2RoundPoint);
                turnCounter=1;

                roundCounter++;
            }
        }
        else{//player2 starts
            printf("Player 2 is starting!\n\n");
            while(roundCounter<=3){
                printf("ROUND %d\n",roundCounter);
                printf("------------------------------------------------\n");
                printf("PLAYER 2'S TURN\n\n");

                while(turnCounter<=3){
                    printf("Dice are rolled: ");
                    dice1=roll_a_dice();
                    dice2=roll_a_dice();
                    printf("Dice 1: %d\tDice 2: %d\n",dice1,dice2);
                    player2RoundPoint=compute_points(dice1,dice2);
                    printf("Points: %d\n",player2RoundPoint);
                    player2OverallPoint+=player2RoundPoint;
                    printf("Total Points: %d\n\n",player2OverallPoint);
                    turnCounter++;
                }
                printf("PLAYER 2'S TURN IS OVER!\n");
                printf("Round %d POINTS: %d\n\n",roundCounter,player2RoundPoint);
                turnCounter=1;

                while(turnCounter<=3){
                    printf("PLAYER 1'S TURN\n");
                    printf("Dice are rolled: ");
                    dice1=roll_a_dice();
                    dice2=roll_a_dice();
                    printf("Dice 1: %d\tDice 2: %d\n",dice1,dice2);
                    player1RoundPoint=compute_points(dice1,dice2);
                    printf("Points: %d\n",player1RoundPoint);
                    player1OverallPoint+=player1RoundPoint;
                    printf("Total Points: %d\n\n",player1OverallPoint);
                    turnCounter++;
                }
                printf("PLAYER 1'S TURN IS OVER!\n");
                printf("Round %d POINTS: %d\n\n",roundCounter,player1RoundPoint);
                turnCounter=1;

                roundCounter++;
            }
        }

        printf("FINAL RESULT:\n");
            printf("-----------------------------------\n");
            printf("PLAYER 1: %d POINTS\n",player1OverallPoint);
            printf("PLAYER 2: %d POINTS\n\n",player2OverallPoint);

            if(player1OverallPoint>player2OverallPoint)
                printf("PLAYER 1 IS WINNER! CONGRATULATIONS...");
            else if(player2OverallPoint>player1OverallPoint)
                printf("PLAYER 2 IS WINNER! CONGRATULATIONS...");
            else
                printf("DRAW...");
    }
    else{
        printf("Bye!");
    }









return 0;

}

void menu(){
    printf("BO BING GAME!\n");
    printf("Choose one from the followings:\n ");
    printf("1. Start the game by selecting who will start first\n");
    printf("2. Exit\n");
    printf("Option: ");
}

int roll_a_dice(){
    return 1+(rand()%6);
}

int compute_points(int dice1,int dice2){
    if(dice1==dice2)
        return 300;
    else{
        if(dice1==1 || dice2==1)
            return 100;
        else
            return 200;
    }
}





