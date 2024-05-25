// C program to build the complete snake game   
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
  
int i, j, height = 10, width = 10; 
int gameover, score; 
int x, y;                       // current position
int tailX[100], tailY[100];     // memory for all tail segments 
int fruitx, fruity;             // fruit position
int nTail = 1;                    
int flag;                       // direction flag
char ch; 
  
// Function to generate the fruit within the boundary 
void setup() { 
    gameover = 0; 
    x = height / 2; 
    y = width / 2;

    srand(time(0));  // Seed the random number generator
    fruitx = rand() % (height - 1) + 1;  // generate fruit x,y so always inside boarders 
    fruity = rand() % (width - 1) + 1; 

    score = 0; 
} 


// Function to draw the boundaries 
void draw() { 
    
    wclear(stdscr); // used to render the graphics clear window
    for (i = 0; i <= height; i++) { 
        for (j = 0; j <= width; j++) { 
            if (i == 0 || i == height || j == 0 || j == width) { 
                printw("#");
            } 
            else if (i == x && j == y){
                    printw("0");
                }   
            else if (i == fruitx && j == fruity){
                        printw("*");
                } 
            else {
                // Fix drawing bug
                int print = 0;
                for(int k = 0; k < nTail; k++){
                    if(tailX[k] == i && tailY[k] == j){
                        printw("o");
                        print = 1;
                    }        
                }
                if (! print){
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
    usleep(450000);     // Sleep for 300000 microseconds (100 milliseconds) 
}


// Function to take the input 
void input() { 
    
    // Get the keyboard input
    int ch = getch();

    // case 97: Handles the 'a' key press.
    // case 115: Handles the 's' key press.
    // case 100: Handles the 'd' key press.
    // case 119: Handles the 'w' key press.
    // case 120: Handles the 'x' key press.
    
    // ch = 119;
    
    // Check if a key was pressed
    if (ch != ERR) {
        
        // Get the character code of the key pressed
        int key = ch & 0xFF;

        // Check if the key pressed was a special key, such as an wasd key
        switch (key) { 
            case 'a': // left
                flag = 1; 
                break; 
            case 's': // down
                flag = 2; 
                break; 
            case 'd': // right
                flag = 3; 
                break; 
            case 'w': // up
                flag = 4; 
                break; 
            case 'x': 
                gameover = 1; 
                break; 
        } 
    }
} 
  

// Function for the logic behind each movement 
void logic() {
    
    int prevX = tailX[0];          
    int prevY = tailY[0];
    int prev2X, prev2Y;

    switch (flag) {
        // x goes up and down
        // y goes left and right 
        // ik its backwards im dyslexic   
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
           
    tailX[0] = x;
    tailY[0] = y;

    for (int ix = 1; ix <= nTail; ix++) {
        prev2X = tailX[ix];
        prev2Y = tailY[ix];
        tailX[ix] = prevX;
        tailY[ix] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
  
    // TODO: Logic for self colision
    // If the game is over (subtract 1 bc boarders)
    if (x < 1 || x > height - 1 || y < 1 || y > width - 1){
        gameover = 1;
        printw("Boundary hit: GAME OVER");
        printw("\n");
        refresh();
        sleep(1);
    } 
         
    // If snake reaches the fruit then update the score 
    if (x == fruitx && y == fruity) {  
        
        // After eating the above fruit generate new fruit
        fruitx = rand() % (width - 2) + 1;   // semi random int between 1, width -2
        fruity = rand() % (height - 2) + 1;   
        nTail++;
        score += 10; 
    } 
}


// Driver Code 
int main() 
{ 
    // init screen, Enable keypad mode, unbuffer input   
    initscr();              // Start curses mode
    cbreak();               // Line buffering disabled
    noecho();               // Don't echo() while we do getch
    nodelay(stdscr, TRUE);  // Non-blocking input
    keypad(stdscr, TRUE); 

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