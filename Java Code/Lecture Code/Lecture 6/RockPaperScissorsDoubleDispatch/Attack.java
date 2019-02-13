public abstract class Attack {
    abstract void handle(Attack attack);
    abstract void handleRock(Attack a);
    abstract void handlePaper(Attack a);
    abstract void handleScissors(Attack a);
}
