#!/usr/bin/env python3
files = ' '.join([str(x) for x in __import__("pathlib").Path('.').iterdir() if x.is_file() and __import__("re").match('.*\.c', str(x))])
with open("Makefile", "w") as f:f.write(f"all:\n\t$(CC) -o Application.out {files} -lSDL2 -lGL -I.\ndebug:\n\t$(CC) -g {files} -o Debug.out -lSDL2 -lGL -I.")
