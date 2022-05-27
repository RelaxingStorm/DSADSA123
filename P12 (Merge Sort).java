//Merge Sort
// left is LowerIndex, right is HigherIndex
public class mergeSort{
    int[] arr;
    int[] tempMergeArr;
    int length;
    public static void main(String[] args){
        int[] inputArr = {34,46,1,12,43};
        mergeSort ms = new mergeSort();
        ms.sort(inputArr);
        
        for(int i : inputArr){
            System.out.print(i + " ");
        }
        System.out.println("");
        for(int i : ms.tempMergeArr){
            System.out.print(i + " ");
        }
    }
    
    public void sort(int inputArr[]){
        this.arr = inputArr;    //copy address of inputArr; Modifies original array
        this.length = inputArr.length;
        this.tempMergeArr = new int[length];
        divideArray(0, length - 1);
    }
    
    public void divideArray(int left, int right){
        if(left < right){
            int mid = left + (right - left) / 2;
            // it will sort left side of an array
            divideArray(left, mid);
            // it will sort right side of an array
            divideArray(mid + 1, right);
            
            mergeArray(left, mid, right);
        }
    }
    
    public void mergeArray(int left, int mid, int right){
        // loop to assign arr values to tempMergeArr
        for(int i = left; i <= right; i++){
            tempMergeArr[i] = arr[i];
        }
        int i = left;
        int j = mid + 1;
        int k = left;   // for arr[k] index (inserting at LowerIndex)
        while(i <= mid && j <= right){
            if(tempMergeArr[i] <= tempMergeArr[j]){
                arr[k] = tempMergeArr[i];
                i++;
            } else {
                arr[k] = tempMergeArr[j];
                j++;
            }
            k++;
        }
        while(i <= mid){
            arr[k] = tempMergeArr[i];
            k++;
            i++;
        }
    }
}

/* Output: 
1 12 34 43 46 
1 34 46 12 43 
*/