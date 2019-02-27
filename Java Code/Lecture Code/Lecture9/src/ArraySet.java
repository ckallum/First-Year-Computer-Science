import java.lang.Iterable;
import java.util.Iterator;
class ArraySet<X> implements Set<X> , Iterable<X> {
    private X[] values;
    private int size;
    private final int N = 100;

    public ArraySet() {
        values = (X[]) new Object[N];
        size = 0;
    }

    @Override
    public void insert(X x) {
        values[size] = x;
        size = size + 1;
    }

    @Override
    public void delete(X x) {
        for (int i = 0; i < size; i = i + 1) {
            if (values[i].equals(x)) {
                values[i] = values[size - 1];
                size = size - 1;
                break;
            }
        }
    }

    @Override
    public void clear() {
        size = 0;
    }

    @Override
    public boolean contains(X x) {
        boolean contains = false;
        for (X value : values) {
            if (value.equals(x)) {
                contains = true;
                break;
            }
        }
        return contains;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public Iterator<X> iterator() {
        return new Iterator<X>() {
            private int index = 0;

            public X next() {
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