public class Runner {
    public static void main(String[] args) {
        Mammal panda = new Panda();
        Mammal sharl = new Shark();
        Mammal dug = new Dog();
        Visitor dogv = new DogVisitor();
        Visitor pandav = new PandaVisitor();
        panda.accept(pandav);
        panda.accept(dogv);
        dug.accept(dogv);
        dug.accept(pandav);
        String string = dug.getSpecies();
        System.out.println(string);
    }
}
