# cpp-menu

Interactive console menu demo with nested navigation, breadcrumbs, and predictable shortcuts.

## Features (user-facing)
- Four-level study menu with Arithmetic and Algebra branches.
- Clear screen between views and a breadcrumb showing your path.
- Option `0` is always reserved for `Back` (or `Exit` at the root).
- Leaf screens pause after showing content so output is not immediately cleared.
- ANSI coloring for readability (set `NO_COLOR=1` to disable).

## Running (users)
1) Build the executable (see engineer section) or use the provided `menu.exe`.
2) Run:  
   ```powershell
   .\menu.exe
   ```
3) Navigate with number keys. `0` always goes back; at the root `0` exits.

## For engineers

### Prerequisites
- Windows with Visual Studio 2026 (or compatible) C++ toolchain.
- `vcvars64.bat` available (Community installs to `C:\Program Files\Microsoft Visual Studio\18\Community\...`).

### Build command (PowerShell)
```powershell
cmd /c "`"C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat`" && cl /EHsc /std:c++17 main.cpp menu_functions.cpp menu_definition.cpp /Fe:menu.exe"
```

### Project layout
- `main.cpp` — entry point.
- `menu.hpp` — menu data structures.
- `menu_functions.hpp/.cpp` — rendering, navigation handlers, and UX helpers.
- `menu_definition.cpp` — declarative menu structure (titles, hierarchy, handlers).

### Notes
- Leaf handlers currently print the title and wait for Enter; extend these to add real lesson content.
- Follow the ordering contract (index `0` is Back/Exit) when adding new menu nodes.
