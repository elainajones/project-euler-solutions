// A palindromic number reads the same both ways. The largest palindrome made 
// from the product of two -digit numbers is:
// 
// 9009 = 91 * 99.
// 
// 
// Find the largest palindrome made from the product of two digit numbers.

public class LargestPalindromeCameron {

   private static class ArrayThread extends Thread {
      private int[] array;
      private int MAX_VALUE;
      private int[] results;
      private int index;

      public ArrayThread(int[] array, int MAX_VALUE, int[] results, int index) {
         this.array = array;
         this.MAX_VALUE = MAX_VALUE;
         this.results = results;
         this.index = index;
      }
      
      @Override
      public void run() {
         int product = 0;
         for (int k = 0; k < MAX_VALUE - index; k++) {
            product = array[0] * array[k];
            if (isPalindrome(product)) {
               results[index] = product;
              System.out.println(array[0] + " * " + array[k] + " = " + product);
               return;
            }
         }
      }

      private boolean isPalindrome(int num) {
         int multiplier = 1;
         int LMD = 0; int RMD = 0;
         for ( ; multiplier < num; multiplier *= 10) {}
         multiplier *= 10;
         while (multiplier > 100) { 
            multiplier /= 100;
            LMD = (num - (num % multiplier)) / multiplier;
            num = (num - (LMD * multiplier));
            RMD = (num % 10);
            num = (num - RMD) / 10;

            if (LMD != RMD) { return false; }
         }
         return true;
      }
   }

   public static int calculateHighestPalindrome(int MAX_VALUE) {
      int[][] arrayOfArrays = new int[MAX_VALUE][MAX_VALUE];
      int[]   results       = new int[MAX_VALUE];

      // build each array in arrayOfArrays
      for (int i = 0; i < MAX_VALUE; i++){
         // fill the array with values
         for (int j = 0; i + j < MAX_VALUE; j++) {
            arrayOfArrays[i][j] = MAX_VALUE - i - j;
         }
         ArrayThread thread = new ArrayThread(arrayOfArrays[i], 
                                              MAX_VALUE, 
                                              results, 
                                              i);
         thread.start();
      }

      int highestPalindrome = 0;
      for (int i = 0; i < MAX_VALUE; i++) {
         if (results[i] > highestPalindrome) {
            highestPalindrome = results[i];
         }
      }
      return highestPalindrome;
   }

   public static void testNumber(int num) {
      int multiplier = 1;
      int LMD = 0; int RMD = 0;
      for ( ; multiplier < num; multiplier *= 10) {}
      multiplier *= 10;
      while (multiplier > 100) {
         if (LMD != RMD) {
            System.out.println("break");
         }
         multiplier /= 100;
         LMD = (num - (num % multiplier)) / multiplier;
         num = (num - (LMD * multiplier));
         RMD = (num % 10);
         num = (num - RMD) / 10;
         System.out.println("Multiplier: " + multiplier);
         System.out.println("LMD: " + LMD);
         System.out.println("RMD: " + RMD);
         System.out.println("num: " + num);
      }
   }

   public static void main(String[] args){
      int MAX_VALUE = Integer.parseInt(args[0]);
      System.out.println(calculateHighestPalindrome(MAX_VALUE));
      // testNumber(12345678);
   }
}

