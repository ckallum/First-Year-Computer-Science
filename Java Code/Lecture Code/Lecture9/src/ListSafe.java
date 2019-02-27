import java.util.Optional;
interface ListSafe <X>{
    public Optional <X> head();
    public Optional List<X> tail();
    public boolean empty();
}
