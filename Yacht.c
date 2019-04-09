#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes -- (for initialization)
int roll_a_dice();
int play_computer(int, int, int, int, int, int);
static int computer_strategy_decider(int , int, int, int, int, int, int, int, int, int, int);
int play_human(int, int, int, int, int, int);
int scoring_system(int, int, int, int, int, int);
void scoresheet(int, int ,int);

int main ()
{
    //Displaying Current round
    int _round;
    //Human Cumulative and Current Score records
    int h_Accumulated_Score = 0, h_Current_Score = 0;
    //Computer Cumulative and Current Score records
    int c_Accumulated_Score = 0, c_Current_Score = 0;
    //Game's player priority record
    int player_First, computer_first;
    //Game starter player name
    char starter_name;
    int game_player_condition;
    //Human Strategy holders
    static int h_strategy_1 = 0, h_strategy_2 = 0, h_strategy_3 = 0, h_strategy_4 = 0, h_strategy_5 = 0, h_strategy_6 = 0;
    //Computer Strategy holders
    static int comp_strategy_1 = 0, comp_strategy_2 = 0, comp_strategy_3 = 0, comp_strategy_4 = 0, comp_strategy_5 = 0, comp_strategy_6 =0;
    srand(time(NULL));
    player_First = roll_a_dice();
    computer_first = roll_a_dice();
    printf("Welcome to the Yahtzee game.\nLet\'s see who is luck!\nPlayer: %d - Machine: %d\n", player_First, computer_first);
    if ( computer_first > player_First)
    {
        game_player_condition = 1;
    }
    else
    {
        game_player_condition = 0;
    }
    switch (game_player_condition)
    {
        case 1:
            printf("\nComputer is the Lucky one, lets get started!\n\n");
            for (_round = 1; _round < 7; _round++)
            {
                printf("Round: %d\n========================================",_round);
                c_Current_Score = play_computer(comp_strategy_1,comp_strategy_2,comp_strategy_3,comp_strategy_4,comp_strategy_5,comp_strategy_6);
                c_Accumulated_Score += c_Current_Score%100;
                switch (c_Current_Score/100)
                {
                    case 1:
                        comp_strategy_1 = 1;
                        printf("\nComputer selects Fives\n");
                        break;
                    case 2:
                        comp_strategy_2 = 1;
                        printf("\nComputer selects Sixes\n");
                        break;
                    case 3:
                        comp_strategy_3 = 1;
                        printf("\nComputer selects Three of a kind\n");
                        break;
                    case 4:
                        comp_strategy_4 = 1;
                        printf("\nComputer selects Large Straight\n");
                        break;
                    case 5:
                        comp_strategy_5 = 1;
                        printf("\nComputer selects Yahtzee\n");
                        break;
                    case 6:
                        comp_strategy_6 = 1;
                        printf("\nComputer selects Chance\n");
                        break;
                }
                printf("\nComputer Score is : %d and Computer total is : %d\n",c_Current_Score%100,c_Accumulated_Score);
                h_Current_Score = play_human(h_strategy_1, h_strategy_2, h_strategy_3, h_strategy_4, h_strategy_5, h_strategy_6);
                h_Accumulated_Score += h_Current_Score%100;
                switch (h_Current_Score%100)
                {
                    case 1:
                        h_strategy_1 = 1;
                        break;
                    case 2:
                        h_strategy_2 = 1;
                        break;
                    case 3:
                        h_strategy_3 = 1;
                        break;
                    case 4:
                        h_strategy_4 = 1;
                        break;
                    case 5:
                        h_strategy_5 = 1;
                        break;
                    case 6:
                        h_strategy_6 = 1;
                        break;
                }
                printf("\nYour score is %d and your total is : %d\n",h_Current_Score%100,h_Accumulated_Score);
                scoresheet(h_Accumulated_Score,c_Accumulated_Score,_round);
            }
            break;
        case 0:
            printf("Player is the lucky one, lets get started!\n\n");
            for (_round = 1; _round < 7; _round++)
            {
                printf("Round: %d\n========================================",_round);
                h_Current_Score = play_human(h_strategy_1, h_strategy_2, h_strategy_3, h_strategy_4, h_strategy_5, h_strategy_6);
                h_Accumulated_Score += h_Current_Score%100;
                switch (h_Current_Score/100)
                {
                    case 1:
                        h_strategy_1 = 1;
                        break;
                    case 2:
                        h_strategy_2 = 1;
                        break;
                    case 3:
                        h_strategy_3 = 1;
                        break;
                    case 4:
                        h_strategy_4 = 1;
                        break;
                    case 5:
                        h_strategy_5 = 1;
                        break;
                    case 6:
                        h_strategy_6 = 1;
                        break;
                }
                printf("Your score is %d and your total is %d\n",h_Current_Score%100,h_Accumulated_Score);
                c_Current_Score = play_computer(comp_strategy_1, comp_strategy_2, comp_strategy_3, comp_strategy_4, comp_strategy_5,comp_strategy_6);
                c_Current_Score += c_Current_Score%100;
                switch (c_Current_Score%100)
                {
                    case 1:
                        comp_strategy_1 = 1;
                        printf("\nComputer selects Fives\n");
                        break;
                    case 2:
                        comp_strategy_2 = 1;
                        printf("\nComputer selects Sixes\n");
                        break;
                    case 3:
                        comp_strategy_3 = 1;
                        printf("\nComputer selects Three of a kind\n");
                        break;
                    case 4:
                        comp_strategy_4 = 1;
                        printf("\nComputer selects Large Straight\n");
                        break;
                    case 5:
                        comp_strategy_5 = 1;
                        printf("\nComputer selects Yahtzee\n");
                        break;
                    case 6:
                        comp_strategy_6 = 1;
                        printf("\nComputer selects Chance\n");
                }
                printf("\nComputer score is %d and computer total is : %d\n",c_Current_Score%100,c_Accumulated_Score);
                scoresheet(h_Accumulated_Score,c_Accumulated_Score,_round);
            }
            break;
    }
    return 0;
}
int roll_a_dice()
{
    return (rand()%6) + 1;
}
int play_computer (int strtg_1, int strtg_2, int strtg_3, int strtg_4, int strtg_5, int strtg_6)
{
    //In here holds the dices which will use right after definition
    int dice_1, dice_2, dice_3, dice_4, dice_5;
    //Computes the result based on dice rolls and strategy number
    printf("\nRolled the dice for computer: ");
    dice_1 = roll_a_dice();
    dice_2 = roll_a_dice();
    dice_3 = roll_a_dice();
    dice_4 = roll_a_dice();
    dice_5 = roll_a_dice();

    printf("\nDice 1: %d, Dice 2: %d, Dice 3: %d, Dice 4: %d, Dice 5: %d", dice_1, dice_2, dice_3, dice_4, dice_5);
    return computer_strategy_decider(dice_1, dice_2, dice_3, dice_4, dice_5, strtg_1,strtg_2, strtg_3, strtg_4, strtg_5, strtg_6);
}
int computer_strategy_decider (int dice_1, int dice_2, int dice_3, int dice_4, int dice_5, int strtg_1, int strtg_2, int strtg_3, int strtg_4, int strtg_5, int strtg_6)
{
    int _Score,_Strategy,_Current_Strategy,_Max = 0;
    for (_Strategy = 6; _Strategy > 0; _Strategy--)
    {
        _Score = scoring_system(dice_1, dice_2, dice_3, dice_4, dice_5,_Strategy);
        if ((strtg_5 == 1)&&(_Strategy == 5))
            continue;
        if ((strtg_4 == 1)&&(_Strategy == 4))
            continue;
        if ((strtg_3 == 1)&&(_Strategy == 3))
            continue;
        if ((strtg_2 == 1)&&(_Strategy == 2))
            continue;
        if ((strtg_1 == 1)&&(_Strategy == 1))
            continue;
        if ((strtg_6 == 1)&&(_Strategy == 6))
            continue;
        if (_Score >= _Max)
        {
            _Max = _Score;
            _Current_Strategy = _Strategy;
        }
    }
    return _Current_Strategy*100 + _Max;
}
int play_human (int strtg_1, int strtg_2, int strtg_3, int strtg_4, int strtg_5, int strtg_6)
{
    //Dices' placeholder
    int dice_1, dice_2, dice_3, dice_4, dice_5;
    //Roller Counter initialized to  "ZERO"
    int d_roll_counter = 0;
    //Control Flow Supervision, checks and adds the strategy to play in current round
    int _Strategy, _IsPlayable = 0, _Inject_Strategy;
    //Boolean simulator if Human wishes to re-roll the dice or not
    char y_O_n;
    //Score's Place holder
    int _Score;
    //Function Computed value from the
    int _Result;

    printf("\nRolled the dice for you: ");
    //we need our control flow (loop) to execute at least 1 time !
    do
    {
        dice_1 = roll_a_dice();
        dice_2 = roll_a_dice();
        dice_3 = roll_a_dice();
        dice_4 = roll_a_dice();
        dice_5 = roll_a_dice();
        d_roll_counter++;
        printf("\nDice1: %d, Dice2: %d, Dice3: %d, Dice4: %d, Dice5: %d",dice_1,dice_2,dice_3,dice_4,dice_5);
        if(d_roll_counter<=2)
        {printf("\nDo you want to roll or not (Y/N): ");
            y_O_n=1;
            while((y_O_n!='Y')&&(y_O_n!='y')&&(y_O_n!='N')&&(y_O_n!='n'))
            {
                scanf(" %c",&y_O_n);
                if((y_O_n!='Y')&&(y_O_n!='y')&&(y_O_n!='N')&&(y_O_n!='n'))
                    printf("\nIt is an invalid operation.\nDo you want to roll or not (Y/N): ");
            }
        }
    }while(((y_O_n!='N')&&(y_O_n!='n'))&&(d_roll_counter<3));
    printf("\nPlease choose your strategy :");
    while (_IsPlayable == 0)
    {
        if (strtg_1 != 1){printf(" (1)Fives,");}
        if (strtg_2 != 1){printf(" (2)Sixes,");}
        if (strtg_3 != 1){printf(" (3)Three of a kind,");}
        if (strtg_4 != 1){printf(" (4)Large Straight,");}
        if (strtg_5 != 1){printf(" (5)Yahtzee,");}
        if (strtg_6 != 1){printf(" (6)Chance");}
        printf(" : ");
        scanf("%d", &_Strategy);
        switch (_Strategy)
        {
            case 1:
                if (strtg_1 != 1)
                {
                    _Score = scoring_system(dice_1, dice_2, dice_3, dice_4, dice_5, _Strategy);
                    _Inject_Strategy = 1;
                    _IsPlayable = 1;
                }
                break;
            case 2:
                if (strtg_2 != 1)
                {
                    _Score = scoring_system(dice_1, dice_2, dice_3, dice_4, dice_5, _Strategy);
                    _Inject_Strategy = 2;
                    _IsPlayable = 1;
                }
                break;
            case 3:
                if (strtg_3 != 1)
                {
                    _Score = scoring_system(dice_1, dice_2, dice_3, dice_4, dice_5, _Strategy);
                    _Inject_Strategy = 3;
                    _IsPlayable = 1;
                }
                break;
            case 4:
                if (strtg_4 != 1)
                {
                    _Score = scoring_system(dice_1, dice_2, dice_3, dice_4, dice_5, _Strategy);
                    _Inject_Strategy = 4;
                    _IsPlayable = 1;
                }
                break;
            case 5:
                if (strtg_5 != 1)
                {
                    _Score = scoring_system(dice_1, dice_2, dice_3, dice_4, dice_5, _Strategy);
                    _Inject_Strategy = 5;
                    _IsPlayable = 1;
                }
                break;
            case 6:
                if (strtg_6 != 1)
                {
                    _Score = scoring_system(dice_1, dice_2, dice_3, dice_4, dice_5, _Strategy);
                    _Inject_Strategy = 6;
                    _IsPlayable = 1;
                }
                break;
            default:
                printf("\nInvalid Strategy! please Choose an appropriate strategy :");
                _IsPlayable = 0;
                break;
        }
    }
    _Result = _Inject_Strategy * 100 + _Score;
    return _Result;
}
int scoring_system (int dice_1, int dice_2, int dice_3, int dice_4, int dice_5, int _Strategy)
{
    int sum = 0;
    switch (_Strategy)
    {
        case 1:
            if (dice_1 == 5){sum += 5;}
            if (dice_2 == 5){sum += 5;}
            if (dice_3 == 5){sum += 5;}
            if (dice_4 == 5){sum += 5;}
            if (dice_5 == 5){sum += 5;}
            break;
        case 2:
            if (dice_1 == 6){sum += 6;}
            if (dice_2 == 6){sum += 6;}
            if (dice_3 == 6){sum += 6;}
            if (dice_4 == 6){sum += 6;}
            if (dice_5 == 6){sum += 6;}
            break;
        case 3:
            if ((dice_1 == dice_2) && (dice_2 == dice_3)){sum = dice_1 + dice_2 + dice_3;}
            else if((dice_1 == dice_2) && (dice_2 == dice_4)){sum = dice_1 + dice_2 + dice_4;}
            else if((dice_1 == dice_2) && (dice_2 == dice_5)) {sum = dice_1 + dice_2 + dice_5;}
            else if((dice_1 == dice_3) && (dice_3 == dice_4)) {sum = dice_1 + dice_3 + dice_4;}
            else if((dice_1 == dice_3) && (dice_2 == dice_5)) {sum = dice_1 + dice_3 + dice_5;}
            else if((dice_1 == dice_4) && (dice_4 == dice_5)) {sum = dice_1 + dice_4 + dice_5;}
            else if((dice_2 == dice_3) && (dice_3 == dice_4)) {sum = dice_2 + dice_3 + dice_4;}
            else if((dice_2 == dice_3) && (dice_3 == dice_5)) {sum = dice_2 + dice_3 + dice_5;}
            else if((dice_2 == dice_4) && (dice_4 == dice_5)) {sum = dice_2 + dice_4 + dice_5;}
            else if((dice_3 == dice_4) && (dice_4 == dice_5)) {sum = dice_3 + dice_4 + dice_5;}
            break;
        case 4:
            if(((dice_1 == 1)||(dice_2 == 1)||(dice_3 == 1)||(dice_4 == 1)||(dice_5 == 1))&&((dice_1 == 2)||(dice_2 == 2)||(dice_3 == 2)||(dice_4 == 2)||(dice_5 == 2))&&((dice_1 == 3)||(dice_2 == 3)||(dice_3 == 3)||(dice_4 == 3)||(dice_5 == 3))&&((dice_1 == 4)||(dice_2 == 4)||(dice_3 == 4)||(dice_4 == 4)||(dice_5 == 4))&&((dice_1 == 5)||(dice_2 == 5)||(dice_3 == 5)||(dice_4 == 5)||(dice_5 == 5)))
            {sum = 40;}
            if(((dice_1 == 6)||(dice_2 == 6)||(dice_3 == 6)||(dice_4 == 6)||(dice_5 == 6))&&((dice_1 == 2)||(dice_2 == 2)||(dice_3 == 2)||(dice_4 == 2)||(dice_5 == 2))&&((dice_1 == 3)||(dice_2 == 3)||(dice_3 == 3)||(dice_4 == 3)||(dice_5 == 3))&&((dice_1 == 4)||(dice_2 == 4)||(dice_3 == 4)||(dice_4 == 4)||(dice_5 == 4))&&((dice_1 == 5)||(dice_2 == 5)||(dice_3 == 5)||(dice_4 == 5)||(dice_5 == 5)))
            {sum = 40;}
            break;
        case 5:
            if((dice_1 == dice_2)&&(dice_2 == dice_3)&&(dice_3 == dice_4)&&(dice_4 == dice_5)){sum = dice_1 * 5;}
            break;
        case 6:
            sum = dice_1 + dice_2 + dice_3 + dice_4 + dice_5;
            break;
    }
}
void scoresheet (int hum_Score, int comp_Score, int _Round)
{
    printf("\nRound %d Scoresheet: \n---------------------------------------",_Round);
    printf("\nComputer : %d\nPlayer : %d\n\n", comp_Score, hum_Score);
    if(_Round == 6)
    {
        printf("\nGame has finished!\n--------------------------------------\nComputer : %d\nPlayer : %d\n", comp_Score, hum_Score);
        if(comp_Score > hum_Score) printf("\nCOMPUTER WON!\n");
        else printf("\nPLAYER WON!\n");
    }
}