class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 2) return;
        
        int left_zero = 0, curr = 0;
    
        while(curr < nums.size()) {
            if (nums[curr] != 0) {
                swap(nums[left_zero], nums[curr]);
                left_zero++;
            }
            curr++;
        }
    }
};

/*
    Explicação:
        - Two pointers approach
        - Os dois ponteiros são iniciados no começo do vector e percorrem juntos
        até que cheguem a um 0 (realizando fake swaps da mesma posição para a 
        mesma posição). A partir daí o ponteiro left_zero marcará a posição do 
        zero mais a esquerda;
        - Em seguida, o ponteiro curr procura o primeiro valor não-nulo depois do left_zero,
        realizando o swap quando o encontra.
        
    Complexidade:
        - Tempo: O(n)
        - Espaço: O(1)
        
*/
