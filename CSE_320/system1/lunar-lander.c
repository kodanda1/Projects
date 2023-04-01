/*
* lunar-lander.c
*
* Copyright 2014 Lukas Fülling <lukas@k40s.net>
* Copyright 2014 Nicolai Süper
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
* MA 02110-1301, USA.
*
* This file has been deliberately broken to use as a tutorial for
* the Vim editor (Dr. Charles Owen)
*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ue (unsigned char)129		/* Definition for ü */

int calculate(int height, int speed, int burn, int gravity) {
  return (speed + gravity - burn);
}

int help() {
    printf("Lunar Lander version 1.1\n");
    printf("Made by Lukas F%clling and Nicolai S%cper\n\n", ue, ue);
    printf("The following arguments are possible (only one):\n");
    printf("-d [1/2/3]\tDefine difficulty. 1 is easy 3 is hard.\n");
    printf("--info\tShow different intro.");
    printf("--help\tPrint this help and exit.\n");
    return 0;
}

int windowcleaner(int step) {
    if (step >= 24) {
        printf("\nTime\t");
        printf("Speed\t\t");
        printf("Fuel\t\t");
        printf("Height\t\t");
        printf("Burn\n");
        printf("----\t");
        printf("-----\t\t");
        printf("----\t\t");
        printf("------\t\t");
        printf("----\n");
        step = 1;
    }
    else if(step<24){
      step++;
    }
    return step;
}

int randomheight() {
  time_t t;
  time(&t);
  srand((unsigned int)t);
  return (rand() % 15000 + 4000);
}

int main(int argc, char *argv[]) {
    // The rate in which the spaceship descents in free fall
    // (in ten seconds)
    const int gravity = 100;
    int height;
    int speed;
    int burn;       /* Fuel burned this step */
    int tensec;     /* The time of flight */
    int fuel;       /* Fuel left. (kilograms) */
    int prevheight; /* Height before this step */
    int step;       /* Number of steps */


    char version[] = "1.1";		/* The Version of the program */
    char dead[] = "\nThere were no survivors.\n\n";
    char crashed[] = 
        "\nThe Spaceship crashed. Good luck getting back home.\n\n";
    char success[] = "\nYou made it! Good job!\n\n";
    char emptyfuel[] = 
        "\nThere is no fuel left. You're floating around like Wheatley.\n\n";

    printf("\nLunar Lander - Version %s\n", version);
    printf("This is a computer simulation of an Apollo lunar landing capsule.\n");
    printf("The on-board computer has failed so you have to land the capsule manually.\n");
    printf("Set burn rate of retro rockets to any value between 0 (free fall) and 200\n");
    printf("(maximum burn) kilo per second. Set burn rate every 10 seconds.\n");
    printf("Good Luck!\n");

    /* Set initial height, time, fuel, burn, prevheight, 
       step and speed according to difficulty. */

    if (argc == 1) { 
      /* Default values when only one argument */
      speed = 1000;
      height = randomheight();
      fuel = 12000;
      tensec = 0;
      burn = 0;
      prevheight = height;
      step = 1;
    }
    else {
        /* If there are more arguments  */
        if (strcmp(argv[1], "-d") == 0) {
            /* Degree of difficulty */
            if (strcmp(argv[2], "1") == 0) {	/* Easy */
                speed = 1000;
                height = randomheight();
                fuel = 12000;
                tensec = 0;
                burn = 0;
                prevheight = height;
                step = 1;
            }
        
            
      
            if (strcmp(argv[2], "2") == 0) {	/* Medium */
              speed = 1000;
              height = randomheight();
              fuel = 1000;
              tensec = 0;
              burn = 0;
              prevheight = height;
              step = 1;
            }
            if (strcmp(argv[2], "3") == 0) {	/* Hard */
                speed = 2000;
                height = randomheight() - 2000;
                fuel = 900;
                tensec = 0;
                burn = 0;
                prevheight = height;
                step = 1;
            }
            else {  /* If argv[1] is not -d, default to Easy */
                speed = 1000;
                height = randomheight();
                fuel = 12000;
                tensec = 0;
                burn = 0;
                prevheight = height;
                step = 1;
            }
        }
        else if (strcmp(argv[1], "--info") == 0) {
            printf("\nLunar Lander - Version %s\n", version);
            printf("Made by Lukas F%clling and Nicolai S%cper\n\n", 
                ue, ue);
            printf("\n\nContact us at http://k40s.net\n");
        }
        else if (strcmp(argv[1], "--help") == 0) {
            help();
            return 0;
        }
        else {
            speed = 1000;
            height = randomheight();
            fuel = 12000;
            tensec = 0;
            burn = 0;
            prevheight = height;
            step = 1;
        }
    }


    printf("\nTime\t");
    printf("Speed\t\t");
    printf("Fuel\t\t");
    printf("Height\t\t");
    printf("Burn\n");
    printf("----\t");
    printf("-----\t\t");
    printf("----\t\t");
    printf("------\t\t");
    printf("----\n");

    do {

        step = windowcleaner(step);

        printf("%d0\t", tensec);
        printf("%d\t\t", speed);
        printf("%d\t\t", fuel);
        printf("%d\t\t", height);

        scanf("%i", &burn);
        if (burn<0 || burn>200) {
          /* If there is a wrong entry */
          printf("The burn rate rate must be between 0 and 200.\n");
          continue;
        }

        prevheight = height;
        speed = calculate(height, speed, burn, gravity);
        height = height - speed;
        fuel = fuel - burn;

        if (fuel <= 0) {
            break;
        }

        tensec++;

    } while (height>0);

    if (height <= 0) {
        if (speed>10) {
            printf("%s", dead);
        }
        else if (speed<10 && speed>3) {
            printf("%s", crashed);
        }
        else if (speed<3) {
            printf("%s", success);
        }
    }
    else if (height>0) {
        printf("%s", emptyfuel);
    }
    return 0;
    
}
