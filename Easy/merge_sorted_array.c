/*Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
 

Constraints:

-10^9 <= nums1[i], nums2[i] <= 10^9
nums1.length == m + n
nums2.length == n

PT-BR: Dados dois arrays de inteiros nums1 e nums2, juntar os arrays nums2 em nums1 em um só array ordenado.

Nota: O número de elementos inicializados em nums1 e nums2 são m e n respectivamente.
Você pode assumir que nums1 tem espaço suficiente (tamanho igual a m + n) para conter elementos adicionais de nums2.*/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int end = nums1Size - 1, j = n - 1, flag = 1;

    if(m == 0)      //se o primeiro vetor for nulo, o primeiro vetor recebe os valores do segundo
    {
        for(int i = 0; i < nums1Size; i++)
            nums1[i] = nums2[i];
        return;
    }
    
    
    while(end + 1 && j + 1)     //começa a partir do final
    {
        if(flag && nums1[m - 1] >= nums2[j])    //enquanto a flag for 1 e o valor do primeiro vetor for maior que o valor do segundo
        {
            nums1[end] = nums1[m - 1];          //faz o ultimo elemento do primeiro vetor receber o maior elemento
            end--;                              //decrementa o fim
            if (m -1 != 0)                      //se o vetor não tiver acabado, decrementa seu tamanho
            {
                m--;
            }
            else                                //se tiver acabado, seta o valor 0 para a flag
            {
                flag = 0;
            }
        }
        else        //se o valor for menor, faz o ultimo receber o valor do segundo vetor
        {
            nums1[end] = nums2[j];
            end--;                      //decrementa o final e o tamanho do segundo vetor
            j--;
        }
    }
}
