struct Node {
    char pad[0x108];
    int a;
    int b;
};
class Manager_4a8a0 {
  public:
    Node* First();
};
class Helper_4a8a0 {
  public:
    Node* Get();
};
class CFightNodePrevCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual bool vfunc_7(void* arg);
    char p4[8];
    int mMode;
    int mValue;
    char p14[8];
    unsigned char mFlag;
};
bool CFightNodePrevCondition::vfunc_7(void* arg) {
    Manager_4a8a0* m = (Manager_4a8a0*)arg;
    Node* n = m->First();
    Node* r = ((Helper_4a8a0*)n)->Get();
    int x = r->a;
    if (mFlag == 0)
        x = r->b;
    int y = mValue;
    switch (mMode) {
    case 0:
        return x == y;
    case 1:
        return x != y;
    }
    return false;
}
