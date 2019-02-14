abstract class Card {
    abstract String getName();
    abstract void accept(Visitor v);
}
