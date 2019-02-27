class LinkedStack implements Stack {
    private ListNode<X> xs = new Empty<X>();

    public void push(X x){
        xs = new Cons <X>(x,xs);
    }

    public X pop(){
        assert !xs.empty();
        X result = xs.head;
        xs = xs.tail;
        return result;
    }

    public X peek(){
        assert !xs.empty();
        return xs.head;
    }

    public boolean empty(){
        return(xs.empty());
    }
}
