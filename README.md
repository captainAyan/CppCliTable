<p align="center">
  <h1 align="center">C++ Cli Table 💡</h1>
  <p align="center">
    C++ "single header file" library for drawing tables in console.
    <br />
    <a href="https://github.com/captainAyan/CppCliTable/issues">Report Bug 😓</a>
  </p>
</p>

## About

A C++ "single header file" library for drawing tables in the console.

## Getting Started / Setup
### As User
"Copy and Paste" or "Download" the <a href="https://raw.githubusercontent.com/captainAyan/CppCliTable/main/table.h">table.h</a> file, and add it to your project.

### As Developer
#### Windows
1. Clone the repo and enter the folder
2. Run `make.bat` or `./make.bat`
#### Linux & Mac
_Coming Soon_ 😁

## Usage

### Include `table.h` in project
```c++
#include "table.h"
```

### Instantiate a Table
```c++
Table table;
```

### Instantiate Columns

#### Description of Column constructor:
Arg No. | Description
-|-|
0|Name of the Column Header|
1|Alignment of Column Header|
2|Alignment of Column values|
3|Column padding|
4|Column size (amount of letter it can contain)|
5|Column resizability|

#### Alignment Parameters
1. **Column::CENTER_ALIGN**: For aligning value or header to the *center*.
2. **Column::RIGHT_ALIGN**: For aligning value or header to the *right*.
3. **Column::LEFT_ALIGN**: For aligning value or header to the *left*.

#### Resizability Parameters
1. **Column::RESIZABLE**: The 'column size'<sup>1</sup> will increase automatically if the values don't fit. 
2. **Column::NON_RESIZABLE**: The 'column size'<sup>1</sup> will not change even if the values don't fit.

1 *'Column size' means the same as mentioned in **Description of Column constructor** Arg No. 4*

```c++
Column c[3] = {
  Column("Name", Column::CENTER_ALIGN, Column::LEFT_ALIGN, 1,7, Column::NON_RESIZABLE),
  Column("Topic", Column::CENTER_ALIGN, Column::RIGHT_ALIGN, 1,2, Column::RESIZABLE),
  Column("Nation", Column::CENTER_ALIGN, Column::LEFT_ALIGN, 1,5, Column::NON_RESIZABLE)
};
```

### Assigning Columns to the Table
```c++
for (int i = 0; i < 3; i++) {
  table.addColumn(c[i]);
}
```

### Adding Rows
```c++
std::string r[3][3] = {
  {"Samuel Miller", "Coding Memes", "Venezuela"},
  {"DevEd", "Web Development", "Germany"},
  {"Mykull", "Crack Head", "U.S.A"}
};

for (int i = 0; i < 3; i++) {
  table.addRow(r[i]);
}
```

### Printing the Table
```c++
table.draw();
```
#### Result:
```bash
+=========+=================+=======+
|  Name   |      Topic      | Natio |
|         |                 |   n   |
+=========+=================+=======+
| Samuel  |    Coding Memes | Venez |
| Miller  |                 | uela  |
+---------+-----------------+-------+
| DevEd   | Web Development | Germa |
|         |                 | ny    |
+---------+-----------------+-------+
| Mykull  |      Crack Head | U.S.A |
+---------+-----------------+-------+
```

### Line Breaking
For **breaking line** use `\n` character.
```c++
std::string r[3][3] = {
  {"Samuel Miller", "Coding Memes", "Venezuela"},
  {"DevEd", "Web Development", "Germany"},
  {"Mykull", "Crack\n Head", "U.S.A"}
};
```
#### Result:
```bash
+=========+=================+=======+
|  Name   |      Topic      | Natio |
|         |                 |   n   |
+=========+=================+=======+
| Samuel  |    Coding Memes | Venez |
| Miller  |                 | uela  |
+---------+-----------------+-------+
| DevEd   | Web Development | Germa |
|         |                 | ny    |
+---------+-----------------+-------+
| Mykull  |           Crack | U.S.A |
|         |            Head |       |
+---------+-----------------+-------+
```

## Contribution
Just send me a pull request. Mention your discord or instagram id.

(if the instructions were unclear, please let me know)

## Contact
Send me a message on discord or instagram. Check out my [Profile Readme](https://github.com/captainAyan)