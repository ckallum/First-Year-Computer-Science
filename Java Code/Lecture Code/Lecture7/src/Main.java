public class Main {
    public static void main(String[] args) {
        Point []ps = new Point[]{
                new Point(0,0),
                new Point(1,1),
                new Point(2,0 ),
        };
        Point []pss = new Point[]{
                new Point(0,0),
                new Point(1,1),
                new Point(2,0 ),
        };
        Polygon p = new Polygon(ps);
        System.out.println(p.getPoints());
        System.out.println(p.getSides());
        p.setPoints(pss);
        System.out.println(p.getPoints());
    }

}
