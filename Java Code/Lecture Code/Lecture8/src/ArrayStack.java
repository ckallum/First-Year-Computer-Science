public class ArrayStack<V> implements Stack<V> {
    private Object[]stack;
    private int size;
    private final int N;

    ArrayStack(){
        N = 100;
        stack = new Object[N];
        size = 0;
    }

    public void push(V x){
        stack[size] = x;
        size = size+1;
    }


    public V peek(){
        assert(size>0);
        return this.stack[size];
    }

    public V pop(){
        assert(size>0);
        Object result = stack[size];
        size = size-1;
        return result;
    }

    public boolean empty(){
        return(size==0);
    }
}
