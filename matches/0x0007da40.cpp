struct Pair {
    int a;
    int b;
};
struct Obj {
    int first(int, int);
    void second(int);
    void target(Pair*);
};
void Obj::target(Pair* p) {
    int i = first(p->a, p->b);
    if (i != -1)
        second(i);
}