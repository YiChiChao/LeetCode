class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b){
            return a[1] > b[1]; //decreasing
        });
        int totalUnit = 0;
        for(int i = 0; truckSize > 0 && i < boxTypes.size() ; ++i){
            if(truckSize >= boxTypes[i][0]){
                totalUnit += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else{
                totalUnit += truckSize * boxTypes[i][1];
                truckSize = 0;
            }
            
        }
        return totalUnit;
    }
};