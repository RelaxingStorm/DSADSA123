import java.util.*;
import java.lang.*;
//Shell Sort O(n^2)
public class Main{
    void Shellsort(int arr[]){
    int n = arr.length;
    for(int gap = n/2; gap>=1; gap = gap/2){
        for(int j = gap; j<n; j++){
            for(int i = j-gap; i>=0; i = i-gap){
                if(arr[i+gap] > arr[i]){
                    break;
                } 
                else {
                    int temp = arr[i+gap];
                    arr[i+gap] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
}
void display(int arr[]){
    int n = arr.length;
    System.out.println("\nSorted array: ");
    for(int i = 0; i<n; i++){
        System.out.print(arr[i] + " ");
    }
     System.out.println(" ");
}
public static void main(String args[]){
    Main mn = new Main();
    Scanner sc = new Scanner(System.in);
    int n;
    System.out.println("Shell Sort\nEnter size of Array: ");
    n = sc.nextInt();
    int arr[] = new int[n];
    System.out.println("Enter Elements of Array: ");
    for(int i = 0; i<n; i++){
        arr[i] = sc.nextInt();
    }
    mn.Shellsort(arr);
    mn.display(arr);
}

}
