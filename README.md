# Let's Learn Typing

Welcome to the Let's Learn Typing project! This project is built to help users improve their typing skills through a fun and interactive typing test game.

## Project Overview

This project focuses on creating a typing test game using the `ncurses` library and `C programming language`. The game provides a platform for users to practice and enhance their typing speed and accuracy.

## Game Requirements

The Let's Learn Typing game includes the following features and requirements:

### Game Mechanics`

- Generates a typing passage using words from a provided word pool file.
- Difficulty levels:
    - **Easy**: Shorter passages with common, simple words.
    - **Medium**: Longer passages with moderately difficult words.
    - **Hard**: Long, complex passages with challenging words.
- Displays the typed passage at the top of the screen and the user's typed characters below.
- Highlights correct characters in green and incorrect characters in red.
- Times the user's typing session with a set time limit (e.g., 60 seconds).
- Displays statistics after the time expires, including WPM (Words per Minute), accuracy, and other performance data.
- Also give Real-time feedback on typing speed and accuracy
- User-friendly interface

### Word Pool File

- The word pool is provided in a text file, with each line containing a word.
- The game reads words from this file and generates the typing passage based on the difficulty level:
    - **Easy**: 30 random words.
    - **Medium**: 60 random words.
    - **Hard**: 90 random words.

### Key Features

- **Word Selection**: Randomly selects a passage for the user to type based on difficulty.
- **Progress Highlighting**: Highlights correct characters in green and incorrect characters in red.
- **Typing Statistics**:
    - **Words per Minute (WPM)**: Number of correct words typed per minute.
    - **Accuracy**: Percentage of correctly typed characters.
    - **Total Keystrokes**: Total number of characters typed, including correct and incorrect characters.
    - **Mistakes**: Count of incorrect characters typed.
    - **Characters per Second (CPS)**: Number of characters typed per second.

### Defining Word Complexity

- **Easy Words**:
    - Length: 5 to 7 letters
    - Syllables: Typically 2 to 3 syllables
    - Examples: Cat, dog
- **Medium Words**:
    - Length: 1 to 4 letters
    - Syllables: Typically 1 or 2 syllables
    - Examples: Table, Flower
- **Hard Words**:
    - Length: 8+ letters
    - Syllables: 3 or more syllables
    - Examples: Rhinoceros, perseverance

Enjoy improving your typing skills with Let's Learn Typing!

## Prerequisites

Before running the project, ensure that you have the following installed:

- `ncurses` library

## Installation

To run the project, follow these steps:

1. **Clone the repository:**
    ```sh
    git clone https://github.com/UniqueSwagger/Lets_learn_typing.git
    ```

2. **Navigate to the source directory:**
    ```sh
    cd Lets_Learn_Typing/src
    ```

3. **Compile the project:**
    ```sh
    gcc -o game main.c data.c functions.c typing_test.c -lncurses
    ```

4. **Run the game:**
    ```sh
    ./game < word_pool.txt
    ```

Enjoy improving your typing skills with Let's Learn Typing!

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue if you have any suggestions or improvements.

## Contact

For any questions or inquiries, please contact [bsse1637@iit.du.ac.bd.com](mailto:bsse1637@iit.du.ac.bd.com).

Happy Typing!