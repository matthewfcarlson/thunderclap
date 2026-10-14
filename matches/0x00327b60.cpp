class Target_327b60 {
  public:
    void m(int);
};
struct Entry_327b60 {
    int key;
    int p1;
    void (Target_327b60::*fn)(int);
    int off;
    int pad1;
    int pad2;
};
class pddiBaseShader {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual bool f9(int, int);
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual Entry_327b60* f19();
    virtual void f20();
    int pad;
    int pad2;
    int id;
};
extern int counter;
bool pddiBaseShader::f9(int key, int arg) {
    Entry_327b60* e = f19();
    if (e) {
        while (e->key) {
            if (e->key == key) {
                Target_327b60* o = (Target_327b60*)((char*)this + e->off);
                (o->*e->fn)(arg);
                ++counter;
                if (counter == -1)
                    counter = 0;
                id = counter;
                ++counter;
                return true;
            }
            e = (Entry_327b60*)((char*)e + 24);
        }
    }
    return false;
}
