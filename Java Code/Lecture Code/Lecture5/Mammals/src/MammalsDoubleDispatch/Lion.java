public class Lion extends Mammal {
    @Override
    public void makeNoise() {
        System.out.println("roar");
    }
    public void makeNoise(Mammal m){
        m.makeNoiseLion();
    }
    @Override
    public void makeNoiseDog() {
        System.out.println("Lion interacting with dog");
    }
    @Override
    public void makeNoiseDolphin() {
        System.out.println("Lion interacting with dolphin");
    }
    @Override
    public void makeNoiseLion() {
        System.out.println("Lion interacting with lion");
    }
}
