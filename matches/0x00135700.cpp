struct P8 {
    int Get();
    void Set(int);
};
struct Tail_135700 {
    char pad[0x12c];
    int field;
};
struct Mid_135700 {
    Tail_135700* GetTail();
};
struct Obj_135700 {
    Mid_135700* GetMid();
};
struct Inner_135700 {
    virtual void f0();
    virtual void f1();
    int pad;
    P8* p8;
    int kind;
};
class FlyingAttackAction_135700 {
  public:
    char pad[0x20];
    Obj_135700* mA;
    int spare;
    Inner_135700* mItem;
    void Run();
};
void FlyingAttackAction_135700::Run() {
    if (mItem != 0 && mItem->kind == 1) {
        Tail_135700* t = mA->GetMid()->GetTail();
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
