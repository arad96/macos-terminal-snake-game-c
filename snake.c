// C program to build the complete snake game   
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <ncurses.h>
  
int i, j, height = 20, width = 20; 
int gameover, score; 
int x, y;                       // current position
int tailX[100], tailY[100];     // memory for all tail segments 
int fruitx, fruity;             // fruit position
int nTail = 0;                    
int flag;                       // direction flag
char ch; 
  
// Function to generate the fruit within the boundary 
void setup() 
{ 
    gameover = 0; 
  
    // Stores height and width 
    x = height / 2; 
    y = width / 2;

// TODO: Get Rid of goto's 
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
void draw() { 
    
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
                    // Fix drawing bug
                    for(int k = 0; k < nTail; k++){
                        if(tailX[k] == j && tailY[k] == i)
                            printw("o");
                    }
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
    usleep(300000);     // Sleep for 300000 microseconds (100 milliseconds) 
    refresh();
}


// Function to take the input 
void input() { 
    
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
void logic() {
    int prevX = tailX[0];          
    int prevY = tailY[0];
    int prev2X, prev2Y;           
    tailX[0] = x;
    tailY[0] = y;

    for (int ix = 1; ix < nTail; ix++) {
        prev2X = tailX[ix];
        prev2Y = tailY[ix];
        tailX[ix] = prevX;
        tailY[ix] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    
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
  
    // TODO: Logic for self colision
    // If the game is over (subtract 2 bc boarders)
    if (x < 1 || x > height - 2 || y < 1 || y > width - 2){
        gameover = 1;
        printw("Boundary hit: GAME OVER");
        printw("\n");
        refresh();
        sleep(1);
    } 
         
    // If snake reaches the fruit then update the score 
    if (x == fruitx && y == fruity) {  
        
        // After eating the above fruit generate new fruit
        fruitx = rand() % 18 + 1;   // semi random int between 1, 18
        fruity = rand() % 18 + 1;   
        nTail++;
        score += 10; 
    } 
}


// Driver Code 
int main() 
{ 
    // init screen, Enable keypad mode, unbuffer input   
    initscr();          // Start curses mode
    cbreak();           // Line buffering disabled
    noecho();           // Don't echo() while we do getch
    nodelay(stdscr, TRUE); // Non-blocking input
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