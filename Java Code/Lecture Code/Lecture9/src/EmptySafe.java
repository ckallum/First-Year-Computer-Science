import java.util.Optional;
class EmptySafe implements ListSafe {
    public Optional <X> head(){
        return Optional.empty();
    }
    public Optional List<X> tail(){
        return Optional.empty();
    }
    public boolean empty(){
        return true;
    }
}
