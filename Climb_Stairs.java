import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] qb = new int[n+1];
        System.out.println(cs(n,qb));
    }
    public static int cs(int n,int[] qb){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        
        if(qb[n] != 0){
            return qb[n];
        }
        int f1 = cs(n-1,qb);
        int f2 = cs(n-2,qb);
        int f3 = cs(n-3,qb);
        int ans = f1+f2+f3;
        qb[n] = ans;
        return ans;
    }

}
