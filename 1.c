#include <stdio.h>

int main(void)
{
    FILE *f, *ff;
    int sum = 0;
    signed char c;
    char text1[100] = {0}; // для считывания
    f = fopen("input.txt", "r");
    int i = 0;
    while ((c = fgetc(f)) != EOF)
    {
     //   printf("%c, %x\n", c, c);
        if (c != ' ' && c != '\n')
        {
            sum++;
            text1[i] = c;
            i++;
        }
    }
   // printf(" %d\n", sum);

   // char text1[100]; // для считывания
    ff = fopen("output.txt", "w");
   // while (fgets(text1, sizeof(text1), f) != NULL)
    //   printf("%s, ", text1);
    ;
    fprintf(ff, "%s, ", text1);
    fprintf(ff, "%s, ", text1);
    fprintf(ff, "%s", text1);
    fprintf(ff, " %d", sum);
    fclose(f);
    fclose(ff);
    return 0;
}