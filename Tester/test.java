import java.util.Arrays;
public class test{
    public static double median(int[] arr1, int[] arr2){
        int count = (arr1.length+arr2.length+1)/2;
        int[] ret = new int[arr1.length+arr2.length];

        for(int i = 0; i < arr1.length; i++){
            ret[i] = arr1[i];
        }

        for(int i = 0; i < arr2.length; i++){
            ret[i+arr1.length] = arr2[i];
        }
        Arrays.sort(ret);
        if(ret.length%2 != 0){
            return ret[ret.length/2+1];
        }else{
            return (double)(ret[ret.length/2]+ret[ret.length/2-1])/2;
        }
    }
    public static void main(String args[]){
        int[] arr1 = new int[]{1,2,6,8,12,15};
        int[] arr2 = new int[]{2,5,8,15};

        System.out.println(median(arr1,arr2));
    }
}