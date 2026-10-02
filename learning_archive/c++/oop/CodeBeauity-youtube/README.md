<div align="center">

### C++ Object-Oriented Programming — CodeBeauty

*My own implementation while following the "C++ Object-Oriented Programming" playlist by CodeBeauty on YouTube*

</div>

---

## Source

- **Course:** [C++ OOP — CodeBeauty (YouTube playlist)](https://youtube.com/playlist?list=PL43pGnjiVwgTJg7uz8KUGdXRdGKE0W_jN&si=mYVhK93vCbtvdeLw)
- **Creator:** CodeBeauty

The explanations and ideas belong to the original creator. What's here is my own code, written while following each video.

## Topics Covered

1. Beginner s Guide to Classes, Objects, Constructors, and Methods
2. What is encapsulation in programming?
3. What is inheritance in programming?
4. What is polymorphism in programming? (coming soon)
5. C++ Operator Overloading startner to advanced


## Files

| File | Description |
|---|---|
| `oop_code_beauty.hpp` | Every topic above, implemented as its own function under `namespace oop` |
| `oop.cpp` | Entry point — an interactive menu (`namespace tui`) to pick and run any topic |

## Requirements

- C++17 or newer
- [`cornatui`](https://github.com/AnasRiemann/cornatui-lib)

## Build

```bash
g++ oop.cpp -o oop -std=c++17
```

Run the executable and pick a topic number from the menu (`exit`, `quit`, or `0` to leave).
