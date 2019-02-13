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




//1.4a)A class is a container containing attributes and methods of a certain object. An object apart of a certain class is an instantiation of that class
//1.4b)Primitives types only store raw values, a value of that primitive type isn't an object as it doesn't have methods and individual methods eg. it doesn't have a class hierarchy/superclass - independent. The value is stored by value. not by reference and it is stored directly on the stack.
//1.4c)Null is a value that can be assigned to any data type that is non-primitive. It means a variable does not reference to any object or array. Objects references can't be null. These are used for class instance variables and array components.
