# macos-terminal-snake-game-c

I am making a simple terminal based snake game in c! just a bit of fun.
I was bored and wanted to relax and exercise my mind a little instead of
doing the usual dumb stuff.

I am running the c program on macos. 

## Useful Links

- [How to get c on a Mac](https://www.cs.auckland.ac.nz/~paul/C/Mac/):

- [How to get I/O working on Mac](http://jbwyatt.com/ncurses.html): 
    For some reason every online tutorial for c snake game uses conio.h as the library for
    consol I/O. Conio does not work on Mac OS.
    [Explanation](https://stackoverflow.com/a/67320678/22211726)

## How to Compile the Code and Play the Game
Since I am using the curses library I need to link the curses.h functions at compile time.
run this command in the directory that contains the 'snake.c' file

1. **Compile the Source Code**:
   ```bash
   gcc -lncurses snake.c -o snake_game

2. **Run the executable**:
   ```bash
   ./snake_game


#### TODO:

### 1. Implement a Hard Mode Where the Game Speeds Up as the Tail Gets Longer
**Next Steps:**
- **Introduce a Difficulty Setting:** Add a setting or menu option for selecting the hard mode.
- **Adjust Game Speed:** Modify the game loop to adjust the speed based on the snake's length. You can decrease the sleep duration or increase the game loop frequency as the tail grows.
- **Testing:** Ensure that the game remains playable and challenging at higher speeds without becoming impossible.

### 2. Fix Variable Names (r for Rows, c for Columns)
**Next Steps:**
- **Refactor Variable Names:** Go through your code and replace `i`, `j`, and `k` with more descriptive variable names like `row`, `col`, and `idx`.
- **Scope Variables Locally:** Ensure that loop variables and other temporary variables have a local scope to avoid conflicts and improve readability.
- **Consistency:** Make sure all instances of the variables are updated throughout the codebase.

### 3. Once Game Over Condition is Hit, Give User Option to Play Again
**Next Steps:**
- **Game Over Screen:** Implement a game over screen that displays the score and an option to play again or exit.
- **User Input Handling:** Capture user input to restart the game or exit. This might involve resetting the game state and reinitializing variables if the user chooses to play again.
- **Loop Management:** Modify the main game loop to handle the game over state and restart the game as needed.

### 4. Ability to Do Profile Monitoring, Performance Monitoring
**Next Steps:**
- **Profile Monitoring:** Implement code to track user statistics such as games played, average score, etc. This might involve storing data in a file or database.
- **Performance Monitoring:** Measure and log performance metrics such as frame rate, CPU usage, and memory usage. Use appropriate libraries or tools for profiling.
- **Display Metrics:** Optionally, add a feature to display performance metrics in the game UI for debugging or user information.

### 5. Add Ability to Keep a High Score
**Next Steps:**
- **High Score Storage:** Decide on a method to store the high score (e.g., in a file, database, or in-memory). Ensure that the score persists between game sessions.
- **High Score Update:** Check and update the high score whenever the game ends. If the current score is higher than the stored high score, update the stored high score.
- **Display High Score:** Show the high score on the main menu or game over screen to motivate the player to beat it.

### Summary
For each feature, focus on the following:
- **Planning:** Clearly define the feature and plan how it will integrate into your existing code.
- **Implementation:** Write the necessary code, ensuring it's modular and maintains the current codebase structure.
- **Testing:** Thoroughly test each feature to ensure it works correctly and doesn't introduce new bugs.
- **Refinement:** Optimize and refine the feature based on testing and feedback.

