// printing all the elements of matrix diagonally

import java.util.Scanner;

public class diagonalMatrix {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("No. of rows? ");
        int row = s.nextInt();
        System.out.println("No. of columns? ");
        int col = s.nextInt();
        System.out.println("Enter the matrix elements");
        int[][] arr = new int[row][col];
        for (int i = 0; i <row ; i++) {
            for (int j = 0; j <col ; j++) {
                arr[i][j] = s.nextInt();
            }
        }

        diagonal(arr,row,col);
    }

    public static void diagonal(int[][] arr , int row , int col){
    
//        loop for the first half diagonal which starts from 0 row and end till the last row ,
//        here row will vary and column is same i.e column always starts from 0

        for (int k = 0; k <row ; k++) {
            int i = k;
            int j =0;
            while(i>=0 && j<col){
                System.out.print(arr[i][j]+" ");
                i=i-1;
                j=j+1;
            }
            System.out.println();
        }
        
 // loop for the second half diagonal which starts from col 1 when row reaches to the end i.e last line
//        here row will be same i.e row always starts from row-1 and column will vary

        for (int k = 1; k <col ; k++) {
            int i=row-1;
            int j =k;
            while(i>=0 && j<col){
                System.out.print(arr[i][j]+" ");
                i=i-1;
                j=j+1;
            }
            System.out.println();
        }
    }
}
