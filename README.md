# Pikchu
A file compression and decompression tool.

Algorithms implemented so far:
-  Run length encoding and decoding (partially)


- Run length encoding and decoding:
1. Pick the first character from the source string.
2. Append the picked character to the destination string.
3. Count the number of subsequent occurances of the picked character and append the count to the destination string.
4. Pick the next character and repeat steps 2, 3 and 4 if the end of string is not reached.

## Todo
[ ] Implement decoding
[ ] Get RLE work for images

## Usage
```
gcc -o main ./src/main.c
./main ./test/sample.txt sample.pck 
```
