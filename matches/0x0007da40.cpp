struct Pair_7da40 {
    int a;
    int b;
};
struct Obj_7da40 {
    int first(int, int);
    void second(int);
    void target(Pair_7da40*);
};
void Obj_7da40::target(Pair_7da40* p) {
    int i = first(p->a, p->b);
    if (i != -1)
        second(i);
}