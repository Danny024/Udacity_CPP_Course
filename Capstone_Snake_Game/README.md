# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

## Project Overview
The Snake Game is a classic video game in which a player controls a snake that moves around a grid, eating food to grow in length while avoiding collisions with the walls and its own tail. The game is implemented in C++ using the Simple DirectMedia Layer (SDL) library for graphics and user input handling.

## Rubric Point
## 1 Loops
Loops are used extensively in the code to create the game's main loop. The main loop continuously checks for user input, updates the game state, and renders the game on the screen. This ensures that the game remains interactive and responsive. Functions and classes are clearly defined in the project code structure. To prevent repeating oneself, all reusable codes are implemented as functions.
During the game, the project allows user inputs that are utilised to manipulate the snake and other game elements like pausing and triggering the wall.

### 2. Functions
Functions are used to encapsulate and modularize different aspects of the game logic. For example, there are functions for handling user input, updating the game state, and rendering the game on the screen. This modular approach improves code readability and maintainability.

### 3. I/O (Input/Output)
Input and output are essential for the game. User input is captured to control the snake's movement and pause/resume the game. Output is displayed on the screen to render the game graphics and provide feedback to the player.

### 4. Object-Oriented Programming (OOP)
The code follows the principles of Object-Oriented Programming (OOP) by defining classes and objects to represent game entities. The Snake, Game, Renderer, and Controller classes are used to encapsulate related data and behavior. The project code is arranged into classes, each of which has a class function to carry out a task and a class attribute to keep data.Every member of the class data has their public, protected, or private status clearly stated. The project makes use of friend functions.

### 5. Memory Management
Memory management is crucial for efficient resource usage. The code effectively manages memory by creating and destroying SDL objects such as windows and renderers. Additionally, memory is allocated dynamically when needed, such as when the snake grows in size. The project makes use of references in function declarations. Both references and pointers used all around the project.

### 6.Concurrency
Concurrency is used to implement features like the poison effect. When the snake consumes a special food item, a separate thread (TimerThread) is launched to handle the poison effect. This thread sleeps for a specified duration and then sets a flag to indicate the end of the poison effect. Everytime a snake gets poisoned, the project starts a new thread. After five seconds of waiting, this thread modifies the game's private pointer variable to restore the snake to its non-poisonous condition.


### Concurrency
The project creates a thread each time snake is poisoned. This thread waits for 12 seconds and return back the snake's poisonous state to normal by modifying the game's private pointer variable. 

Update: I have added a mutex poison_mutex in game.cpp I made use of 'lock_guard' to ensure that the _poisoned variable is accessed and modified safely thereby preventing data races.

## Getting Started
To play the Snake Game, follow these steps:

Build the project using a C++ compiler that supports SDL.
Run the compiled executable.
Use the arrow keys to control the snake's movement (Up, Down, Left, Right).
Press the "ESC" key to pause/resume the game.
Eat food items to increase your score and try to avoid collisions.
Enjoy playing the Snake Game!

## Added features

One can add a wall to the game by pressing the w button. The w button can enable or disable the wall. If the wall is enabled the snake would die if it hits the wall.

A pause function is added to the game by pressing the ESC key button.


Peradventure the snake dies a small dialog box appears and shows score and size information of the snake. 


Poisonous Food Feature Added. The possibility of a food been poisoned food is 1 out of 10 which is actually 10 %. A poisonous food is unidentifiable by looks. If the snake eats a poisonous food it would turn colour RED and it  would misbehave for a period of 12 seconds (ie the effect of the poison waers off after 12 seconds). During this period the snake would be going the opposite direction. For instance if LEFT key is pressed the snake would go RIGHT direction.








