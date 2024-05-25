// C program to build the complete snake game   
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <ncurses.h>
  
int i, j, height = 20, width = 20; 
int gameover, score; 
int x, y, fruitx, fruity, flag;
char ch; 
  
// Function to generate the fruit within the boundary 
void setup() 
{ 
    gameover = 0; 
  
    // Stores height and width 
    x = height / 2; 
    y = width / 2;

label1: 
    fruitx = rand() % 20; 
    if (fruitx == 0) 
        goto label1; 
label2: 
    fruity = rand() % 20; 
    if (fruity == 0) 
        goto label2; 
    score = 0; 
} 


// Function to draw the boundaries 
void draw() 
{ 
    wclear(stdscr); // used to render the graphics clear window
    for (i = 0; i < height; i++) { 
        for (j = 0; j < width; j++) { 
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1) { 
                printw("#"); 
            } 
            else { 
                if (i == x && j == y){
                    printw("0");
                }   
                else if (i == fruitx && j == fruity){
                        printw("*");
                } 
                else{
                    printw(" ");
                }      
            } 
        } 
        printw("\n"); 
    } 
  
    // Print the score after the game ends 
    printw("score = %d", score); 
    printw("\n"); 
    printw("press X to quit the game");
    printw("\n");
    refresh();
}


// Function to take the input 
void input() 
{ 
    // Get the keyboard input
    int ch = getch();

    // Check if a key was pressed
    if (ch != ERR) {
        
        // Get the character code of the key pressed
        int key = ch & 0xFF;

        // Check if the key pressed was a special key, such as an wasd key
        switch (ch) { 
            case 'a': 
                flag = 1; 
                break; 
            case 's': 
                flag = 2; 
                break; 
            case 'd': 
                flag = 3; 
                break; 
            case 'w': 
                flag = 4; 
                break; 
            case 'x': 
                gameover = 1; 
                break; 
        } 
  }
} 
  

// Function for the logic behind each movement 
void logic() 
{ 
    sleep((double)0.05); 
    switch (flag) { 
        case 1: 
            y--; 
            break; 
        case 2: 
            x++; 
            break; 
        case 3: 
            y++; 
            break; 
        case 4: 
            x--; 
            break; 
        default: 
            break; 
    } 
  
    // If the game is over (subtract 2 bc boarders)
    if (x < 1 || x > height - 2 || y < 1 || y > width - 2){
        gameover = 1;
        printw("Boundary hit: GAME OVER");
        printw("\n");
        refresh();
        sleep((double)1.5);
    } 
         
    // If snake reaches the fruit then update the score 
    if (x == fruitx && y == fruity) { 
        label3: 
            fruitx = rand() % 18 + 1;   // semi random int between 1, 18
            if (fruitx == 0) 
                goto label3; 
    
        // After eating the above fruit generate new fruit 
        label4: 
            fruity = rand() % 18 + 1;   
            if (fruity == 0) 
                goto label4; 
            score += 10; 
    } 
}


// Driver Code 
int main() 
{ 
    // init screen, Enable keypad mode, unbuffer input 
    initscr();
    keypad(stdscr, TRUE);   
    cbreak();
    noecho();

    // Generate boundary 
    setup(); 
  
    // Until the game is over 
    while (!gameover) { 
        draw(); 
        input(); 
        logic();
    }

    // Disable keypad mode End curses mode
    keypad(stdscr, FALSE); 
    endwin();			   
return 0;
} 