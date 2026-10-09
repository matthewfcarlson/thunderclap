class Obj {
  public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual int f7();
    virtual int f8();
    virtual int f9();
    virtual int f10();
    virtual int f11();
    virtual int f12();
    virtual int f13();
    virtual int f14();
    virtual int f15();
    virtual int f16();
    virtual int f17();
    int pad[2];
    int count;
    int items[1];
    int get(int index);
};
class Helper {
  public:
    int apply(int x);
};
int Obj::get(int index) {
    if (index >= 0 && index < count) {
        Helper* h = (Helper*)*(int*)((int)*(int*)this + 0x44);
        return h->apply(items[index]);
    }
    return 0;
}