struct Pair {
    int a, b;
};
class Obj {
    char pad[0x170];
    volatile Pair entries[40];
    int count;

  public:
    void Add(const volatile Pair* p);
};
void Obj::Add(const volatile Pair* p) {
    int n = count;
    int i = 0;
    if (n > 0) {
        volatile Pair* e = entries;
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