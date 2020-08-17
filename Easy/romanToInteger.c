/*Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together.
Twelve is written as, XII, which is simply X + II. 
The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX.
There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. 
Input is guaranteed to be within the range from 1 to 3999.*/

/*PT-BR: Dado um número romano, convertê-lo para um inteiro.
A entrada deve estar na faixa de 1 a 3999.

--------------------------------------------------------------------------------------------------------*/

int simple_case(char s){        /*switch case that returns the basic cases of Roman numerals*/
    
    switch (s){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;            
    }
        
}

int romanToInt(char *s){    /*function to convert a Roman numeral to an integer*/

    int result=0;           /*variable to store the result*/
    
    for(int i = 0; i < strlen(s); i++){ /*"for" that analyzes character by character until the end of the string*/
        
        result += simple_case(s[i]);    /*result receives the simple case*/

        if((i > 0) && (simple_case(s[i-1]) < simple_case(s[i]))){   /*if the previous character is less*/
            result = result - (2*(simple_case(s[i-1])));            /*subtracts twice the previous character from result*/
        }
    }
        
    return result;

}

/*-------------------------------------------------------------------------------------------------------------

PT-BR: Lógica utilizada

Caso seja algum caso base (I, V, X, L, C, D, M), retorna o seu valor direto.

Caso seja um número do tipo III:

Somar o primeiro caractere com o resultado, no caso, 0 + 1 = 1;
Verificar se o caracterer anterior é menor que o atual, nesse caso não é;
Então continua somando, 1 + 1 = 2;
Verificar se o caracterer anterior é menor que o atual, nesse caso não é;
Então continua somando, 2 + 1 = 3;
A string acabou e o valor de III = 3;

Caso seja um número do tipo IX:

Somar o primeiro caractere com o resultado, no caso, 0 + 1 = 1;
Verficar se o caractere anterior é menor que o atual, nesse caso não é;
Então continua somando, 1 + 10 = 11;
Verficar se o caractere anterior é menor que o atual, nesse caso é;
Então fazer resultado receber resultado menos 2 vezes o valor anterior,
ou seja, 11 - (2*1) = 9;
A string acabou e o valor de IX = 9;

*/