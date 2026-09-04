<div align="center">

### C++ Pointers — CodeBeauty

*My own implementation while following the "C++ Pointers" playlist by CodeBeauty on YouTube*

</div>

---

## Source

- **Course:** [C++ Pointers — CodeBeauty (YouTube playlist)](https://youtube.com/playlist?list=PL43pGnjiVwgSSRlwfahAuIqoJ8TfDIlHq&si=UVM-2fRo8MXoNrZ7)
- **Creator:** CodeBeauty

The explanations and ideas belong to the original creator. What's here is my own code, written while following each video.

## Topics Covered

1. Introduction to pointers
2. Void pointers
3. Pointers and arrays
4. Returning multiple values from a function using pointers
5. Dynamic arrays — creating/changing an array size at runtime
6. Dynamic two-dimensional arrays
7. Smart pointers
8. Function pointers

## Files

| File | Description |
|---|---|
| `pointers.hpp` | Every topic above, implemented as its own function under `namespace ptr` |
| `pointers_code_beauity.cpp` | Entry point — an interactive menu (`namespace ui`) to pick and run any topic |

## Requirements

- C++17 or newer
- [`cornatui`](https://github.com/AnasRiemann/cornatui-lib) — the menu here is built on top of it; copy the `cornatui` folder alongside these two files before building

## Build

```bash
g++ pointers_code_beauity.cpp -o pointers -std=c++17
```

Run the executable and pick a topic number from the menu (`exit`, `quit`, or `0` to leave).
