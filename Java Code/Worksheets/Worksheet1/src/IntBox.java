public class IntBox{
    int x;

    public IntBox(int x) {
        this.x = x;
    }

    IntBox add(int v){
        IntBox newInt = new IntBox(this.x + v);
        return newInt;
    }

    IntBox subtract(int v) {
        IntBox newInt = new IntBox(this.x - v);
        return newInt;
    }

    IntBox scale(int v){
        IntBox newInt = new IntBox(this.x * v);
        return newInt;
    }

    @Override
    public string toString(){
        String string = "IntBox("+this.x+")";

    }
}

