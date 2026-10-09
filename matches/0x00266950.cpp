class Ref {
  public:
    virtual void A();
    virtual void B();
};
int Make();
class Obj {
  public:
    char pad0[12];
    int a;
    int b;
    int mode;
    char pad18[4];
    Ref* ref;
    void F(int mode);
};
void Obj::F(int mode) {
    switch (mode) {
    case 2:
        a = Make();
        break;
    case 3:
        b = Make();
        if (ref)
            ref->B();
        ref = 0;
        break;
    }
    this->mode = mode;
}