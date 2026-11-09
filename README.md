# Vault Heist: The Living Vault

A GUI puzzle-strategy game where data structures are structural maps of a high-security vault. Players learn data structures from the inside out: reading traversals, searching a BST, deleting nodes, repairing imbalances with AVL rotations, and organizing treasures using a Max Heap and Heap Sort. 

Every step raises an alarm meter—the shape, balance, and height of your trees directly dictate whether you escape or get caught!

---

## 2. Project Architecture & Requirements
- **Language:** Standard C++ (C++17 or higher)
- **Graphics Library:** SFML (Simple and Fast Multimedia Library)
- **Core Constraint:** All major data structures (Binary Tree, BST, AVL Tree, Max Heap) are implemented **completely from scratch**. No standard library tree containers or priority queues are utilized.
- **Decoupled Architecture:** The backend model (pure data structures) is entirely independent of the GUI. It communicates via an isolated `EventLog` system that feeds discrete steps directly into the `AnimationController`.

---

## 3. Game Controls

### Mouse Interactions
- **Click Room/Node:** Select a node or answer level-specific traversal/search prompts.
- **Hover Room/Node:** Displays a tooltip showing the node's `Key`, `Height`, `Balance Factor`, `Subtree Size`, and `Depth`.
- **Drag Room Token:** Used in Act 1 blueprint reconstruction levels to position structural elements.
- **Drag Subtree to Pivot:** Executes manual AVL rotations in Act 3.
- **Mouse Wheel / Drag Canvas:** Zoom and pan across massive or deep tree layouts.

### Keyboard Shortcuts
- `Space` — Play / Pause current animation playback.
- `Left Arrow` / `Right Arrow` — Step backward / forward frame-by-frame through the Event Log.
- `Z` — Undo previous strategic action.
- `H` — Request a hint (caps maximum level star count to 2).
- `Esc` — Open the pause/in-game menu.

### Visual Color Codes
- 🟩 **Green** — Balanced node (Balance factor of -1, 0, or 1).
- 🟨 **Yellow** — Structural warning border.
- 🟥 **Red** — Balance violation or broken invariant.
- 🟦 **Blue** — Currently visited/compared node.
- ⬛ **Grey** — Subtree safely pruned/skipped during range queries.
- 🟨 **Gold** — Target heist objective treasure node.

---

## 4. Multi-Platform Build & Run Instructions

This project explicitly supports development across different operating systems and IDE variations without cross-contaminating environmental parameters.

### Option A: Linux (Ubuntu) using VS Code & SFML 2.6.x

#### Prerequisites
Install the required developer tooling and SFML binaries via `apt`:
```bash
sudo apt update
sudo apt install build-essential libsfml-dev
```

#### Compilation & Execution
To compile the application using standard compilation configurations:
```bash
g++ -std=c++17 src/*.cpp -o bin/vault_heist -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
```

To run the compiled executable binary:
```bash
./bin/vault_heist
```

---

### Option B: Windows using Visual Studio & SFML 2.5.x

#### Prerequisites
1. Download the **SFML 2.5.1 (Visual C++ 15 2017 - 32/64-bit)** binaries from the official site.
2. Extract the directory locally to a standard root location (e.g., `C:/SFML-2.5.1`).

#### IDE Property Configuration
1. Open your project files locally inside **Visual Studio**.
2. Right-click your project node in the *Solution Explorer* and select **Properties**.
3. **C/C++** $\rightarrow$ **General** $\rightarrow$ *Additional Include Directories*: Add `C:\SFML-2.5.1\include`.
4. **Linker** $\rightarrow$ **General** $\rightarrow$ *Additional Library Directories*: Add `C:\SFML-2.5.1\lib`.
5. **Linker** $\rightarrow$ **Input** $\rightarrow$ *Additional Dependencies*: Add the following library targets:
   - `sfml-graphics.lib`, `sfml-window.lib`, `sfml-system.lib`, `sfml-audio.lib` (Use `-d` suffixes for Debug targets).
6. Copy all essential `.dll` assets from `C:\SFML-2.5.1\bin\` and paste them directly into your output execution target directory containing your compiled `.exe`.
7. Click **Build Solution** (`Ctrl+Shift+B`) and press **F5** to run.

---

## 5. Team & Contribution Policy
- All core algorithmic implementations are completed entirely from scratch.
- Merges to the upstream `main` branch are verified via isolated system tests to safeguard production workflows against compiler drift.

