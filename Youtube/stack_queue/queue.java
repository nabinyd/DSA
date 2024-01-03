package stack_queue;

import java.util.Queue;
import java.util.*;

public class queue {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(10);
        queue.add(20);
        queue.add(30);
        queue.add(40);
        queue.add(50);
        System.out.println(queue.size());

        System.out.println(queue.remove());
        System.out.println(queue.remove());
        System.out.println(queue.remove());
        System.out.println(queue.remove());
        System.out.println(queue.remove());
        // System.out.println(queue.remove()); //it will throw exception
        System.out.println("dequeFunction");
        deque();
    }

    public static void deque() {

        Deque<Integer> deque = new ArrayDeque<>();
        deque.push(15);
        deque.push(20);
        deque.push(25);
        deque.push(30);
        deque.push(35);

        System.out.println(deque.size());
        System.out.println(deque.pop());
        System.out.println(deque.pop());
    }
}
