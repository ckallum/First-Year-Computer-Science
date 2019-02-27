import java.util.Arrays;

public class Polygon {
    private Point[] points;

    Polygon(Point[] points) {
        this.points = points;
    }

    String getPoints() {
        return toString();
    }

    @Override
    public String toString() {
        return "Polygon{" +
                "points=" +  points.toString();
    }

    public void setPoints(Point[] points) {
        this.points = points;
    }

    public int getSides() {
        return points.length;
    }
}
