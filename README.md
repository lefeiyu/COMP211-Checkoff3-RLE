# Run-Length Encoding in C

## Introduction

Run-length encoding (RLE) is a simple lossless compression method. It replaces a consecutive run of the same character with the number of repetitions followed by that character. For example:

```text
AAAAABBBCC -> 5A3B2C
```

This small project demonstrates the basic idea in C with strings that contain letters only.

## How RLE works

The program reads a string from left to right. It remembers the current character, counts how many times that character appears in a row, prints the count and character, and then moves to the next run.

For `AAAAABBBCC`, the steps are:

1. Count five consecutive `A` characters and print `5A`.
2. Count three consecutive `B` characters and print `3B`.
3. Count two consecutive `C` characters and print `2C`.
4. Combine the pieces to get `5A3B2C`.

Characters only belong to the same run when they are next to each other. Two matching characters separated by another character are counted separately.

## Compile and run

From the repository directory, compile the program with:

```sh
cc -std=c11 -Wall -Wextra -pedantic rle.c -o rle
```

Then run it:

```sh
./rle
```

Expected output:

```text
AAAAABBBCC -> 5A3B2C
ABCDEFGH -> 1A1B1C1D1E1F1G1H
AABCCCCD -> 2A1B4C1D
```

The first and third lines test repeated characters. The second line tests a string with no repeated neighboring characters.

## Algorithm and variables

The function `print_rle` uses two nested `while` loops. The outer loop processes one run at a time. The inner loop looks ahead and counts matching characters.

- `input` is the string being encoded.
- `position` is the array index where the current run starts.
- `current` stores the character in the current run.
- `count` stores how many times that character repeats consecutively.

After printing a run, the program adds `count` to `position`. This skips the characters that were just encoded and starts the next run.

The program prints the encoding directly instead of saving it in another array. This keeps the example focused on the counting algorithm.

## Why RLE is lossless

RLE is lossless because the count and character preserve enough information to rebuild the original data. For example, `5A3B2C` says to write five `A` characters, three `B` characters, and two `C` characters. That recreates `AAAAABBBCC` exactly.

This demonstration does not include a decoder. Its simple count-character notation is unambiguous only under the stated input limit: the examples contain letters and no digits. If digits were allowed as data, an encoding such as `111A` could be unclear without extra separators or escaping. A full encoder and decoder should use a format that separates counts from data, such as `(11, '1')(1, 'A')`, or another documented binary format.

## When RLE works well

RLE works well when data contains long consecutive runs of the same value. Simple images with large areas of one color are a common example. In this project, `AAAAABBBCC` becomes shorter because several repeated characters are replaced by short count-character pairs.

## When RLE increases the size

RLE is not always smaller than the original data. A string with no consecutive repetition needs a count for every character:

```text
ABCDEFGH -> 1A1B1C1D1E1F1G1H
```

The eight-character input becomes a sixteen-character encoding. This happens because RLE adds count information even when there is no repetition to summarize.

## Interesting findings

The main idea is simple, but the format matters as much as the loop. The count-character format is easy to read for letter-only examples, yet it needs a clearer design if digits or arbitrary bytes are allowed. I also found it useful to see that compression is not guaranteed: RLE depends on the pattern in the input, not just the input length.

## Presentation materials and references

My original presentation is included in the [`presentation`](presentation/) folder as `RLE_COMP211_Plain_Student_Style.pptx`.

Educational sources and notes about how they were used are listed in [`references.md`](references.md). A draft of the required AI exploration reflection is in [`reflection.md`](reflection.md).
