class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        for (int num : nums1) {
            hashmap[num]++;
        }
        
        vector<int> ans;
        
        for (int num : nums2) {
            if (hashmap[num]) {
                ans.push_back(num);
                hashmap[num]--;
            }
        }
        return ans;
    }
};

/* 
    Explicação:
        - Hashmap de frequencia cuja chave são os números do primeiro array e 
        os valores são a frequencia dos próprios números.
        - Itera-se no segundo array e é verificado se a chave já existe no 
        hashmap. Caso exista, o valor é adicionado ao array de resposta e a 
        frequencia é decrementada. 
    
    Complexidades:
        - Espaço: O(max(n,m))
        - Tempo: O(max(n,m))
*/
