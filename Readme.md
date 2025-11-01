# 🧩 Tic-Tac-Toe in C

A simple **two-player console-based Tic-Tac-Toe game** written in C.  
Players take turns to mark the grid with **‘X’** or **‘O’** until one wins or the game ends in a draw.

---

## 🎮 Features

- Two-player turn-based gameplay  
- Input validation (prevents overwriting moves)  
- Detects win or draw conditions  
- Easy-to-read 3×3 board display  
- Automatically resets move count on new game start  

---

## 🧠 How the Game Works

- The board is represented by a 3×3 grid labeled from **1 to 9**:

```
 1 | 2 | 3
-----------
 4 | 5 | 6
-----------
 7 | 8 | 9
```

- **Player 1** uses `'X'`, and **Player 2** uses `'O'`.  
- Players take turns entering a number between **1–9** to place their mark.  
- The game checks after every move:
- If a player has won (three in a row, column, or diagonal)
- If all 9 cells are filled → results in a **draw**

---

## ⚙️ Compilation and Execution

### 1️⃣ Compile
Use GCC or any C compiler:

```bash
gcc tic_tac_toe.c -o tic_tac_toe
```
### 2️⃣ Run
Execute the compiled program:
```bash
./tic_tac_toe
```
---