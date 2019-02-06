class Robot {

  String name;
  int numLegs;
  float powerLevel;

  Robot(String name) {
    this.name = name;
    numLegs = 2;
    powerLevel = 2.0f;
  }

  Robot() {
    this("Standard Model");
  }

  void talk(String phrase) {
    if (powerLevel >= 1.0f) {
      System.out.println(name + " says " + phrase);
      powerLevel -= 1.0f;
    } else {
      System.out.println(name + " is too weak to talk.");
    }
  }

  void charge(float amount) {
    System.out.println(name + " charges.");
    powerLevel = powerLevel + amount;
  }
}

abstract class AbstractRobot extends Robot {/*Can't be instantiated, used so
                                              subclasses can have a base to
                                              extend, overide and implement
                                              the abstrace methods eg.
                                              allows common method
                                              implementation among subclasses
                                              (Robots that can greet). Abstract
                                              methods don't have a body(ready
                                              to be overided).
                                              */
  abstract void greet(AbstractRobot other);
  abstract void greet(TranslationRobot other);
  abstract void greet(CarrierRobot other);
}

class TranslationRobot extends AbstractRobot {
  // class has everything that AbstractRobot has implicitly
  String substitute;

  TranslationRobot(String substitute) {
    this.substitute = substitute;
  }

  void translate(String phrase) {
    this.talk(phrase.replaceAll("a", substitute));
  }

  @Override
  void greet(TranslationRobot other) {
    talk("'Hello from a TranslationRobot to another.'");
  }

  @Override
  void greet(CarrierRobot other) {
    talk("'Hello from a CarrierRobot to a TranslationRobot.'");
  }

  @Override
  void greet(AbstractRobot other) {
    other.greet(this);
  }

  @Override
  void charge(float amount) {
    System.out.println(name + " charges double.");
    powerLevel = powerLevel + 2 * amount;
} }

class CarrierRobot extends AbstractRobot {

  @Override
  void greet(TranslationRobot other) {
    talk("'Hello from a TranslationRobot to a CarrierRobot.'");
  }

  @Override
  void greet(CarrierRobot other) {
    talk("'Hello from a CarrierRobot to another.'");
  }

  @Override
  void greet(AbstractRobot other) {
    other.greet(this);
  }

  void carry() {
    System.out.println("Carrying.");
} }

class InheritanceWorld {
  public static void main (String[] args) {
    Robot c3po = new Robot();
    TranslationRobot c4po = new TranslationRobot("e");
    Robot c5po = new TranslationRobot("e");
    c3po.charge(10); //charges normally
    c4po.charge(10); //charges double
    c5po.charge(10); //polymorphism: charges double!
} }

class DispatchWorld {
  public static void main (String[] args) {
	AbstractRobot c3po = new TranslationRobot("e");
	AbstractRobot c4po = new TranslationRobot("o");
	AbstractRobot c5po = new CarrierRobot();
	AbstractRobot c6po = new CarrierRobot();
	c3po.greet(c4po);
	c5po.greet(c4po);
	c4po.greet(c5po);
	c5po.greet(c6po);
} }
