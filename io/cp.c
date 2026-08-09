#include <stdio.h>

typedef unsigned int BYTE; //A char in C is a single byte, but whether it is signed or unsigned depends on the compiler.

int main(int argc, char *argv[])
{

    FILE *src = fopen(argv[1], "rb");
    FILE *dst = fopen(argv[2], "wb");//"r" or "w" works for text files, but for copying arbitrary bytes you should use : "rb" and "wb" for b:binary

    BYTE b;

    while (fread(&b, sizeof(b), 1, src) != 0)
    {
    fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(dst);
    fclose(src);

}