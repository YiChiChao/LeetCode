
int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize){
    int bucket[1001] = {0};
    for(int i = 0; i < boxTypesSize; ++i){
        bucket[boxTypes[i][1]] += boxTypes[i][0];
    }
    int totalUnit = 0;
    for(int i = 1000; i > 0 ; --i){
        if(bucket[i] == 0)continue;
        if(truckSize >= bucket[i]){
            totalUnit += i * bucket[i];
            truckSize -= bucket[i];
        }
        else{
            totalUnit += truckSize * i;
            return totalUnit;
        }
            
    }
    return totalUnit;
}

    
