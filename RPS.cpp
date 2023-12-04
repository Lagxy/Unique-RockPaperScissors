/*
    1 = Rock
    2 = Paper
    3 = Scissors
*/
#include<stdio.h>
#include<stdlib.h>

class Player{
    private:

    public:
    char name[50];//can be improved
    int health = 100;
    int RPS;

    // Player(const char names[], int health) : health(health){
    //     name = names;
    // }

    void action(int RPS, Player &opponent){
        switch (RPS){
        case 1:
            opponent.health -= 50;
            printf("%s take 50 damage!\n\n", opponent.name);
            break;
        case 2:
            health += 50;
            if(health > 100) health = 100;
            printf("%s is healed by 50!\n\n", name);
            break;
        case 3:
            opponent.health -= 25;
            printf("%s take 25 damage!\n\n", opponent.name);
            break;
        default:
            system("cls");
            puts("Invalid input!\nPlease restart the program\n");
            exit(0);
        }
    }
};

int checkWinner(int p1, int p2){
    if(p1 == 1){
        switch(p2){
            case 1: return -1;
            case 2: return 1;
            case 3: return 0;
            default: return 404;
        }
    }
    if(p1 == 2){
        switch(p2){
            case 1: return 0;
            case 2: return -1;
            case 3: return 1;
            default: return 404;
        }
    }
    if(p1 == 3){
        switch(p2){
            case 1: return 1;
            case 2: return 0;
            case 3: return -1;
            default: return 404;
        }
    }
    return -1;
}

int main(){
    int round=1;
    Player player[2];

    printf("Enter player 1 name: "); scanf("%[^\n]", &player[0].name);getchar();
    printf("Enter player 2 name: "); scanf("%[^\n]", &player[1].name);getchar();
    system("cls");

    while(player[0].health > 0 && player[1].health > 0){
        for(int i=0;i<2;i++){
            printf("ROUND %d\n", round);
            printf("%s VS %s\n\n", player[0].name, player[1].name);
            printf("Tutorial:\n1 = Rock\n2 = Paper\n3 = Scissors\n\n");

            printf("%s health: %d\n%s health: %d\n\n", player[0].name, player[0].health, player[1].name, player[1].health);

            printf("%s`s turn: ", player[i].name); scanf("%d", &player[i].RPS); system("cls");
        }

        int winner = checkWinner(player[0].RPS, player[1].RPS);

        if(winner == 0) player[0].action(player[0].RPS, player[1]);
        else if (winner == 1) player[1].action(player[1].RPS, player[0]);
        else if (winner == -1) puts("Draw!");
        else {
            puts("Invalid Input!\nPlease restart the program");
            return 0;
        }

        round++;
    }

    if(player[0].health <= 0){
        system("cls");
        printf("aowkwkwkw %s kalah", player[0].name);
    } else {
        system("cls");
        printf("aowkwkwkw %s kalah", player[1].name);
    }

    return 0;
}