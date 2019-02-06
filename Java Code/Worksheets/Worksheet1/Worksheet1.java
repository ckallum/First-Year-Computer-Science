//1.1a)Boolen determining function key states, control keys etc.
//1.1b)All function keys, macro's etc.
//1.2a)public = The class is shared can be seen outside the class. eg the Hello World class and main method can be accessed by all other classes
//1.2b)This is so the JVM instantiates/calls the main method during run time first without instantiating any objects.Static means that an object doesn't have to be instantiated eg, a pure function
//1.3)
class Critter{
    private String name;

    Critter(String var){
        this.name = var;
    }

    void poke() {
        System.out.println(this.name + " was poked");
    }

    void eat(Critter c){
        System.out.println(this.name + " ate " + c.name);
    }
}


class Vector2D{
    final double x;
    final double y;

    Vector2D(double var1, double var2){
        this.x = var1;
        this.y = var2;
    }

    double distance(Vector2D v){
        return java.lang.Math.sqrt((this.x-v.x)*(this.x-v.x)  + (this.y-v.y)*(this.y-v.y));
    }

    double magnitude(){
        return java.lang.Math.sqrt(this.x*this.x + this.y*this.y);
    }

    Vector2D add(Vector2D v) {
        Vector2D vector = new Vector2D(this.x + v.x, this.y + v.y);
        return vector;
    }

    Vector2D scale(double f){
        Vector2D vector = new Vector2D(this.x * f, this.y * f);
        return vector;
    }

    Vector2D midpoint(Vector2D v){
        Vector2D vector = new Vector2D((this.x+v.x)/2, (this.y+v.y)/2);
        return vector;
    }

    double dotProduct(Vector2D v){
        return this.x * v.x + this.y + v.y;
    }

    @Override
    public String toString(){
        String string = "Vector2D("+ this.x +", " + this.y+")";
        return string;
    }


}

public class Worksheet1{
    public static void main(String[] args){
/*
        Critter critter = new Critter("Cow");
        Critter critter2 = new Critter("grass");
        critter.poke();
        critter.eat(critter2);
*/
// -------------------------------------------
/*
        Vector2D a = new Vector2D(10.0, 10.0);
        Vector2D b = new Vector2D(12.0,13.0);
        Vector2D c = a.midpoint(b);
        System.out.println(c.toString());
*/
//--------------------------------------------
        double x = new Vector2D(10.0, 10.0)
                .add(new Vector2D(5.0, 5.0))
                .midpoint(new Vector2D(5.0, 5.0))
                .scale(3)
                .dotProduct(new Vector2D(5.0, 5.0));
        System.out.println(x);
    }
}

//1.4a)A class is a container containing attributes and methods of a certain object. An object apart of a certain class is an instantiation of that class
//1.4b)Primitives types only store raw values, a value of that primitive type isn't an object as it doesn't have methods and individual methods eg. it doesn't have a class hierarchy/superclass - independent. The value is stored by value. not by reference and it is stored directly on the stack.
//1.4c)Null is a value that can be assigned to any data type that is non-primitive. It means a variable does not reference to any object or array. Objects references can't be null. These are used for class instance variables and array components.



