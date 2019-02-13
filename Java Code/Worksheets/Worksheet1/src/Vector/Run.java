class Run{
    public static void main(String[] args){
/*
        Critter critter = new Critter("Cow");
        Critter critter2 = new Critter("grass");
        critter.poke();
        critter.eat(critter2);
*/
// -------------------------------------------

        Vector2D a = new Vector2D(10.0, 10.0);
        Vector2D b = new Vector2D(12.0,13.0);
        Vector2D c = a.midpoint(b);
        System.out.println(c.toString());

//--------------------------------------------
        // double x = new Vector2D(10.0, 10.0)
        //         .add(new Vector2D(5.0, 5.0))
        //         .midpoint(new Vector2D(5.0, 5.0))
        //         .scale(3)
        //         .dotProduct(new Vector2D(5.0, 5.0));
        // System.out.println(x);
    }
}