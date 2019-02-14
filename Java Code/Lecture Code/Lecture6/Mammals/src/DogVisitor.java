public class DogVisitor extends Visitor{
    @Override
    void visit(Dog d){
        System.out.println("Dog's love me");
    }

    @Override
    void visit(Panda p){
        System.out.println("Panda's are stupid");
    }

    @Override
    void visit(Shark s){
        System.out.println("Not quite my expertise");
    }
}
