// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int left = 1, right = n;
    if(n == 1)return 1;
    while(left <= right){
        int mid = left+(right-left)/2;
        if(isBadVersion(mid) && mid == 0)return mid;
        else if(isBadVersion(mid)){
            if(!isBadVersion(mid-1))return mid;
            else right = mid;
            
        }
        else{
            left = mid+1;
            printf("%d\n", left);
        }
    }
    return -1;
}