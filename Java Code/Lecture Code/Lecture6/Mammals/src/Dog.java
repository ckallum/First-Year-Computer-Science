public class Dog extends Mammal {

        String species = "Dog";
        @Override
        String getSpecies(){
            return this.species;
        }

        @Override
        void accept(Visitor v) {
            v.visit(this);
        }

}
