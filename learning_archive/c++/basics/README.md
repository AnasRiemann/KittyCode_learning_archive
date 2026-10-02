<div align="center">

### C++ Basics & Beyond

*My own from-scratch reference covering the fundamentals of C++ — written by me, not tied to a specific course*

</div>

---

## About This Folder

Unlike the other course folders in this repo, this one isn't a walkthrough of someone else's playlist — it's a fundamentals reference I put together myself, covering the basics of C++ from data types all the way to functions, plus a couple of "just beyond the basics" topics (generic functions, lambdas) as a bonus round.

## Topics Covered

**Basics** — `basics.hpp`

1. Data types
2. Input & Output
3. Operators & math functions
4. Conditional statements (`if` / `switch`)
5. Loops & arrays
6. Functions — default parameters, `return`, overloading, recursion vs. iteration

**Advanced Topics** — `advanced.hpp` (option `7` in the menu)

7. Generic (template) functions
8. Lambda functions
9. Basics of linux commands (coming soon)

## Files

| File | Description |
|---|---|
| `basics.hpp` | Topics 1–6, each implemented as its own function under `namespace basics` |
| `advanced.hpp` | Topics 7–8 (the bonus round), under `namespace adv` |


## Requirements

- C++17 or newer
- [`cornatui`](https://github.com/AnasRiemann/cornatui-lib) — the menu here is built on top of it; copy the `cornatui` folder alongside these files before building

## Build

```bash
g++ basics_program.cpp -o basics -std=c++17
```

Run the executable and pick a topic number from the menu (`exit`, `quit`, or `0` to leave).
