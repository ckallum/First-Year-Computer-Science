public class Gold extends Card{
    String name = "Gold Card";
    @Override
    String getName(){
        return this.name;
    }

    @Override
    void accept(Visitor v){
        v.visitGold(this);
    }

}
