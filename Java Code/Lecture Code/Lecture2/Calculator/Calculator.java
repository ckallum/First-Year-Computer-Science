class Adder{
  int sum;
  void add(int summand){
    sum+=summand;
  }
}

class Calculator{
  public static void main(String[] args){
    Adder adder = new Adder();
    try{
      throw (new Exception("This is an exception message."));
    }
    catch(Exception e){
      System.out.println("Exception:" + e.getMessage());
    }
    try{
      for (String arg:args){
        adder.add(Integer.parseInt(arg));
      }
      System.out.println("Sum = " + adder.sum);
    }
    catch (Exception e){
      System.out.println("Something went wrong, but I can hand it!");
    }
  }
}
