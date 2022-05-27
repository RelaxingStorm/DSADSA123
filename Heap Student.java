import java.lang.*;
import java.util.*;
// Sorting Data using Heap (MinHeap and MaxHeap method)
public class Main{
    public void MaxHeap(int arr[]){
        int n = arr.length;
        // First create a heap; starting from mid to left
        for(int i = (n/2)-1; i>=0; i--){
            MaxHeapify(arr, n, i);
        }
        // On this created heap, 
        for(int i = n-1; i>0; i--){
            // swap first element (root) with last index
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            // arguments: arr, i treated as ending of new heap, 0 treated as largest (arr[0])
            MaxHeapify(arr, i, 0);
        }
    }
    public void MinHeap(int arr[]){
        int n = arr.length;
        for(int i = (n/2)-1; i>=0; i--){
            MinHeapify(arr, n, i);
        }
        for(int i = n-1; i>0; i--){
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            MinHeapify(arr, i, 0);
        }
    }
    void MaxHeapify(int arr[], int n, int i){
        int largest = i;        // i assumed as largest root of subtree
        int l = (i * 2) + 1;    // left child of root in subtree
        int r = (i * 2) + 2;    // right child of root in subtree
        // if (left child) > (largest) && (left child) < (heap length)
        if(l < n && arr[l] > arr[largest]){
            largest = l;    // change largest to (left child)
        }
        // if (right child) > (largest) && (right child) < (heap length)
        if(r < n && arr[r] > arr[largest]){
            largest = r;    // change largest to right
        }
        // check if largest was changed; if yes, swap
        if(largest != i){
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            // Now recursively heapify the subtree
            MaxHeapify(arr, n, largest);
        }
    }
    
    void MinHeapify(int arr[], int n, int i){
        int smallest = i;        // i assumed as smallest root of subtree
        int l = (i * 2) + 1;    // left child of root in subtree
        int r = (i * 2) + 2;    // right child of root in subtree
        // if (left child) < (smallest) && (left child) < (heap length)
        if(l < n && arr[l] < arr[smallest]){
            smallest = l;    // change smallest to (left child)
        }
        // if (right child) < (smallest) && (right child) < (heap length)
        if(r < n && arr[r] < arr[smallest]){
            smallest = r;    // change smallest to right
        }
        // check if smallest was changed; if yes, swap
        if(smallest != i){
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
            // Now recursively heapify the subtree
            MinHeapify(arr, n, smallest);
        }
    }
    
    void printArr(int arr[]){
        for(int i = 0; i<arr.length; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println(" ");
    }
    
    public static void main(String args[]){
        Main m = new Main();
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the no. of students: ");
        n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter their marks: ");
        for(int i = 0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        
        m.MaxHeap(arr); // sorts in ascending (increasing order) (low to high)
        System.out.println("Lowest Marks: " + arr[0]);
        m.printArr(arr);
        m.MinHeap(arr); // sorts in descending (decreasing order) (high to low)
        System.out.println("Highest Marks: " + arr[0]);
        m.printArr(arr);
    }
}

/* Output:
Enter the no. of students: 
3
Enter their marks: 
67
12
90
Lowest Marks: 12
12 67 90  
Highest Marks: 90
90 67 12  
*/