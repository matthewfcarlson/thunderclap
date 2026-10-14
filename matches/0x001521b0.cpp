// Same code shape as 0x00135700 (propagated; names are from that function)
struct P8 {
    int Get();
    void Set(int);
};
struct Tail_1521b0 {
    char pad[0x12c];
    int field;
};
struct Mid_1521b0 {
    Tail_1521b0* GetTail();
};
struct Obj_1521b0 {
    Mid_1521b0* GetMid();
};
struct Inner_1521b0 {
    virtual void f0();
    virtual void f1();
    int pad;
    P8* p8;
    int kind;
};
class Target_1521b0 {
  public:
    char pad[0x20];
    Obj_1521b0* mA;
    int spare;
    Inner_1521b0* mItem;
    void Run();
};
void Target_1521b0::Run() {
    if (mItem != 0 && mItem->kind == 1) {
        Tail_1521b0* t = mA->GetMid()->GetTail();
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
