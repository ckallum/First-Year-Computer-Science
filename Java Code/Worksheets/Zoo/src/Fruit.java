public class Fruit extends Food {

  @Override
  public String eaten(Dog dog){
    String string = "dog eats fruit";
    return string;
  }

  @Override
  public String eaten(Animal animal){
    String string = "animal eats fruit";
    return string;
  }

  @Override
  public String eaten(Cat cat){
    String string = "cat eats fruit";
    return string;
  }

}
