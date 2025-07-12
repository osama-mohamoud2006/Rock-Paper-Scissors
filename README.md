
# 🪨📄✂️ Rock Paper Scissors – C++ Game

A classic **Rock, Paper, Scissors** terminal game built with C++. This project includes:
- Colorful UI using `system("color")`
- Sound effects using Windows API (`PlaySound`)
- Simple animation for text output

---

## 🎮 Features

- 🎵 **Sound Effects**  
  - Start round: `lml-b-wl.wav`  
  - Game over: `smb2_game_over.wav` (Super Mario 2 style!)

- 🎨 **Visual Feedback**  
  - Green = User wins round  
  - Red = Computer wins  
  - Yellow = Draw  
  - Game over screen in red with animation

- 🔢 **Round Customization**  
  - User can choose how many rounds to play  
  - Option to replay after summary

---

## 🧠 Game Logic

- 1 = Stone  
- 2 = Paper  
- 3 = Scissors  
Each round, the computer randomly chooses a move. The game compares both choices and determines the winner.

---

> 🎉 At the end of all rounds, the game shows a result screen with sound and animation,and ask you if you want another round or not .

---

## 🛠️ Requirements

- **Platform**: Windows only  
- **Compiler**: Any C++ compiler supporting C++11 or later  
- **Libraries**:  
  - `windows.h`  
  - `mmsystem.h` (linked via `winmm.lib`)

---

## 📂 Project Structure

```

📦 rock-paper-scissors
┣ 📄 project.cpp                # Main source code
┣ 📄 lml-b-wl.wav               # Start round sound
┣ 📄 smb2\_game\_over.wav         # Game over sound
┣ 📄 PROJECT 1.exe              # Compiled binary
┗ 📄 README.md                  # This file

```

---

## 🧾 How to Run

1. Open the `.cpp` file in your C++ IDE (e.g., Visual Studio)
2. Make sure both sound files are in the same directory
3. Compile and run
4. Follow on-screen instructions to play

---

## 🔊 Notes

- If sound doesn't play, make sure:
  - WAV files are in the **same folder** as the `.exe`
  - WAV files are properly encoded (PCM, mono/stereo, ≤ 705kbps)
  - You're running the game on **Windows** (sound only works on Windows via `PlaySound`)

---

## 📜 License

This project is licensed under the [MIT License](LICENSE).








