#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void branefuk(const char *bf)
{
    char *r;
    char *output = (char *)malloc(30000 * sizeof(char));

    while (*bf != '\0')
    {
        switch (*bf)
        {
        case '+':
        {
            (*output)++;
            break;
        }

        case '-':
        {
            (*output)--;
            break;
        }
        case '>':
        {
            ++output;
            break;
        }
        case '<':
        {
            --output;
            break;
        }
        case '.':
        {
            printf("%c\n", *output);
            break;
        }
        case ',':
        {
            printf("i dont know what to do with that");
            break;
        }
        case '[':
        {
            r = output;
            if (*output == 0)
            {
                while (*bf != ']')
                {
                    ++bf;
                }
            }
            else
            {
                continue;
            }
            break;
        }
        case ']':
        {
            output = r;
            break;
        }
        default:

            break;
        }
        ++bf;
    }
    // free(output);
}

int main()
{
    char *input = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
    branefuk(input);
    return 0;
}
