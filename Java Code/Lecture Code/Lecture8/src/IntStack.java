interface IntStack{
    //state: xs:[Object]
    //init: xs=[]

    //post:xs = x:xs0

    void push(int x);

    //pre: xs != []
    //post xs = xs0
    //return head xs
    int peek();

    //pre xs != []
    //post x:xs = tail xs0
    //return x
    int pop();

    //post: xs = xs0
    //return xs = []
    boolean empty();


}
