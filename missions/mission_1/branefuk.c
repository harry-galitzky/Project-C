#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void branefuk(const char *bf)
{
    char str[30000] = {0};
    char *output = str;

    while (*bf != '\0')
    {
        switch (*bf)
        {
        case '+':
            (*output)++;
            break;
        case '-':
            (*output)--;
            break;
        case '>':
            output++;
            break;
        case '<':
            output--;
            break;
        case '.':
            printf("%c", *output);
            break;
        case ',':
            printf("i dont know what to do with that");
            break;
        case '[':
            if (*output == 0)
            {
                int loops = 1;
                while (loops > 0)
                {
                    bf++;
                    if (*bf == '[')
                        loops++;
                    if (*bf == ']')
                        loops--;
                }
            }
            break;
        case ']':
            if (*output != 0)
            {
                int loops = 1;
                while (loops > 0)
                {
                    bf--;
                    if (*bf == ']')
                        loops++;
                    if (*bf == '[')
                        loops--;
                }
            }
            break;
        default:
            break;
        }
        bf++;
    }
}
