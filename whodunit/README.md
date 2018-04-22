# Questions

## What's `stdint.h`?

It's a header file in C's standard library that allows programmers to write more portable code by providing typedefs that specify values for each data type.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

These tell the program what the maximun values are for the respective data types.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE - 1 byte; DWORD - 4 bytes; LONG - 4 bytes; WORD - 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

ASCII B & M

## What's the difference between `bfSize` and `biSize`?

biSize - the number of bytes required by the structure
bfSize - the size of the BITMAP file in bytes.

## What does it mean if `biHeight` is negative?

the file is top down with the origin in the top left corner

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

fopen will return NULL if you are opening a file to read and the file doesn't exist.

## Why is the third argument to `fread` always `1` in our code?

We are looking at each individual element.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3      (4 - (9 % 4) % 4   ==>  4-1 = 3 % 4   ==>   3

## What does `fseek` do?

sets a file position

## What is `SEEK_CUR`?

tells the program that you want to set the file position from the current location.
