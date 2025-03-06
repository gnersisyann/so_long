# 🎮 so_long – A 2D Game with MiniLibX

so_long is a simple 2D game built using MiniLibX. The player explores a map, collects collectibles, and reaches the exit while avoiding obstacles or enemies.
# 🚀 Features

    Uses MiniLibX for graphics rendering.
    Supports .ber map files with walls, collectibles, and an exit.
    Basic movement mechanics (WASD / Arrow keys).

# 🛠 Installation & Compilation
```
make // or make bonus
```
This generates the so_long executable.

Run the game with a valid map file:
```
./so_long maps/example.ber // or ./so_long_bonus
```
# 🎮 Controls

    W / ↑ – Move up
    A / ← – Move left
    S / ↓ – Move down
    D / → – Move right
    ESC – Quit the game

# 📷 Screenshots  

![Game Screenshot 1](https://i.imgur.com/xkGFDIR.png)  
*(mandatory)*

![Game Screenshot 2](https://i.imgur.com/UJHDr8r.png)  
*(bonus)*

# 📜 Example Map (.ber format)
```
111111
10C0E1
10P001
111111
```
    1 – Walls
    0 – Walkable space
    P – Player start position
    C – Collectibles
    E – Exit
    M - Enemy (bonus)

# 🏆 Learning Outcomes

✅ Understanding MiniLibX for 2D rendering

✅ Handling keyboard inputs and event loops

✅ Working with 2D maps and file parsing
