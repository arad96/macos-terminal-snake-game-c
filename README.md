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
      
