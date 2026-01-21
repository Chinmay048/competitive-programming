class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> temp;
        for(int i=0;temp.size()<arr.size();i++){
            if(arr[i]!=0)
                temp.push_back(arr[i]);
            else{
                temp.push_back(arr[i]);
                if(temp.size()==arr.size())
                    break;
                temp.push_back(0);
            }
           

        }
        arr=temp;
    }
};