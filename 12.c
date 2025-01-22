#include <stdio.h>

int main(void)
{
    FILE *f, *ff;
    
    signed char c;
    int previos_spase = 1;

    f = fopen("input.txt", "r");
    ff = fopen("output.txt", "w");
    
    while ((c = fgetc(f)) != EOF)
    {       
        if ( (c == ' ') && (previos_spase == 1))
        {
            continue;
        }

        if (c == ' ')
        {
            c = '\n';
            previos_spase = 1;
        }
        else 
        {
            previos_spase = 0;
        }
        
        fprintf(ff, "%c", c);
    }
   
    fclose(f);
    fclose(ff);
    return 0;
}