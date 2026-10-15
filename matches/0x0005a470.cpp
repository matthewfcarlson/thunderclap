struct Leaf {
    char pad[0x104];
    int value;
};
struct Mid {
    char pad[0x330];
    Leaf* first;
    Leaf* second;
    inline Leaf* select() {
        if (second)
            return second;
        Leaf* p = first;
        if (!p)
            return 0;
        return p;
    }
};
class B {
  public:
    Mid* get();
};
class A {
  public:
    B* get();
};
int __cdecl target(A* a) {
    if (!a)
        return 0;
    B* b = a->get();
    if (!b)
        return 0;
    Mid* m = b->get();
    if (!m)
        return 0;
    Leaf* p = m->select();
    if (!p)
        return 0;
    return p->value;
}