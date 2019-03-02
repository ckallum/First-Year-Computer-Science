public class TestUtils {

    static void assertEquals(String a, String b){
        try {
            if (a.equals(b)) {
                System.out.println("Equal");
            } else {
                throw (new AssertionError("Expected string: " + a + " but was " + b));
            }

        }
        catch (Exception e){
            System.out.println("Exception:"+ e.getMessage());
        }
    }

    static void assertEquals(int a, int b){
        try {
            if (a==b) {
                System.out.println("Equal");
            } else {
                throw (new AssertionError("Expected int: " + a + " but was " + b));
            }

        }
        catch (Exception e){
            System.out.println("Exception:"+ e.getMessage());
        }
    }

    static void assertUniversalEquals(Object a, Object b){
        try{
            if (a == null && b == null){
                 System.out.println("OK");
            }
            else if(a == null){
                throw (new AssertionError("Expected: null" +  "but got "+b+" ("+b.getClass()+ ")"));

            }
            else if (b == null){
                throw (new AssertionError("Expected:" + a + " ("+a.getClass() + ") but got null"));

            }

            else if (!a.equals(b)){
                throw (new AssertionError("Expected:" + a + " ("+a.getClass() + ") but got "+b+" ("+b.getClass()+ ")"));

            }
        }
        catch (Exception e){
            System.out.println(("Exception:" + e.getMessage()));
        }

    }
}
