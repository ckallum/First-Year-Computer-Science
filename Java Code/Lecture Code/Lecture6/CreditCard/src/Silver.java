public class Silver extends Card{
    String name = "Silver Card";
    @Override
    String getName(){
        return this.name;
    }

    @Override
    void accept(Visitor v){
        v.visitSilver(this);
    }

}
