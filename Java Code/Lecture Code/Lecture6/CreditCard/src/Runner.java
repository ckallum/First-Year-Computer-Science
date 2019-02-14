public class Runner {
    public static void main(String[] args) {
        Card a = new BronzeCard();
        Card b = new Silver();
        Card c = new Gold();
        Visitor d = new FuelVisitor();
        Visitor e = new DutyFreeVisitor();
        Visitor f = new ShopVisitor();
        String aname = a.getName();
        a.accept(d);
        b.accept(e);
        System.out.println(aname);

    }
}
