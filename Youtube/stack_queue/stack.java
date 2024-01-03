package stack_queue;

import java.util.Stack;

public class stack {
    public static void main(String[] args) {

        Stack<Integer> stack = new Stack<>();
        stack.push(14);
        stack.push(25);
        stack.push(10);
        stack.push(12);
        stack.push(40);

        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.pop()); // it will throw empty stack exception

    }

    public class CustomStack {
        protected int[] data;
        private static final int DEFAULT_SIZE = 10;

        public CustomStack() {
            this.data = new int[DEFAULT_SIZE];
        }

        public CustomStack(int size) {
            this.data = new int[size];
        }

    }
}
