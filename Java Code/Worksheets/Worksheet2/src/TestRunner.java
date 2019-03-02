public class TestRunner {
    public static void main(String[] args) {
        String a = new String("ab");
        String b = new String("ab");
        int aa = new Integer(34);
        int bb = new Integer(34);
//        TestUtils.assertEquals(a ,b);
//        TestUtils.assertEquals(aa,bb);
//        TestUtils.assertUniversalEquals(1, 2);
//        TestUtils.assertUniversalEquals("1", "2");
//        TestUtils.assertUniversalEquals(a,b);
//        TestUtils.assertUniversalEquals("1", null);
        TestUtils.assertUniversalEquals(1, "1");
//        TestUtils.assertUniversalEquals(null, null);
    }
}
