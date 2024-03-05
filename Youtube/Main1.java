import java.util.ArrayList;

class Main1 {
    public static void main(String[] args) throws Exception {
        Heap<Integer> heap = new Heap<>();

        heap.insert(10);
        heap.insert(20);
        heap.insert(30);
        heap.insert(40);
        // System.out.println(heap.remove());
        // System.out.println(heap.remove());

        ArrayList list = heap.heapSort();
        System.out.println(list);
    }
}
