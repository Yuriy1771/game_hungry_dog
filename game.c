#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    char map[10][21];
    int dogY = 5, dogX = 10;
    char key;
    int cY, cX;
    int aY = 5, aX = 9;
    int counter = 0;

    srand(time(NULL));

    do {
    system("clear");
    printf("          %d\n", counter);
    if(counter >= 3) {
        printf("    you a winner!\n");
    }
    sprintf(map[0], "####################");
    for(int k = 1; k < 9; k++) {
        sprintf(map[k], "#                  #");
    }
    sprintf(map[9], "####################");
    map[dogY][dogX] = '@';
    map[aY][aX] = '*';
    cY = dogY;
    cX = dogX;


    for(int i = 0; i < 10; i++) {
        printf("%s\n", map[i]);
    }

    key = getchar();
    if(key == 'w') dogY--;
    if(key == 's') dogY++;
    if(key == 'd') dogX++;
    if(key == 'a') dogX--;
    if(map[dogY][dogX] == '#') {
        dogY = cY;
        dogX = cX;
    }
    if(map[dogY][dogX] == map[aY][aX]) {
        counter++;
    }
    if((dogY == aY) && (dogX == aX)) {
        aY = rand() * 1.0 / RAND_MAX * 8 + 1;
        aX = rand() * 1.0 / RAND_MAX * 18 + 1;
    }

    }
    while(key != 'e');
    return 0;
}