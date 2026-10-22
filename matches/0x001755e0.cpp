class Ref {
  public:
    virtual void Add();
    virtual void Release();
};
class Action_1755e0 {
  public:
    virtual void v();
    char pad[24];
    Action_1755e0();
};
class DriftToHulkAction : public Action_1755e0 {
  public:
    int a;
    Ref* p;
    char pad2[12];
    int y;
    char z;
    DriftToHulkAction(int, Ref*);
    virtual void v();
};
DriftToHulkAction::DriftToHulkAction(int n, Ref* b) : Action_1755e0() {
    volatile int* q = &a;
    *q = 0;
    p = 0;
    y = 0;
    z = 0;
    a = n;
    if (b)
        b->Add();
    if (p)
        p->Release();
    p = b;
}