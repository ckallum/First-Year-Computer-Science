public class BronzeCard extends Card {

    String name = "Bronze Card";
    @Override
    String getName(){
        return this.name;
    }

    @Override
    void accept(Visitor v){
        v.visitBronze(this);
    }

}
