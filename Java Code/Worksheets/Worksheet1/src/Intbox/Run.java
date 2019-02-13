public class Run {
    public static void main(String[] args) {
        IntBox a = new IntBox(10).add(10);
        System.out.println(a.toString());
        System.out.println(a.scale(10).toString());
        System.out.println(a.toString());
        IntBox b = new IntBox(a);
        System.out.println(b.toString());
    }
}