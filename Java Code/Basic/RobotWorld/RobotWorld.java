class Robot {
  private String name;
  private int numlegs;
  private float powerLevel;

  Robot(String productName){
    name = productName;
    numlegs = 2;
    powerLevel = 2.0f;
  }

  void talk(String phrase){
    if (powerLevel>=1.0f){
      System.out.println(name+ " says " + phrase);
      powerLevel =- 1.0f;
    }
    else {
      System.out.println(name+" is too weak to talk");
    }
  }

  void charge(float amount){
    System.out.println(name + " is chargin");
    powerLevel+=amount;
  }
}

class RobotWorld{
  public static void main(String[] args){
    Robot c3po = new Robot("C3PO");
    for (String arg : args){
      c3po.charge(Float.parseFloat(arg));
    }
    c3po.talk("Hello!");
  }
}
