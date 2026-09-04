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
  <sub>Every folder here follows a public course or YouTube playlist step by step — my own code, written while learning,<br>kept as a reference for anyone following the same material.</sub>
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

This repo collects my own implementations while working through public programming courses and YouTube playlists — across whatever language or topic I happen to be learning at the time.

None of the teaching content here is mine. Every course folder credits its original source — the creator, and a link to the playlist or video — right in that folder's own `README.md`. What's mine is the code: my own attempt at each lesson, written while following along.

---

## How This Repo Is Organized

Courses are grouped by language first, then by topic:

```
KittyCode_learning_archive/
├── learning_archive/
│   └── c++/
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
  - The original course/playlist link and creator
  - Topics covered
  - Build/run instructions for that language

**Adding a new course:** create `learning_archive/<language>/<topic>/`, drop in the code, add a short `README.md` crediting the source, and add one row to the [Courses](#courses) table below.

---

## Getting Started

1. Pick a course from the [table below](#courses)
2. Open its folder — its own `README.md` has the original source link and any build/run steps
3. Since each folder is self-contained, you only need the tools for that specific language, not the whole repo

---

## Courses

| Course | Language | Source | Folder |
|---|---|---|---|
| Pointers | C++ | CodeBeauty (YouTube) | [`learning_archive/c++/pointers/`](./learning_archive/c++/pointers) |

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