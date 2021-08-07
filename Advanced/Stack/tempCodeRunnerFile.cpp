oid reverse(Stack* st) {
    Stack* h = new Stack();
    reverse_helper(st,h);
    st = h;
    st->display();
}