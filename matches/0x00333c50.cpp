class Ref {
public:
    virtual void Release();
    virtual void AddRef();
};
class PlayerBink {
public:
    virtual void f0(); virtual void f1(); virtual void f2();
    virtual void f3(Ref*, Ref*);
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    char pad[0x10-4];
    Ref* a;
    Ref* b;
};
void PlayerBink::f3(Ref* x, Ref* y) {
    if (a != x) {
        Ref* old = a;
        a = x;
        if (x) x->Release();
        if (old) old->AddRef();
    }
    if (b != y) {
        Ref* old = b;
        b = y;
        if (y) y->Release();
        if (old) old->AddRef();
    }
}