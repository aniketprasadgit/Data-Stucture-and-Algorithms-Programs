import java.io.*;
import java.util.*;

public class Main{
  public static void display(int[] a){
    StringBuilder sb = new StringBuilder();

    for(int val: a){
      sb.append(val + "
");
    }
    System.out.println(sb);
  }

public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    int[] a = new int[n];
    for(int i = 0; i < n; i++){
       a[i] = Integer.parseInt(br.readLine());
    }

    int[] span = solve(a);
    display(span);
 }

 public static int[] solve(int[] arr){
     int[] ans = new int[arr.length];
     Stack<Integer> st = new Stack<>();
     ans[0] = 1;
     st.push(0);
     
     for(int i = 1; i< arr.length;i++){
         // pop all smaller elements on left
         while(st.size() != 0 && arr[st.peek()] < arr[i]){
             st.pop();
         }
         // check size of stack and update ans
         if(st.size() == 0){
             ans[i] = i+1;
         }
         else{
             ans[i] = i - st.peek();
         }
         // push current index in stack
         st.push(i);
     }
     return ans;
     

 }

}
