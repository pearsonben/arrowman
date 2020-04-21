/*  This line allows the compiler to understand the
 *    graphics functions
 */
 #include <graphics_lib.h>
 #include <math.h>

 #define PI 3.14159265


double x_velocity;
double y_velocity;

int mainMenu(void){



    BITMAP image = GFX_LoadBitmap("ArrowMan Main Screen.png"); // loading the main menu bitmap
    GFX_DrawBitmap(image, 500,250);
    GFX_DrawFilledRectangle(440, 300, 580, 350, BLACK);
    GFX_SetColour(RED);
    //printf(": start of mainMenu ");
    GFX_UpdateDisplay();

    menuButtons();

}

int drawStickman(int xstart, int ystart, int direction){ //draws the stickman at given position

    if (direction == 1){ // for the right facing stickman
        GFX_SetColour(WHITE);
        GFX_DrawFilledCircle(xstart,ystart,2.5,WHITE);
        GFX_DrawLine(xstart, ystart, xstart+15, ystart-30, 5); //draws left leg
        GFX_DrawFilledCircle(xstart+30,ystart,2.5,WHITE);
        GFX_DrawLine(xstart+30,ystart, xstart+15, ystart-30, 5); // draws right leg
        GFX_DrawLine(xstart+15, ystart-30, xstart+15,ystart-80,5); // draws body
        GFX_DrawFilledCircle(xstart+18,ystart-88, 12, WHITE); // draws head


        GFX_DrawLine(xstart+15, ystart-80, xstart-10,ystart-75, 5); // draws left arm
        GFX_DrawFilledCircle(xstart-10,ystart-75,2.5,WHITE);
        GFX_DrawLine(xstart+15,ystart-80, xstart+50,ystart-80, 5); // draws right arm
        GFX_DrawFilledCircle(xstart+50,ystart-80,2.5,WHITE);
        GFX_DrawArc(xstart,ystart-80,50, 300, 120, 2); // draws bow
        GFX_DrawLine(xstart+15,ystart-80,xstart+30,ystart-120,1); //draws top string
        GFX_DrawLine(xstart+15,ystart-80, xstart+30,ystart-40,1); // draws bottom string
        //GFX_DrawLine(xstart+50,ystart-80, xstart+65,ystart-80,2); // draws arrow
        //GFX_DrawFilledTriangle(xstart+60,ystart-83,xstart+60,ystart-77, xstart+70,ystart-80, WHITE);
        drawArrow(xstart,ystart,1);
        }
    else if (direction == -1){ // for the left facing stickman
        GFX_SetColour(WHITE);
        GFX_DrawFilledCircle(xstart,ystart,2.5,WHITE);
        GFX_DrawLine(xstart, ystart, xstart+15, ystart-30, 5); //draws left leg
        GFX_DrawFilledCircle(xstart+30,ystart,2.5,WHITE);
        GFX_DrawLine(xstart+30,ystart, xstart+15, ystart-30, 5); // draws right leg
        GFX_DrawLine(xstart+15, ystart-30, xstart+15,ystart-80,5); // draws body
        GFX_DrawFilledCircle(xstart+12,ystart-88, 12, WHITE); // draws head


        GFX_DrawLine(xstart+15, ystart-80, xstart-20,ystart-80, 5); // draws left arm
        GFX_DrawFilledCircle(xstart-20,ystart-80,2.5,WHITE);
        GFX_DrawLine(xstart+15,ystart-80, xstart+40,ystart-75, 5); // draws right arm
        GFX_DrawFilledCircle(xstart+40,ystart-75,2.5,WHITE);
        GFX_DrawArc(xstart+30,ystart-80,50, 240, -120, 2); // draws bow
        GFX_DrawLine(xstart+15,ystart-80,xstart,ystart-120,1); //draws top string
        GFX_DrawLine(xstart+15,ystart-80, xstart,ystart-40,1); // draws bottom string
        //GFX_DrawLine(xstart-20,ystart-80, xstart-35,ystart-80,2); // draws arrow
        //GFX_DrawFilledTriangle(xstart-30,ystart-83,xstart-30,ystart-77, xstart-35,ystart-80, WHITE);
        drawArrow(xstart,ystart,-1);
    }// draws arrow tip
}


int drawArrow(int xstart, int ystart, int direction){ //draws the arrow for the stickman
    if (direction == 1){
        GFX_DrawLine(xstart+50,ystart-80, xstart+65,ystart-80,2); // draws arrow
        GFX_DrawFilledTriangle(xstart+60,ystart-83,xstart+60,ystart-77, xstart+70,ystart-80, WHITE);
    }
    else if (direction == -1){
        GFX_DrawLine(xstart-20,ystart-80, xstart-35,ystart-80,2); // draws arrow
        GFX_DrawFilledTriangle(xstart-30,ystart-83,xstart-30,ystart-77, xstart-35,ystart-80, WHITE);

    }

}

double drawAngleBar( angle,xposition,yposition){ // shows the desired angle of the projectile
    char angleText[3];                              //updates the new angle as arrow keys are pressed
    GFX_InitFont();
    GFX_SetColour(RED);
    sprintf(angleText,"%ld",angle);
    GFX_DrawText(165,465,angleText);




}
int drawHealthBar1(healthp1,xposition,yposition){ //draws the health bar for player 1
    BITMAP health0 = GFX_LoadBitmap("health0.png"); // as player1's health deteriorates, the bitmap will change indicating a smaller health bar
    BITMAP health1 = GFX_LoadBitmap("health1.png");
    BITMAP health2 = GFX_LoadBitmap("health2.png");
    BITMAP health3 = GFX_LoadBitmap("health3.png");
    BITMAP health4 = GFX_LoadBitmap("health4.png");
    BITMAP health5 = GFX_LoadBitmap("health5.png");
    BITMAP health6 = GFX_LoadBitmap("health6.png");


        if (healthp1 == 200){
        GFX_DrawBitmap(health6, xposition,yposition);
        }
        else if (healthp1 < 200 && healthp1 > 167){
            GFX_DrawBitmap(health5, xposition,yposition);
        }
        else if (healthp1 <= 167 && healthp1 > 134){
            GFX_DrawBitmap(health4, xposition,yposition);
        }
        else if (healthp1 <= 134 && healthp1 > 101){
            GFX_DrawBitmap(health3, xposition,yposition);
        }
        else if (healthp1 <= 101 && healthp1 > 68){
            GFX_DrawBitmap(health2, xposition,yposition);
        }
        else if (healthp1 <= 68 && healthp1 > 35){
            GFX_DrawBitmap(health1, xposition,yposition);
        }
        else if (healthp1 <= 35 && healthp1 > 1){
            GFX_DrawBitmap(health0, xposition,yposition);
        }
        else if (healthp1 <= 0){
            GFX_DrawBitmap(health0, xposition,yposition);
        }


    GFX_UpdateDisplay();
}
int drawHealthBar2(healthp2,xposition,yposition){ //draws the health bar for player 2
    BITMAP health0 = GFX_LoadBitmap("health0.png"); //  when player2's healt deteriorates, the bitmap will change showing a smaller health bar
    BITMAP health1 = GFX_LoadBitmap("health1.png");
    BITMAP health2 = GFX_LoadBitmap("health2.png");
    BITMAP health3 = GFX_LoadBitmap("health3.png");
    BITMAP health4 = GFX_LoadBitmap("health4.png");
    BITMAP health5 = GFX_LoadBitmap("health5.png");
    BITMAP health6 = GFX_LoadBitmap("health6.png");

    if (healthp2 == 200){
        GFX_DrawBitmap(health6, xposition,yposition);
        }
        else if (healthp2 < 200 && healthp2 > 167){
            GFX_DrawBitmap(health5, xposition,yposition);
        }
        else if (healthp2 <= 167 && healthp2 > 134){
            GFX_DrawBitmap(health4, xposition,yposition);
        }
        else if (healthp2 <= 134 && healthp2 > 101){
            GFX_DrawBitmap(health3, xposition,yposition);
        }
        else if (healthp2 <= 101 && healthp2 > 68){
            GFX_DrawBitmap(health2, xposition,yposition);
        }
        else if (healthp2 <= 68 && healthp2 > 35){
            GFX_DrawBitmap(health1, xposition,yposition);
        }
        else if (healthp2 <= 35 && healthp2 > 1){
            GFX_DrawBitmap(health0, xposition,yposition);
        }
        else if (healthp2 <= 0){
            GFX_DrawBitmap(health0, xposition,yposition);
        }


    GFX_UpdateDisplay();

}
int drawPowerBar(power, xposition,yposition){ // draws the power bar at bottom left for the projectile

    BITMAP powerBar = GFX_LoadBitmap("powerBarFrame.png");
    BITMAP power1 = GFX_LoadBitmap("power1.png");
    BITMAP power2 = GFX_LoadBitmap("power2.png");
    BITMAP power3 = GFX_LoadBitmap("power3.png");
    BITMAP power4 = GFX_LoadBitmap("power4.png");
    BITMAP power5 = GFX_LoadBitmap("power5.png");

    switch(power) {
        case 0:
            GFX_DrawBitmap(powerBar,xposition,yposition);
            break;
        case 1:
            GFX_DrawBitmap(power1,xposition,yposition);
            break;
        case 2:
            GFX_DrawBitmap(power2,xposition,yposition);
            break;
        case 3:
            GFX_DrawBitmap(power3,xposition,yposition);
            break;
        case 4:
            GFX_DrawBitmap(power4,xposition,yposition);
            break;
        case 5:
            GFX_DrawBitmap(power5,xposition,yposition);
            break;
    }
    GFX_UpdateDisplay();

}

int drawObstacle(xstart,ystart){ //draws the target at  a random position
    BITMAP target = GFX_LoadBitmap("targetPNG.png");
    GFX_DrawBitmap(target, xstart, ystart);
    GFX_UpdateDisplay();

}

int endScreen(void){ // loads the end screen and initialises the mouse input
    GFX_ClearWindow();
    GFX_InitBitmap();
    BITMAP endGame = GFX_LoadBitmap("endGame.png");
    GFX_DrawBitmap(endGame,500,250);
    GFX_UpdateDisplay();
    int mouseX;
    int mouseY;
    int key;
    int eventCheck = 0;
    GFX_CreateEventQueue(); // initialising mouse functions
    GFX_InitMouse();
    GFX_RegisterMouseEvents();
    while (!eventCheck){
        GFX_WaitForEvent();
        if (GFX_IsEventMouseButton()){ // getting the mouse left click co ordinates
            GFX_GetMouseButton(&key);
            if (key == MOUSE_BUTTON_LEFT){
                GFX_GetMouseCoordinates(&mouseX,&mouseY);
                if (430 < mouseX && mouseX < 480 && 290 < mouseY && mouseY < 350){
                    playGame1P(); // if yes is clicked, start again
                    break;
                }
                else if(520 < mouseX && mouseX < 570 && 290 < mouseY && mouseY < 350){
                    mainMenu(); // if no is clicked, return to the main menu
                    selectionScreen();
                    break;
                }
            }
        }
    }


}

int selectionScreen(void){ // loads the mouse interactions on the 1p-2p game selections creen

    GFX_ClearWindow();
    BITMAP gameSelection = GFX_LoadBitmap("playGameScreen.png"); // loads the game selection screen
    GFX_DrawBitmap(gameSelection, 500,250);

    GFX_SetColour(RED);
    GFX_UpdateDisplay();
    int mouseX;
    int mouseY;
    int key;
    int eventCheck = 0;
    GFX_CreateEventQueue(); // initialising mouse functions
    GFX_InitMouse();
    GFX_RegisterMouseEvents();
    while (!eventCheck){
        GFX_WaitForEvent();
        if (GFX_IsEventMouseButton()){ // getting the mouse left click co ordinates
            GFX_GetMouseButton(&key);
            if (key == MOUSE_BUTTON_LEFT){
                GFX_GetMouseCoordinates(&mouseX,&mouseY);
                if ((240 < mouseX && mouseX < 480) && (70 < mouseY && mouseY < 400)){ //1 player button clicked

                    GFX_ClearWindow();
                    playGame1P(); // starts 1 player game
                    eventCheck = 1;
                }
                else if ((520 < mouseX && mouseX < 760) && (70 < mouseY && mouseY < 400)){ // 2 player button clicked
                    GFX_ClearWindow();
                    playGame2P();
                    eventCheck = 1; // starts 2 player game
                }
                else if ((20 < mouseX && mouseX < 130) && (450 < mouseY && mouseY < 500)){ // back button clicked
                    mainMenu();
                    eventCheck = 1; // returns to the main menu
                }
                else{
                    eventCheck = 0;
                }

            }
        }
    }

}

int fireArrow(power, angle){ //determines the x and y velocity components from the chosen power and angle of the shot

    double velocity;
    double radianAngle;
    switch(power){
        case 0:
            velocity = 20;

            break;
        case 1:
            velocity = 40;

            break;
        case 2:
            velocity = 60;

            break;
        case 3:
            velocity = 80;

            break;
        case 4:
            velocity = 100;

            break;
        case 5:
            velocity = 120;

            break;
    }
        radianAngle = angle * PI/180;
        x_velocity = velocity * cos(radianAngle);
        y_velocity = velocity * sin(radianAngle);



}




int playGame1P(void){ // 1 player game function
    BITMAP piggies = GFX_LoadBitmap("piggy.png");
    BITMAP tree = GFX_LoadBitmap("tree.png");
    BITMAP winScreen = GFX_LoadBitmap("winScreen.png");
    BITMAP birds = GFX_LoadBitmap("birb.png");
    int tries = 0;
    int level = 3;
        while (tries < 3){
            GFX_ClearWindow();
            printf("\r\n start of loop level value is: %d", level);
            int power = 0;
            int angle = 0;
            int key = 0;


            int targetHeight;
            int targetPosition;
            int pigLocation;
            int birdLocation1;
            int birdLocation2;
            if (level == 1){
                srand(time(NULL));
                targetHeight = 450;
                targetPosition = rand() % 450 + 150;
                drawObstacle(targetPosition, 420);
                drawPowerBar(power, 80,475);
            }
            else if (level == 2){
                srand(time(NULL));
                targetHeight = 450;
                targetPosition = rand() % 450 + 550;
                drawObstacle(targetPosition,420);
                drawPowerBar(power, 80,475);
                pigLocation = targetPosition - 130;
                GFX_DrawBitmap(piggies, pigLocation,415);
            }
            else if (level == 3){
                srand(time(NULL));
                targetHeight = rand() % 400 + 50;
                targetPosition = 980;
                GFX_DrawBitmap(tree, 600,250);
                drawObstacle(targetPosition, targetHeight);
                drawPowerBar(power,80,475);
                birdLocation1 = targetHeight - 80;
                birdLocation2 = targetHeight + 100;
                GFX_DrawBitmap(birds, 980,  birdLocation1);
                GFX_DrawBitmap(birds,980, birdLocation2);

            }


            GFX_InitFont();
            GFX_SetColour(RED);
            char escape[18] = "Press Esc to exit";
            char powerLabel[6] = "power:";
            char angleLabel[6] = "angle:";
            char windLabel[5] = "wind:";                        //draws all the on screen text
            char level2[30] = "Nice shot ,on to level 2!";
            char level3[30] = "Nice shot, on to level 3!";
            GFX_DrawText(10,10, escape);
            GFX_DrawText(10,465,powerLabel);
            GFX_DrawText(110,465,angleLabel);
            GFX_DrawText(500,465, windLabel);




            GFX_SetColour(GREEN);
            GFX_DrawLine(0,450,1000,450, 5); // draws the stickmen and the grass
            drawStickman(30,450,1);





            char windSpeed[2];
            srand(time(NULL));
            int wind2 = rand() % 39 + 1; // creates a random direction and speed for the wind
            srand(time(NULL));
            int windDirection = rand() % 2;
            GFX_SetColour(RED);

            if (windDirection == 0){
                GFX_DrawLine(565,473,595,473,2);
                GFX_DrawFilledTriangle(570,478,570,468,565,473,RED);
                GFX_UpdateDisplay();

            }
            if (windDirection == 1){
                GFX_DrawLine(565,473,595,473,2);
                GFX_DrawFilledTriangle(590,478,590,468,595,473,RED); //draws the windspeed indicator
                GFX_UpdateDisplay();
            }


            sprintf(windSpeed, "%ld", wind2);
            GFX_SetColour(RED);
            GFX_DrawText(540, 465, windSpeed);




            GFX_UpdateDisplay();


            GFX_CreateEventQueue();
            GFX_InitKeyboard();
            GFX_RegisterKeyboardEvents();


            while(1){

                GFX_WaitForEvent();
                fflush(stdout);
                if (GFX_IsEventKeyDown()){
                     GFX_GetKeyPress(&key);
                    if (key == ALLEGRO_KEY_RIGHT){
                        if (power != 5){ // makes sure the maximum power is 5
                            power = power + 1;
                            drawPowerBar(power, 80,475);
                            //printf("\r\n power is: %d", power);

                        }

                    }
                    else if (key == ALLEGRO_KEY_LEFT){
                        if (power != 0){ // makes sure you cant select a negative power
                            power = power - 1;
                            drawPowerBar(power, 80,475);
                            //printf("\r\n power is: %d", power);
                            //fflush(stdout);
                        }

                    }
                    else if (key == ALLEGRO_KEY_UP){
                        if (angle != 90){ // makes sure you cant choose an angle greater than 90
                            angle = angle + 5;
                            GFX_DrawFilledRectangle(164,465,200,485, BLACK);
                            drawAngleBar(angle, 165,490);
                            GFX_UpdateDisplay();
                            //printf("\r\n angle is: %d", angle);
                            //fflush(stdout);
                        }

                    }
                    else if (key == ALLEGRO_KEY_DOWN){
                        if (angle != 0){ // makes sure that you cant choose a negative angle
                            angle = angle - 5;
                            GFX_DrawFilledRectangle(164,465,200,485, BLACK);
                            drawAngleBar(angle, 165, 490);
                            GFX_UpdateDisplay();
                            //printf("\r\n angle is: %d", angle);
                            //fflush(stdout);
                            }
                    }

                    else if (key == ALLEGRO_KEY_ENTER){

                        fireArrow(power,angle); // when enter is pressed, fire the projectile

                        break;
                    }
                    else if (key == ALLEGRO_KEY_ESCAPE){
                        mainMenu(); // if escape is pressed, quit to main menu
                        menuButtons();
                    }
                }


            }


            //float x_velocity;


            if (windDirection == 0){
                x_velocity = x_velocity - wind2;

            }
            else if (windDirection == 1){
                x_velocity = x_velocity + wind2; // decides if wind is headwind or tailwind

            }


            double initial_position_y = 370;
            double initial_position_x = 100;
            GFX_MoveTo(initial_position_x, initial_position_y);


            double gravity = 9.81;
            double pos_y = initial_position_y;
            double pos_x = initial_position_x;
            double time;

            int int_x_velocity;
            int int_y_velocity;

            while ((int)pos_y < 450 && (int) pos_x < 1000){  // this loop calculates the y position for every value of x, which draws the projectile
                time = (pos_x - initial_position_x) / x_velocity;
                pos_y = initial_position_y - (y_velocity*time) + (gravity*time*time)/2;
                int_y_velocity = (int) pos_y;
                int_x_velocity = (int) pos_x;
                GFX_DrawLineTo(int_x_velocity, int_y_velocity, 3);
                pos_x += 1;
                GFX_UpdateDisplay();
                if (((targetPosition - 40) < pos_x && pos_x < (targetPosition + 40)) && ((targetHeight - 40) < pos_y && pos_y < (targetHeight + 40)) && level == 1){
                    level = level + 1;
                    tries = -1;
                    GFX_DrawText(500,250, level2);
                    GFX_UpdateDisplay(); //  if the target gets hit, advance to the next level
                    GFX_PauseFor(5000);
                    pos_y = 9000;
                }
                if ((((pigLocation - 40) < pos_x && pos_x < (pigLocation + 40)) && ((targetHeight - 40) < pos_y && pos_y < (targetHeight + 40)) && level == 2)){
                    endScreen();
                    tries = 3;
                    break; // if the pig gets hit, game over

                }
                else if ((((targetPosition - 40) < pos_x && pos_x < (targetPosition + 40)) && ((targetHeight - 40) < pos_y && pos_y < (targetHeight + 40)) && level == 2)){
                    level = level + 1;
                    tries = -1;
                    GFX_DrawText(500,250, level3); // if target gets hit, advance to level 3
                    GFX_UpdateDisplay();
                    GFX_PauseFor(5000);
                    pos_y = 9000;
                }
                else if (birdLocation1 - 20 < pos_y && pos_y < birdLocation1 + 20 && 970 < pos_x && pos_x < 1000){
                    endScreen();
                    tries = 3;
                    break; // if the birds get hit, end game

                }
                else if (birdLocation2 - 20 < pos_y && pos_y < birdLocation2 + 20 && 970 < pos_x && pos_x < 1000){
                    endScreen();
                    tries = 3;
                    break;// if the birds get hit, end game

                }
                else if (((targetPosition - 40) < pos_x && pos_x < (targetPosition + 40)) && ((targetHeight - 40) < pos_y && pos_y < (targetHeight + 40)) && level == 3){

                    GFX_DrawBitmap(winScreen,610,250); // if target gets hit, advance to wingame screen
                    GFX_UpdateDisplay();
                    int mouseX;
                    int mouseY;
                    int key;
                    int eventCheck = 0;
                    GFX_CreateEventQueue(); // initialising mouse functions
                    GFX_InitMouse();
                    GFX_RegisterMouseEvents();
                    while (!eventCheck){
                        GFX_WaitForEvent();
                        if (GFX_IsEventMouseButton()){ // getting the mouse left click co ordinates
                            GFX_GetMouseButton(&key);
                            if (key == MOUSE_BUTTON_LEFT){
                                GFX_GetMouseCoordinates(&mouseX,&mouseY);
                                if(500 < mouseX && mouseX < 600 && 240 < mouseY && mouseY < 290){
                                    playGame1P();
                                    eventCheck = 1;
                                }
                                else if( 620 < mouseX && mouseX < 680 && 240 < mouseY && mouseY < 290){
                                    mainMenu();
                                    selectionScreen();
                                    eventCheck = 1;

                                }
                                else{
                                    eventCheck = 0;
                                }
                            }
                        }
                    }

                    GFX_UpdateDisplay();
                     tries = 5;
                    break;




                }

            }
            GFX_ClearWindow();
            tries = tries + 1;


        }
        if (tries == 3){
            endScreen();
        }


    }


int playGame2P(void){ // 2 player game function
    BITMAP player1wins = GFX_LoadBitmap("player1Wins.png");
    BITMAP player2wins = GFX_LoadBitmap("player2Wins.png");
    GFX_ClearWindow();
    GFX_SetColour(GREEN);
    GFX_DrawLine(0,450,1000,450, 5);
    drawStickman(30,450,1); //draws both stickmen and all onscreen text
    drawStickman(950,450, -1);
    GFX_InitFont();

    char player1go[30] = "Player 1's turn:";
    char player2go[30] = "Player 2's turn:";

    GFX_DrawText(500,250, player1go);
    GFX_SetColour(RED);

    char escape[18] = "Press Esc to exit";
    char powerLabel[6] = "power:";
    char angleLabel[6] = "angle:";
    char windLabel[5] = "wind:";

    GFX_DrawText(10,10, escape);
    GFX_DrawText(10,465,powerLabel);
    GFX_DrawText(110,465,angleLabel);
    GFX_DrawText(500,465, windLabel);

    char windSpeed[2];
            srand(time(NULL)); // defines the windspeed and direction
            int wind2 = rand() % 39 + 1;
            srand(time(NULL));
            int windDirection = rand() % 2;
            GFX_SetColour(RED);

            if (windDirection == 0){
                GFX_DrawLine(565,473,595,473,2);
                GFX_DrawFilledTriangle(570,478,570,468,565,473,RED); //draws the windindicator
                GFX_UpdateDisplay();

            }
            if (windDirection == 1){
                GFX_DrawLine(565,473,595,473,2);
                GFX_DrawFilledTriangle(590,478,590,468,595,473,RED);
                GFX_UpdateDisplay();
            }


            sprintf(windSpeed, "%ld", wind2);
            GFX_SetColour(RED);
            GFX_DrawText(540, 465, windSpeed);
    int power = 0;
    drawPowerBar(power,80,475);

    GFX_UpdateDisplay();
    GFX_PauseFor(3000);
    GFX_DrawFilledRectangle(480,230, 650,270,BLACK);
    GFX_UpdateDisplay();
    int angle = 0;

    int healthp1 = 200;
    int healthp2 = 200;

    int whichPlayer = 1; // this value starts as 1 to represent player 1 starting, but in the loop below will be changed to 2
    int key;
    int looper;

    double initial_position_xp1 = 100;
    double initial_position_yp1 = 370;
    //GFX_MoveTo(initial_position_xp1,initial_position_yp1);
    double initial_position_xp2 = 880;
    double initial_position_yp2 = 370;

    double gravity = 9.81;
    double pos_yp1;
    double pos_xp1;
    double time;
    double pos_yp2;
    double pos_xp2;


    int int_x_velocity;
    int int_y_velocity;



    while (healthp1 != 0 || healthp2 != 0){ //while either player still has some health, continue playing
    drawHealthBar1(healthp1,30, 250);
    drawHealthBar2(healthp2, 950, 250);
        key = 0;
        power = 0;
        angle = 0;
        pos_yp1 = initial_position_yp1;
        pos_xp1 = initial_position_xp1;

        pos_yp2 = initial_position_yp2;
        pos_xp2 = initial_position_xp2;


        drawPowerBar(power,80,475);
        GFX_UpdateDisplay();
        if (healthp1 == 0){  //
            GFX_ClearWindow();
            GFX_DrawBitmap(player2wins, 500,250);
            GFX_UpdateDisplay();
            int mouseX;
            int mouseY;
            int key;
            int eventCheck = 0;
            GFX_CreateEventQueue(); // initialising mouse functions
            GFX_InitMouse();
            GFX_RegisterMouseEvents();
            while (!eventCheck){
                GFX_WaitForEvent();
                if (GFX_IsEventMouseButton()){ // getting the mouse left click co ordinates
                    GFX_GetMouseButton(&key);
                    if (key == MOUSE_BUTTON_LEFT){
                        GFX_GetMouseCoordinates(&mouseX,&mouseY);
                        if(430 < mouseX && mouseX < 480 && 290 < mouseY && mouseY < 350){
                            playGame2P();
                            eventCheck = 1; // if yes is clicked, start again
                        }
                        else if( 520 < mouseX && mouseX < 570 && 290 < mouseY && mouseY < 350){
                            mainMenu();
                            selectionScreen(); // if no is clicked, end game
                            eventCheck = 1;

                        }
                        else{
                            eventCheck = 0;
                        }
                    }
                }
            }
            break;
        }
        else if (healthp2 == 0){ // if player 2's health runs out, start endgfame screen
            GFX_ClearWindow();
            GFX_DrawBitmap(player1wins, 500,250);
            GFX_UpdateDisplay();
            int mouseX;
            int mouseY;
            int key;
            int eventCheck = 0;
            GFX_CreateEventQueue(); // initialising mouse functions
            GFX_InitMouse();
            GFX_RegisterMouseEvents();
            while (!eventCheck){
                GFX_WaitForEvent();
                if (GFX_IsEventMouseButton()){ // getting the mouse left click co ordinates
                    GFX_GetMouseButton(&key);
                    if (key == MOUSE_BUTTON_LEFT){
                        GFX_GetMouseCoordinates(&mouseX,&mouseY);
                        if(430 < mouseX && mouseX < 480 && 290 < mouseY && mouseY < 350){
                            playGame2P();
                            eventCheck = 1;
                        }
                        else if( 520 < mouseX && mouseX < 570 && 290 < mouseY && mouseY < 350){
                            mainMenu();
                            selectionScreen();
                            eventCheck = 1;

                        }
                        else{
                            eventCheck = 0;
                        }
                    }
                }
            }
            break;

        }

        if (whichPlayer == 1){ // player 1's go

            GFX_CreateEventQueue();
            GFX_InitKeyboard();
            GFX_RegisterKeyboardEvents();
            looper = 1;
            while(looper == 1){
                GFX_WaitForEvent();
                    if (GFX_IsEventKeyDown()){
                        GFX_GetKeyPress(&key);
                        if (key == ALLEGRO_KEY_RIGHT){
                            if (power != 5){ // makes sure you cant select a negative power
                            power = power + 1;
                            drawPowerBar(power, 80,475);
                        }
                        }
                        else if(key == ALLEGRO_KEY_LEFT){
                            if (power != 0){ // makes sure you cant select a negative power
                            power = power - 1;
                            drawPowerBar(power, 80,475);
                            }
                        }
                        else if(key == ALLEGRO_KEY_UP){
                            if (angle != 90){ // makes sure you cant choose an angle greater than 90
                            angle = angle + 5;
                            GFX_DrawFilledRectangle(164,465,200,485, BLACK);
                            drawAngleBar(angle, 165,490);
                            GFX_UpdateDisplay();
                            }
                        }
                        else if(key == ALLEGRO_KEY_DOWN){
                            if (angle != 0){ // makes sure that you cant choose a negative angle
                            angle = angle - 5;
                            GFX_DrawFilledRectangle(164,465,200,485, BLACK);
                            drawAngleBar(angle, 165, 490);
                            GFX_UpdateDisplay();
                        }
                        }
                        else if(key == ALLEGRO_KEY_ENTER){
                            fireArrow(power,angle);
                            GFX_MoveTo(initial_position_xp1,initial_position_yp1);
                            while ((int)pos_yp1 < 450 && (int) pos_xp1 < 1000){
                                time = (pos_xp1 - initial_position_xp1) / x_velocity;
                                pos_yp1 = initial_position_yp1 - (y_velocity*time) + (gravity*time*time)/2;
                                int_y_velocity = (int) pos_yp1;
                                int_x_velocity = (int) pos_xp1;
                                GFX_DrawLineTo(int_x_velocity, int_y_velocity, 3);
                                pos_xp1 += 1;
                                GFX_UpdateDisplay();

                                // the if statements below are the hitboxes for the stickmen, headshots dealing 95 damage,
                                //body shots doing 50, and legshots dealing 20 damage.


                                if ( 950 < pos_xp1 && pos_xp1 < 974 && 50 < pos_yp1 && pos_yp1 < 374){ // headshot
                                    healthp2 = healthp2 - 95;
                                    printf("p2 health is : %d" ,healthp2);
                                    fflush(stdout);
                                    pos_xp1 = 9000;
                                }
                                else if ( pos_xp1 == 965 && 370 < pos_yp1 && pos_yp1 < 420){ // bodyshot
                                    healthp2 = healthp2 - 50;
                                    printf("p2 health is : %d" ,healthp2);
                                    fflush(stdout);
                                    pos_xp1 = 9000;
                                }
                                else if ( 950 < pos_xp1 && pos_xp1 < 965 && 420 <= pos_yp1 < 450 ){ //legshot
                                    healthp2 = healthp2 - 20;
                                    printf("p2 health is : %d" ,healthp2);
                                    fflush(stdout);
                                    pos_xp1 = 9000;
                                }
                            }
                            if (healthp2 <= 0){ // if p2s health runs out, end game
                                GFX_ClearWindow();
                                GFX_DrawBitmap(player1wins, 500,250);
                                GFX_UpdateDisplay();
                                int mouseX;
                                int mouseY;
                                int key;
                                int eventCheck = 0;
                                GFX_CreateEventQueue(); // initialising mouse functions
                                GFX_InitMouse();
                                GFX_RegisterMouseEvents();
                                while (!eventCheck){
                                    GFX_WaitForEvent();
                                    if (GFX_IsEventMouseButton()){ // getting the mouse left click co ordinates
                                        GFX_GetMouseButton(&key);
                                        if (key == MOUSE_BUTTON_LEFT){
                                            GFX_GetMouseCoordinates(&mouseX,&mouseY);
                                            if(430 < mouseX && mouseX < 480 && 290 < mouseY && mouseY < 350){
                                                playGame2P();
                                                eventCheck = 1;
                                            }
                                            else if( 520 < mouseX && mouseX < 570 && 290< mouseY && mouseY < 350){
                                                mainMenu();
                                                selectionScreen();
                                                eventCheck = 1;

                                            }
                                            else{
                                                eventCheck = 0;
                                            }
                                        }
                                    }
                                }
                                break;
                            }
                            GFX_DrawText(500,250,player2go);
                            GFX_UpdateDisplay();
                            GFX_PauseFor(3000);
                            //GFX_ClearWindow();
                            GFX_DrawFilledRectangle(99,40,1000,449,BLACK);
                            drawStickman(950,450,-1);
                            drawHealthBar2(healthp2,950,250);
                            GFX_UpdateDisplay();
                            whichPlayer = 2;
                            looper = 0;

                        }

                    }

            }


        }


        key = 0;
        if (whichPlayer == 2){ // player 2's go
            angle = 180;
            GFX_CreateEventQueue();
            GFX_InitKeyboard();
            GFX_RegisterKeyboardEvents();
            looper = 1;
            while(looper == 1){
                GFX_WaitForEvent();
                    if (GFX_IsEventKeyDown()){
                        GFX_GetKeyPress(&key);
                        if (key == ALLEGRO_KEY_RIGHT){
                            if (power != 5){ // makes sure you cant select a negative power
                            power = power + 1;
                            drawPowerBar(power, 80,475);
                        }
                        }
                        else if(key == ALLEGRO_KEY_LEFT){
                            if (power != 0){ // makes sure you cant select a negative power
                            power = power - 1;
                            drawPowerBar(power, 80,475);
                            }
                        }
                        else if(key == ALLEGRO_KEY_UP){
                            if (angle != 90){ // makes sure you cant choose an angle greater than 90
                            angle = angle - 5;
                            GFX_DrawFilledRectangle(164,465,200,485, BLACK);
                            drawAngleBar(angle, 165,490);
                            GFX_UpdateDisplay();
                            }
                        }
                        else if(key == ALLEGRO_KEY_DOWN){
                            if (angle != 180){ // makes sure that you cant choose a negative angle
                            angle = angle + 5;
                            GFX_DrawFilledRectangle(164,465,200,485, BLACK);
                            drawAngleBar(angle, 165, 490);
                            GFX_UpdateDisplay();
                        }
                        }
                        else if(key == ALLEGRO_KEY_ENTER){
                            fireArrow(power,angle);
                            GFX_MoveTo(initial_position_xp2,initial_position_yp2);
                            while ((int)pos_yp2 < 450 && (int) pos_xp2 > 0){
                                time = (pos_xp2 - initial_position_xp2) / x_velocity;
                                pos_yp2 = initial_position_yp2 - (y_velocity*time) + (gravity*time*time)/2;
                                int_y_velocity = (int) pos_yp2;
                                int_x_velocity = (int) pos_xp2;
                                GFX_DrawLineTo(int_x_velocity, int_y_velocity, 3);
                                pos_xp2 -= 1;
                                GFX_UpdateDisplay();
                                if ( 36 < pos_xp2 && pos_xp2 < 60 && 350 < pos_yp2 && pos_yp2 < 372    ){ // headshot
                                    healthp1 = healthp1 - 95;
                                }
                                else if( pos_xp2 == 45 && 372 < pos_yp2 && pos_yp2 < 420){ // bodyshot
                                    healthp1 = healthp1 - 50;
                                }
                                else if( 15 < pos_xp2 && pos_xp2 < 30 && 420 < pos_yp2 && pos_yp2 < 450){ // legshot
                                    healthp1 = healthp1 - 20;
                                }
                            }

                            if (healthp1 <= 0){
                                GFX_ClearWindow();
                                GFX_DrawBitmap(player2wins, 500,250);
                                GFX_UpdateDisplay();
                                int mouseX;
                                int mouseY;
                                int key;
                                int eventCheck = 0;
                                GFX_CreateEventQueue(); // initialising mouse functions
                                GFX_InitMouse();
                                GFX_RegisterMouseEvents();
                                while (!eventCheck){
                                    GFX_WaitForEvent();
                                    if (GFX_IsEventMouseButton()){ // getting the mouse left click co ordinates
                                        GFX_GetMouseButton(&key);
                                        if (key == MOUSE_BUTTON_LEFT){
                                            GFX_GetMouseCoordinates(&mouseX,&mouseY);
                                            if(430 < mouseX && mouseX < 480 && 260 < mouseY && mouseY < 300){
                                                playGame1P();
                                                eventCheck = 1;
                                            }
                                            else if( 520 < mouseX && mouseX < 570 && 260 < mouseY && mouseY < 300){
                                                mainMenu();
                                                selectionScreen();
                                                eventCheck = 1;

                                            }
                                            else{
                                                eventCheck = 0;
                                            }
                                        }
                                    }
                                }
                                GFX_UpdateDisplay();
                                break;
                            }


                            GFX_DrawText(500,250, player1go);
                            GFX_UpdateDisplay();
                            GFX_PauseFor(3000);
                            GFX_DrawFilledRectangle(0,40, 910,449,BLACK);
                            drawStickman(30,450,1);
                            GFX_UpdateDisplay();

                            whichPlayer = 1;
                            looper = 0;

                        }

                    }

            }




    }

}
}
int howToPlay(void){ // draws the how to play section
    GFX_ClearWindow();
    BITMAP howTo = GFX_LoadBitmap("howToPlayScreen.png");
    GFX_DrawBitmap(howTo,500,250);
    GFX_UpdateDisplay();
    GFX_CreateEventQueue();
    GFX_InitKeyboard();
    GFX_RegisterKeyboardEvents();
    int looper = 1;
    int key = 0;
            while(looper == 1){
                GFX_WaitForEvent();
                    if (GFX_IsEventKeyDown()){
                        GFX_GetKeyPress(&key);
                        if (key == ALLEGRO_KEY_ESCAPE){
                        mainMenu();
                        looper = 0;
                        break;
                        }
                    }
            }

}




int menuButtons(void){ // this function gets the mouse inputs to tell what buttons being pressed
    int mouseX; // on the main menu
    int mouseY;
    int key;
    int eventCheck = 0;

    GFX_CreateEventQueue();
    GFX_InitMouse();
    GFX_RegisterMouseEvents(); // gets mouse co ordinates
    while (!eventCheck){
        GFX_WaitForEvent();
        if (GFX_IsEventMouseButton()){
            GFX_GetMouseButton(&key);
            if (key == MOUSE_BUTTON_LEFT){
                GFX_GetMouseCoordinates(&mouseX,&mouseY);
                if ((465 < mouseX && mouseX < 540) && (200 < mouseY && mouseY < 225)){

                    eventCheck = 1;
                    selectionScreen(); // if  "play" is clicked, go to the game selection screen


                }
                else if (440 < mouseX && mouseX < 560 && 250 < mouseY && mouseY < 290){ // when how to play is clicked

                howToPlay();
                break;
                eventCheck = 1;


                }
                else if (465 < mouseX && mouseX < 540 && 350 < mouseY && mouseY < 400){
                    GFX_CloseWindow();
                    eventCheck = 1;

                }
                else{ // if no buttons are clicked, continue looping until a button is pressed

                eventCheck = 0;
                }
            }
        }
    }
}



int main(void)      // the main game starts with the main function, which then initialises the window and calls the start menu functions.
{
    GFX_InitBitmap();
    GFX_InitWindow(1000, 600);
    mainMenu();
    menuButtons();
    return 0;
}


