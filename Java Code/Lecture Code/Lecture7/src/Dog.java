class Dog extends Animal implements Pet{
    @Override
    void noise(){
        System.out.println("Roar");
    }

    @Override
    public void cuddle(){
        System.out.println("Tongue Cuddle");
    }
}
