#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void branefuk(const char *bf)
{
    char tape[30000] = {0};
    char *ptr = tape;

    while (*bf != '\0')
    {
        switch (*bf)
        {
        case '+':
            (*ptr)++;
            break;
        case '-':
            (*ptr)--;
            break;
        case '>':
            ptr++;
            break;
        case '<':
            ptr--;
            break;
        case '.':
            printf("%c", *ptr);
            break;
        case ',':
            printf("i dont know what to do with that");
            break;
        case '[':
            if (*ptr == 0)
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
            if (*ptr != 0)
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

int main()
{
    char *input = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
    branefuk(input);
    return 0;
}
