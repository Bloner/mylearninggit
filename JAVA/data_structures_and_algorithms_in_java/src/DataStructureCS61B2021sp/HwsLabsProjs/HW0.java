package DataStructureCS61B2021sp.HwsLabsProjs;

public class HW0 {
    public static void main(String[] args){
        int[] a = {1,2,-3,4,5,4};
        four(a, 3);
        System.out.println(java.util.Arrays.toString(a));
    }

    public static void run(){
        String a = "Achilles";
        String t = "Tortoise";
        double aPos = 0;
        double tPos = 100;
        double aSpeed = 20;
        double tSpeed = 10;
        double totalTime = 0;
        while (aPos < tPos) {
            System.out.println("At time: " + totalTime);
            System.out.println("    " + a + " is at position " + aPos);
            System.out.println("    " + t + " is at position " + tPos);
            double timeToReach = (tPos - aPos) / aSpeed;
            totalTime = totalTime + timeToReach;
            aPos = aPos + timeToReach * aSpeed;
            tPos = tPos + timeToReach * tSpeed;
        }
    }

    public static void one(int line){
        if(line < 0)System.out.println("Wrong number");
        int i = 0;
        while(i++ < line){
            for(int j = 0;j < i;j++) {
                System.out.print("*");
            }
            System.out.print("\n");
        }
    }

    public static int two(int[] arr){
        int max = arr[1];
        for(int i = 0;i < arr.length;i++){
            if(max < arr[i])max = arr[i];
        }
        return max;
    }

    public static int three(int[] arr){
        int max = arr[1];
        int i = 0;
        while(i < arr.length){
            if(max < arr[i])max = arr[i];
            i++;
        }
        return max;
    }

    public static void four(int[] a, int n){
        for(int i = 0; i < a.length; i++){
            if(a[i] > 0){
                int res = 0;
                for(int j = i; j < a.length && (j-i)<=n; j++)res += a[j];
                a[i] = res;
            }
        }
    }
}
