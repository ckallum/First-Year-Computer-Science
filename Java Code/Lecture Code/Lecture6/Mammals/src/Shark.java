public class Shark extends Mammal {
    String species = "Shark";
    @Override
    String getSpecies(){
        return this.species;
    }

    @Override
    void accept(Visitor v) {
        v.visit(this);
    }
}
