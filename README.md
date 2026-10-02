<div align="center">

# KittyCode Learning Archive

**A growing archive of hands-on implementations from programming courses & YouTube tutorials**
*Multiple Languages · Course-by-Course · Self-Study · Open for Anyone to Follow Along*

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](./LICENSE)
[![Languages](https://img.shields.io/badge/languages-multiple-blueviolet)]()
[![Status](https://img.shields.io/badge/status-ongoing-brightgreen)]()

</div>

<br>

<p align="center">
  <sub>Most folders here follow a public course or YouTube playlist step by step; a few are self-written references I put together on my own.<br>Either way, the code is mine, written while learning, kept as a reference for anyone following along.</sub>
</p>

---

## Contents

- [Why This Repo Exists](#why-this-repo-exists)
- [Overview](#overview)
- [How This Repo Is Organized](#how-this-repo-is-organized)
- [Getting Started](#getting-started)
- [Courses](#courses)
- [License](#license)
- [Feedback & Corrections](#feedback--corrections)
- [Author](#author)

---

## Why This Repo Exists

Watching a course is easy. Actually implementing every lesson yourself is where the learning happens — so instead of letting that code disappear in some local folder after each video, it lives here, organized and kept around.

That serves two purposes at once: a personal record of what's been studied, and a reference for anyone else working through the same course who wants to see how someone else approached the same lesson.

## Overview

This repo collects my own implementations while working through public programming courses and YouTube playlists, plus a few self-written reference folders I put together on my own — across whatever language or topic I happen to be learning (or reviewing) at the time.

Most of the teaching content here isn't mine — every folder that follows an external course credits its source (the creator, and a link to the playlist or video) right in that folder's own `README.md`. A few folders are written entirely by me from scratch and say so instead. Either way, the code itself is always my own: my own attempt at each lesson, or my own write-up of a topic.

---

## How This Repo Is Organized

Courses are grouped by language first, then by topic:

```
KittyCode_learning_archive/
├── learning_archive/
│   └── c++/
│       ├── basics/
│       │   ├── README.md
│       │   ├── basics.hpp
│       │   ├── advanced.hpp
│       │   └── basics_program.cpp
│       └── pointers/
│           ├── README.md
│           ├── pointers.hpp
│           └── pointers_code_beauity.cpp
├── LICENSE
└── README.md              # you are here
```

- **Language folder** — lowercase, matching the language name (`c++`, `python`, ...)
- **Topic folder** — the course/subject itself (`pointers`); add a source suffix only if more than one course ever covers the same topic (e.g. `pointers-codebeauty`)
- Every topic folder is self-contained, with its own `README.md` covering:
  - The original course/playlist link and creator — or a note that the folder is self-written, for topics not tied to one course
  - Topics covered
  - Build/run instructions for that language

**Adding a new course:** create `learning_archive/<language>/<topic>/`, drop in the code, add a short `README.md` (crediting the source, or noting it's self-written), and add one row to the [Courses](#courses) table below.

---

## Getting Started

1. Pick a course from the [table below](#courses)
2. Open its folder — its own `README.md` has the original source link (or a note that it's self-written) and any build/run steps
3. Since each folder is self-contained, you only need the tools for that specific language, not the whole repo

---

## Courses

| Course | Language | Source | Folder |
|---|---|---|---|
| C++ Basics & Beyond | C++ | Self-written (no single course) | [`learning_archive/c++/basics/`](./learning_archive/c++/basics) |
| Pointers | C++ | CodeBeauty (YouTube) | [`learning_archive/c++/pointers/`](./learning_archive/c++/pointers) |
| oop | C++ | CodeBeauty (YouTube) | [`learning_archive/c++/oop/`](./learning_archive/c++/oop) |

*(This table grows as new courses are added — check each folder's own README for details.)*

---

## License

This repository is licensed under MIT — see [LICENSE](./LICENSE).

The license covers **my own implementation code only**. It does not extend to the original teaching content — explanations, starter code, or ideas — of any course or playlist linked from this repo; that remains the property of its original creator.

---

## Feedback & Corrections

Spot a bug, or a better way to implement something? Open an issue:
[github.com/AnasRiemann/KittyCode_learning_archive/issues](https://github.com/AnasRiemann/KittyCode_learning_archive/issues)

---

## Author

**Anas Riemann**
- Repository: [github.com/AnasRiemann/KittyCode_learning_archive](https://github.com/AnasRiemann/KittyCode_learning_archive)
- Other projects: [Poincaré](https://github.com/AnasRiemann/Poincare_CLI_app) · [cornatui](https://github.com/AnasRiemann/cornatui-lib)
- More about me: [github.com/AnasRiemann/about_me](https://github.com/AnasRiemann/about_me)