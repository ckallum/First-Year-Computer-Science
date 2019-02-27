public class Cons implements List {
    private final X head;
    private final List<X> tail;
    public Cons(X head, List<X> tail){
        this.head = head;
        this.tail = tail;
    }

    public X head(){
        return head;
    }
    public List<X> tail(){
        return tail;
    }
    public boolean empty(){
        return false;
    }
}
