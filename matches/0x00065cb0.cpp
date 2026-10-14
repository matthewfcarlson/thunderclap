struct Pair_65cb0 {
    int a, b;
};
class Obj_65cb0 {
    char pad[0x170];
    volatile Pair_65cb0 entries[40];
    int count;

  public:
    void Add(const volatile Pair_65cb0* p);
};
void Obj_65cb0::Add(const volatile Pair_65cb0* p) {
    int n = count;
    int i = 0;
    if (n > 0) {
        volatile Pair_65cb0* e = entries;
        do {
            if (e->a == p->a && e->b == p->b)
                return;
            ++i;
            ++e;
        } while (i < *(volatile int*)&count);
    }
    if (n < 40) {
        entries[n].a = p->a;
        entries[n].b = p->b;
        ++count;
    }
}