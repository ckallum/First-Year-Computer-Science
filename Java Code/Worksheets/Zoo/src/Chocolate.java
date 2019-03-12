public class Chocolate extends Food {

  @Override
  public String eaten(Dog dog){
    String string = "dog eats chocolate";
    return string;
  }

  @Override
  public String eaten(Animal animal){
    String string = "animal eats chocolate";
    return string;
  }

  @Override
  public String eaten(Cat cat){
    String string = "cat eats chocolate";
    return string;
  }


}
