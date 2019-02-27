// state: xs : Set X
// init: xs = ∅
interface Set<X> {
    // pre: x ∉ xs
    // post: xs = {x} ∪ xs0
    public void insert(X x);
    // pre: x ∈ xs
    // post: x ∉ xs ∧ xs0 = {x} ∪ xs
    public void delete(X x);
    // post: xs = ∅
    public void empty();
    // post: xs = xs0
    // return: x ∈ xs
    public boolean contains(X x);
    // post: xs = xs0
    // return: |xs|
    public int size();
}