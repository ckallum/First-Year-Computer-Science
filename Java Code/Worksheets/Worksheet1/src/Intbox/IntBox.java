package Intbox;

public class IntBox{
    int x;

    IntBox(int x) {
        this.x = x;
    }

    IntBox(IntBox v){
        this.x = v.x;
    }


    IntBox add(int v){
        this.x += v;
        return this;
    }

    IntBox subtract(int v) {
        this.x -=v;
        return this;
    }

    IntBox scale(int v){
        this.x *= v;
        return this;
    }

    @Override
    public String toString(){
        String string = "Intbox.IntBox("+this.x+")";
        return string;
    }
}



