import java.lang.*;
import java.util.*;     // for scanner class
// Sorting Data using Heap (Max Heap method)
public class Main{
    public void sort(int arr[]){
        int n = arr.length;
        // First create a heap; starting from mid to left
        for(int i = (n/2)-1; i>=0; i--){
            heapify(arr, n, i);
        }
        // On this created heap, 
        for(int i = n-1; i>0; i--){
            // swap first element (root) with last index
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            // arguments: arr, i treated as ending of new heap, 0 treated as largest (arr[0])
            heapify(arr, i, 0);
        }
    }
    void heapify(int arr[], int n, int i){
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
            heapify(arr, n, largest);
        }
    }
    
    void printArr(int arr[]){
        for(int i = 0; i<arr.length; i++){
            System.out.print(arr[i] + " ");
        }
    }
    
    public static void main(String args[]){
        Main m = new Main();
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the elements: ");
        for(int i = 0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        m.sort(arr);
        System.out.println("Sorted Array: ");
        m.printArr(arr);
    }
}