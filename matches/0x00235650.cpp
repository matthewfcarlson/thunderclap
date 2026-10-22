class ParamValueInventoryEntity_235650 {
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
struct Manager_235650 {
    char pad[12];
    int value;
};
extern Manager_235650* gManager_235650;
class Iter_235650 {
  public:
    int pad[3];
    Iter_235650(int);
    int First();
    int Next();
};
int ParamValueInventoryEntity_235650::f7(int wanted, int limit) {
    if (limit <= 0)
        return 0;
    Manager_235650* m = gManager_235650;
    if (!m)
        return 0;
    int n = 1;
    Iter_235650 it(m->value);
    *(Manager_235650**)((char*)&it + 8) = m;
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
