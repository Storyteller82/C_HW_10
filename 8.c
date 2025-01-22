#include <stdio.h>

int main(void)
{
    FILE *f, *ff;
    //int sum = 0;
    signed char c;
    int digit[1000] = {0}; // для считывания
    int i = -1,  previos_flag = 0, n = 0;
    
    f = fopen("input.txt", "r");
    
    while ((c = fgetc(f)) != EOF)
    {
     //   printf("%c, %x\n", c, c);
        if (c >= '0' && c <= '9') // если это цифра
        {
            if (previos_flag == 1) // проверяем была ли до этого цифра
            {
                i = i * 10 + (c - '0');  // собираем число в кучу
            }
            else                    // до этого цифр не было, шли одни буквы
            {
                i = (c - '0'); // закидываем первую цифру "нейтрализованная" промежуточная забирает цифру
                previos_flag = 1; // и говорим что только что была цифра          
            }
        }
        else  // если это не цифра, а буква
        {
            previos_flag = 0;  // говорим, что цифры не было еще или закончились

             if (i >= 0)     // и если в промежуточной что-то хранится (положительное число)
             {
                digit[n] = i;   // число закидываем в массив
                n++;
                i = - 1; // а промежуточную "обнуляем" "нейтрализуем"
             }
         }
    }

    // сортировка массива ==============================================================

    int temp;
    int no_swap;

    for (int i = n-1; i >= 0; i--)
    {
        no_swap = 1;
        for (int j = 0; j < i; j++)
        {
            if (digit[j] > digit[j + 1])
            {
                temp = digit[j];
                digit[j] = digit[j + 1];
                digit[j + 1] = temp;
                no_swap = 0;
            }
        }
        if (no_swap == 1)
            break;
    }

    // закидываем массив в файл ===========================================================
   
    ff = fopen("output.txt", "w");
   
    for (int i = 0; i <=(n-1); ++i)
    {
        fprintf(ff, "%d ", digit[i]);
    }
    
    
    fclose(f);
    fclose(ff);
    return 0;
}