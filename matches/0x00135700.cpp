struct P8 {
    int Get();
    void Set(int);
};
struct Tail {
    char pad[0x12c];
    int field;
};
struct Mid {
    Tail* GetTail();
};
struct Obj {
    Mid* GetMid();
};
struct Inner {
    virtual void f0();
    virtual void f1();
    int pad;
    P8* p8;
    int kind;
};
class Target {
  public:
    char pad[0x20];
    Obj* mA;
    int spare;
    Inner* mItem;
    void Run();
};
void Target::Run() {
    if (mItem != 0 && mItem->kind == 1) {
        Tail* t = mA->GetMid()->GetTail();
        P8* p = mItem->p8;
        if (p != 0) {
            int v = t->field;
            if (p->Get() == v)
                p->Set(0);
        }
    }
    if (mItem != 0) {
        mItem->f1();
        mItem = 0;
    }
}
