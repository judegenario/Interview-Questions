/*EN: Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

EXAMPLES:
Input: [2,2,1]                      Input: [4,1,2,1,2]
Output: 1                           Output: 4                                                                   */

/*PT-BR: Dado um vetor de inteiros não vazio, cada elemento aparece duas vezes, exceto 1. Encontre esse elemento.
Seu algoritmo deve ter uma complexidade linear o(n)*/

int singleNumber(int* nums, int numsSize) {
    
    int result = 0, i= 0;
    
    for (i = 0; i<numsSize;i++){    /*Looping through an array*/
        
        result = result^nums[i];    /*variable x receives the result of the XOR operation between the bits*/
    }
    
    return result;
}

/*PT-BR: Lógica utilizada:

Para solucionar essa questão foram usados conceitos de operação bit-a-bit e o operador relacional XOR (^)

TABELA XOR
a   b   resultado
0   0   0
0   1   1
1   0   1
1   1   0

O resultado só será verdadeiro (1) quando os bits forem diferentes.
Podemos usar essa ideia para comparar os elementos do vetor, retornando o elemento que não se repete.

EX: [2, 2, 1]

result = 0;

comparar result com nums[i] (bit a bit), ou seja, 0 (em binário 00) com 2(em binário 10):

00
10

resultado: 10;
result recebe 10;

repetir a operação comparando 10 com o prox 2 (10):

10
10

resultado: 00;
result recebe 00;

comparar 00 com 1 (01):

00
01

resultado: 01;
result recebe 01, o vetor acabou, retorna 01 (1);


*/