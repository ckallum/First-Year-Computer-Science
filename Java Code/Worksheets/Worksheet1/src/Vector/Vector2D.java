public class Vector2D{
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