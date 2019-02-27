public class Point {
    final int x;
    final int y;
    Point(int x, int y){
        this.x = x;
        this.y = y;
    }

    public Point move(int dx, int dy){
        return(new Point(x+dx, y+dy));
    }

    @Override
    public String toString() {
        return "Point{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }
}
