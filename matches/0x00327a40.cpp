class pddiShader_327a40 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class Handler_327a40 {
  public:
    void h(int);
};
typedef void (Handler_327a40::*HFn)(int);
struct Entry_327a40 {
    int key;
    int a;
    HFn fn;
    int off;
    int p1;
    int p2;
};
class pddiBaseShader_327a40 : public pddiShader_327a40 {
  public:
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool f6(int, int);
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual Entry_327a40* f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    char pad[8];
    int member;
};
extern int counter;
bool pddiBaseShader_327a40::f6(int key, int arg) {
    Entry_327a40* e = f16();
    if (e && e->key) {
        do {
            if (e->key == key) {
                Handler_327a40* h = (Handler_327a40*)((char*)this + e->off);
                (h->*(e->fn))(arg);
                ++counter;
                if (counter == -1)
                    counter = 0;
                member = counter;
                ++counter;
                return true;
            }
            e = (Entry_327a40*)((char*)e + 24);
        } while (e->key);
    }
    return false;
}
