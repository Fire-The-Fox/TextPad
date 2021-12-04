# TextPad version
VERSION=1.0

# paths
BIN_PATH=usr/local/bin
DESTDIR=/

# compiler

CFLAGS = -o ./bin/TextPad `pkgconf --cflags --libs gtk+-3.0`

GCC = gcc