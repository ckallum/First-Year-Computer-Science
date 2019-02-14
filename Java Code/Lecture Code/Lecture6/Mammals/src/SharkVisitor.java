public class SharkVisitor extends Visitor{
    @Override
    void visit(Dog d){
        System.out.println("Dog's suck");
    }

    @Override
    void visit(Panda p){
        System.out.println("Panda's are impractical");
    }

    @Override
    void visit(Shark s){
        System.out.println("SHARKSHARKSHARK");
    }
}
