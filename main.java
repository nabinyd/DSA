
/**
 * main
 */
import java.util.Arrays;

public class main {

    public static void main(String[] args) {
        int[] arr = { 55, 2, 6, 8, 26 };
        selection(arr);
        System.out.println(Arrays.toString(arr));

    }
    /* -------------------------------- insertion ------------------------------- */

    static void insertion(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j > 0; j--) {
                if (arr[i] < arr[j - 1]) {
                    swap(arr, j, j - 1);
                } else {
                    break;
                }
            }
        }
    }

    /* -------------------------------- swapping -------------------------------- */

    static void swap(int[] arr, int first, int second) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }

    /* -------------------------------- selection ------------------------------- */

    static void selection(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            // find the max item in the remaining array and swap with correct index
            int last = arr.length - i - 1;
            int maxIndex = getMaxIndex(arr, 0, last);
            swap(arr, maxIndex, last);
        }
    }

    /* ---------------------------- getting max index --------------------------- */

    private static int getMaxIndex(int[] arr, int start, int end) {
        int max = start;
        for (int i = start; i <= end; i++) {
            if (arr[max] < arr[i]) {
                max = i;
            }
        }
        return max;
    }

}