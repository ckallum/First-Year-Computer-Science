public class PandaVisitor extends Visitor{
    @Override
    void visit(Dog d){
        System.out.println("Dog's are ok");
    }

    @Override
    void visit(Panda p){
        System.out.println("Panda's love me");
    }

    @Override
    void visit(Shark s){
        System.out.println("SHARKPANDA");
    }
}
