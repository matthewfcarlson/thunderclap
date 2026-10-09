class Ref {
  public:
    virtual void F0();
    virtual void F1();
};
class BillboardQuadGroup {
  public:
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual void F6();
    virtual void F7();
    virtual void F8(Ref*);
    virtual void F9();
    virtual void F10();
    virtual void F11();
    char p0[12];
    int active;
    char p1[0x70];
    Ref* current;
};
void BillboardQuadGroup::F8(Ref* value) {
    if (value)
        value->F0();
    if (current)
        current->F1();
    current = value;
    if (value) {
        int type = *(int*)((char*)value + 0x18);
        if (type == 1 || type == 3 || type == 7 || type == 2 || type == 4 || type == 5 || type == 6) {
            active = 1;
            return;
        }
    }
    active = 0;
}