package DataStructureCS61B2021sp.HwsLabsProjs;

public class Collatz {
    public static void main(String[] args) {
        helper(45671);
    }

    public static void helper(int i){
        while(i != 1) {
            System.out.print(i + " ");
            if ((i & 1) == 0)
                i /= 2;
            else
                i = 3 * i + 1;
        }
        System.out.println(1);
    }
}
