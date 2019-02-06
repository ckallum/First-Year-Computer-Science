class Number {
  int x;

  Number(int x) {
    this.x = x;
  }
}

class CallWorld {

  static int square(Number n) {
    n.x *= n.x;/*These values are called by reference as the object n is
                 referencing to an object and these changes are persistent*/
    return n.x;
  }

  static int square(int x) {
    x *= x;/* This is a call by value, eg the value is copied and will not
              change the actual value. The new value is returned and used*/
    return x;
  }

  public static void main (String[] args) {
    int x = 10;
    System.out.println(square(x));
    System.out.println(x);
    Number n = new Number(10);
    System.out.println(square(n));//Compiler knows which squaremethod to use.
    System.out.println(n.x);
  }
}
