/*EN: Given a 32-bit signed integer, reverse digits of an integer.

Example 1:      Example 2:          Example 3:
Input: 123      Input: -123         Input: 120
Output: 321     Output: -321        Output: 21

Assume we are dealing with an environment which could only store integers within 
the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, 
assume that your function returns 0 when the reversed integer overflows.*/

/*PT-BR: Dado um inteiro de 32 bits com sinal, inverta seus dígitos. Suponha que
só é possível armazenar inteiros dentro do intervalo de 32 bits: [−231, 231 - 1]. A função
deve retornar 0 quando estourar esse intervalo*/


int reverse(int x){     //function to reverse an integer
    int num = 0;
    int result = 0;
    while (x != 0) {    //while the number is different from 0
        num = x % 10;   //variable "num" receives the result of the x%10 module
        x /= 10;        //divide x by 10

        /*checks if the result is greater than the allowed number (overflow)
        INT_MAX = 2147483647 e INT_MIN = -2147483647 - 1*/
        if((result > (INT_MAX/10)) || (result < (INT_MIN/10))) return 0;  
        
        result = result * 10 + num; //receives the reverse value
        
    }
         
    return result;      //return the reverse number
} 

/*PT-BR: a lógica é a seguinte:
Dado 123

Passo 1:    fazer 123%10 = 3
            num = 3;

Passo 2:    dividir 123/10 = 12; (lembrando que na divisão inteira as casas decimais não são consideradas)
Passo 3:    verificar se o result é maior do que o permitido;
Passo 4:    fazer result receber 0*10 + 3, ou seja, 3

Repetir o processo, agora com o novo valor de x que é 12

Passo 1:    fazer 12%10 = 2
            num = 2;

Passo 2:    dividir 12/10 = 1;
Passo 3:    verificar se o result é maior do que o permitido;
Passo 4:    fazer result receber 3*10 + 2, ou seja, 32

Repetir o processo, agora com o novo valor de x que é 1

Passo 1:    fazer 1%10 = 1
            num = 1;

Passo 2:    dividir 1/10 = 0;
Passo 3:    verificar se o result é maior do que o permitido;
Passo 4:    fazer result receber 32*10 + 1, ou seja, 321

Resultado = 321, o número foi invertido

*/