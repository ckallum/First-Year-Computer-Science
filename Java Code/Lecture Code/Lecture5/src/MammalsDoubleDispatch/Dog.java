public class Dog extends Mammal {
    @Override
    public void makeNoise() {
        System.out.println("woof");
    }

    public void makeNoise(Mammal m){
        m.makeNoiseDog();
    }
    @Override
    public void makeNoiseDog() {
        System.out.println("Dog interacting with dog");
    }
    @Override
    public void makeNoiseDolphin() {
        System.out.println("Dog interacting with dolphin");
    }
    @Override
    public void makeNoiseLion() {
        System.out.println("Dog interacting with lion");
    }
}
