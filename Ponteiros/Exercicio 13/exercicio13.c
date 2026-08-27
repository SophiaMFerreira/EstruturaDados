/*  13. Quais as saídas produzidas pelo trecho de código abaixo?
        int main() {
            int y, *p, x;
            y = 0;
            p = &y;
            x = *p;         ->  x = 0
            x = 4;              x = 4
            (*p)++;             *p = 1; y = 1
            x--;                x = 3
            (*p) += x;          *p = 4; y = 4
            printf ("\nx = %d\n", x);
            printf ("\ny = %d\n", y);
        }

        R.: x = 3 e y = 4

*/

#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

        int y, *p, x;
        y = 0;
        p = &y;
        x = *p;
        x = 4;
        (*p)++;
        x--;
        (*p) += x;

        printf ("\nx = %d\n", x);
        printf ("\ny = %d\n", y);
}
