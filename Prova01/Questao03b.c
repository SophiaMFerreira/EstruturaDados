/*  Quest˜ao 3b: [5 pontos]
    Complexidade esperada: O(n);

    #include <stdio. h>

    int main ( ) {
        long a , n ;                                    // Instancia a e n do tipo long
        printf( ”\na=” );                               // Imprime a =
        scanf( ”%ld ” , &a ) ;                          // Recebe m valor para a
        printf( ”\nn=” ) ;                              // Imprime n =
        scanf( ”%ld ” , &n ) ;                          // Recebe m valor para n
        long z=1, t=a , k=n ;                           // Instancia z= 1, t = a e k = n no tipo long
        while ( k>0 ) {                                 // Executa o codigo enquanto k for menor que 0
            if( k%2 != 0 ) z*=t ;                       // Se o resto de k dividido por 0 for diferente de 0, multiplica o valor de z por t ( z * t) e garda em z
            k = k / 2;                                  // Divide k por 2
            if ( k != 0 ) t*=t ;                        // Se o resto de k dividido por 0 for diferente de 0, multiplica o valor de t por t ( t * t) e garda em t
            }
            printf( ”\nz=%ld \n ” , z ) ;               // Imprime o valor de z
        }
    }

    Em resumo o programa recebe dois valores e leva k, z e t a 0   FJ ??????

    Complexidade:

    int main ( ) {
        long a , n ;                                    // 1
        printf( ”\na=” );                               // 1
        scanf( ”%ld ” , &a ) ;                          // 1
        printf( ”\nn=” ) ;                              // 1
        scanf( ”%ld ” , &n ) ;                          // 1
        long z=1, t=a , k=n ;                           // 1
        while ( k>0 ) {                                 // log n
            if( k%2 != 0 ) z*=t ;                       // depende
            k = k / 2;                                  // depende
            if ( k != 0 ) t*=t ;                        // depende
            }
            printf( ”\nz=%ld \n ” , z ) ;               // 1
        }
    }

                                                        //TOT: log n + 6 = O(log n)
    Complexidade retornada por *On: O(log n)
*/

#include <stdio.h>   //Acrescentei

int main ( ) {
        int oN = 0;
        long a , n ;                                     // 1
        printf( "\na=" );                                // 1
        //scanf( "%%ld " , &a ) ;//Mudei
        scanf( "%ld" , &a ) ;// 1
        //scanf( "%%ld" , &n ) ; //Mudei                          // 1
        printf( "\nn=" ) ;
        scanf( "%ld" , &n ) ; //Mudei

        long z=1, t=a , k=n ;                           // 1
        while ( k>0 ) {                                 // log n -> pois k é dividido sucessivamente até chegar a 0  FJ Ok!!! (log na base 2)
            if( k%2 != 0 ) z*=t ;                       //
            k = k / 2;                                  //
            if ( k != 0 ) t*=t ;                        //
             oN++;
            printf( "\nOn= %d", oN);                    // log n
        }
            printf( "\nz=%ld \n " , z ) ;               // 1
}
