public class Dolphin extends Mammal{
    @Override
    public void makeNoise() {
        System.out.println("squeek click");
    }
    public void makeNoise(Mammal m) {
       m.makeNoiseDolphin();
    }
    @Override
    public void makeNoiseDog() {
        System.out.println("Dolphin interacting with dog");
    }
    @Override
    public void makeNoiseDolphin() {
        System.out.println("Dolphin interacting with dolphin");
    }
    @Override
    public void makeNoiseLion() {
        System.out.println("Dolphin interacting with lion");
    }
}
