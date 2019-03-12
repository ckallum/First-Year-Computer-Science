import java.util.Iterator;
import java.util.Set;

class ArraySet<X> implements Set<X>, Iterable<X> {
    private X values[];
    private int size = 0;

    @Override
    public int size() {
        return 0;
    }

    @Override
    public boolean isEmpty() {
        return false;
    }

    @Override
    public boolean contains(Object o) {
        return false;
    }

    @Override
    public Object[] toArray() {
        return new Object[0];
    }

    @Override
    public Iterator<X> iterator() {
        return new Iterator<X>() {
            private int index = 0;
            public X next () {
                X x = values[index];
                index = index + 1;
                return x;
            }
            public boolean hasNext() {
                return (index < size);
            }
        };
    }
}
