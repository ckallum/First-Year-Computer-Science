class IntBox{
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
        String string = "IntBox("+this.x+")";
        return string;
    }
}

class Run {
    public static void main(String[] args) {
        IntBox a = new IntBox(10).add(10);
        System.out.println(a.toString());
        System.out.println(a.scale(10).toString());
        System.out.println(a.toString());
        IntBox b = new IntBox(a);
        System.out.println(b.toString());
    }
}


