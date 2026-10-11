class Base {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual char f6(int, int);
    virtual int f7(int, int);
};
struct Manager {
    char pad[12];
    int value;
};
extern Manager* gManager;
class Iter {
  public:
    int pad[3];
    Iter(int);
    int First();
    int Next();
};
int Base::f7(int wanted, int limit) {
    if (limit <= 0)
        return 0;
    Manager* m = gManager;
    if (!m)
        return 0;
    int n = 1;
    Iter it(m->value);
    *(Manager**)((char*)&it + 8) = m;
    int item = it.First();
    while (item) {
        if (f6(wanted, item)) {
            if (limit == n)
                return item;
            ++n;
        }
        item = it.Next();
    }
    return 0;
}
