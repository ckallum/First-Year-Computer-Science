public class Panda extends Mammal {
    String species = "Panda";
    @Override
    String getSpecies(){
        return this.species;
    }

    @Override
    void accept(Visitor v) {
        v.visit(this);
    }
}
