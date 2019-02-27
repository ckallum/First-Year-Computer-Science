public class ObjectArrayStack implements ObjectStack {
    private Object[]stack;
    private int size;
    private final int N;

    ObjectArrayStack(){
        N = 100;
        stack = new Object[N];
        size = 0;
    }

    public void push(Object x){
        stack[size] = x;
        size = size+1;
    }


    public Object peek(){
        assert(size>0);
        return this.stack[size];
    }

    public Object pop(){
        assert(size>0);
        Object result = stack[size];
        size = size-1;
        return result;
    }

    public boolean empty(){
        return(size==0);
    }

}
