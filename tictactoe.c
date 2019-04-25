#include<stdio.h>

#include<stdlib.h>

int r = 0, p1 = 0, p2 = 0;
void print(char a[5][5]);
void input(char a[5][5], char s);
void check(char a[5][5]);
void result(char w);
void main() {
    int i, j, k, n1, n2;
    char a[5][5] = {
        ' ',
        '|'
    };
    char w = '\0';

    for (i = 0; i <= 5; i++) //saving pattern in the array
    {

        for (j = 0; j < 6; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0)
                    a[i][j] = a[0][0];
                else
                    a[i][j] = a[0][1];
            } else {
                if (j % 2 == 0) {
                    a[i][j] = '-';
                } else {
                    a[i][j] = '+';
                }
            }
        }
    }

    if (r % 2 == 0)
        printf("Player 1 is X\nPlayer 2 is O");
    else
        printf("Player 1 is O\nPlayer 2 is X");

    print(a); //print array

    for (k = 1; k <= 4; k++) {
        printf("X's turn\n");

        input(a, 'X');

        print(a);

        if (k > 2) {
            check(a);
        }
        printf("O's turn\n");

        input(a, 'O');

        print(a);
        if (k > 2) {
            check(a);

        }

    }

    printf("X's turn\n");

    input(a, 'X');

    print(a);

    check(a);
}

void print(char a[5][5]) {
    int i, j;
    printf("\n\n\n");
    for (i = 0; i < 5; i++) //print pattern loop
    {
        printf("   ");
        for (j = 0; j < 5; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}

void input(char a[5][5], char s) {
    int n1, n2;
    do {
        printf("Enter the row\n");
        scanf("%d", & n1);
        while ((getchar()) != '\n');
        switch (n1) {
        case 1:
            n1 = 0;
            break;
        case 2:
            n1 = 2;
            break;
        case 3:
            n1 = 4;
            break;
        default:
            {
                printf("Invalid row choose between 1,2 and 3\n");
                n1 = 5;
            }
        }
    } while (n1 == 5);

    do {
        printf("Enter the column\n");
        scanf("%d", & n2);
        while ((getchar()) != '\n');
        switch (n2) {
        case 1:
            n2 = 0;
            break;
        case 2:
            n2 = 2;
            break;
        case 3:
            n2 = 4;
            break;
        default:
            {
                printf("Invalid column choose between 1,2 and 3\n");
                n2 = 5;
            }

        }
    } while (n2 == 5);

    if (a[n1][n2] == ' ') {
        if (s == 'X')
            a[n1][n2] = 'X';
        else
            a[n1][n2] = 'O';
    } else {
        printf("Invalid row or column\n");
        input(a, s);
    }
    system("cls");
}

void check(char a[5][5]) {
    char w;
    int c;

    //check diagonals
    if (a[2][2] != ' ') {
        if (a[0][0] == a[2][2] && a[2][2] == a[4][4]) {
            w = a[0][0];
            result(w);
        }
        if (a[0][4] == a[2][2] && a[2][2] == a[4][0]) {
            w = a[2][2];
            result(w);
        }

    }

    // check rows
    for (c = 0; c < 5; c = c + 2) {
        if (a[c][0] == a[c][2] && a[c][0] == a[c][4]) {
            if (a[c][0] != ' ') {
                w = a[c][0];
                result(w);
            }
        }
    }

    // check columns
    for (c = 0; c < 5; c = c + 2) {
        if (a[0][c] == a[2][c] && a[0][c] == a[4][c]) {
            if (a[0][c] != ' ') {
                w = a[0][c];
                result(w);
            }
        }
    }
}

void result(char w) {
    int ch;
    if (w == 'X') {
        printf("X wins\n");
        if (r % 2 == 0) {
            printf("Player 1 wins\n");
            p1++;
        } else {
            printf("Player 2 wins\n");
            p2++;
        }
    } else {
        if (w == 'O') {
            printf("O wins\n");
            if (r % 2 == 0) {
                printf("Player 2 wins\n");
                p2++;
            } else {
                printf("Player 1 wins\n");
                p1++;
            }
        } else
            printf("Draw\n");
    }
    r++;

    printf("\n\nScore\nPlayer 1 : %d\nplayer 2 : %d\n\n\n", p1, p2);
    printf("Do you want to continue? \nEnter 1 to continue\n");
    scanf("%d", & ch);
    if (ch == 1) {
        system("cls");
        main();
    } else
        exit(0);

}
