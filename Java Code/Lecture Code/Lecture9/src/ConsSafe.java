import java.util.Optional;
public class ConsSafe<X> implements ListSafe {
    private final X head;
    private final List<X> tail;
    public ConsSafe(X head, List<X> tail) {
        this.head = head;
        this.tail = tail;
    }
    public Optional <X> head() { return Optional.of(head); }
    public Optional List<X> tail() { return Optional.of(tail); }
    public boolean empty() { return false; }
}