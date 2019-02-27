//abs : (int[], int, int)->[int]
//abs(stack, size, N) = [stack[size-1]] | 0<i<=size
//dti (stack, size, N) = stack.length== N^size<=N


class ArrayIntStack implements IntStack {
    private int[]stack;
    private int size;
    private final int N;

    ArrayIntStack(){
        N = 100;
        stack = new int[N];
        size = 0;
    }

    public void push(int x){
        stack[size] = x;
        size = size+1;
    }


    public int peek(){
        assert(size>0);
        return this.stack[size];
    }

    public int pop(){
        assert(size>0);
        int result = stack[size];
        size = size-1;
        return result;
    }

    public boolean empty(){
        return(size==0);
    }


}
