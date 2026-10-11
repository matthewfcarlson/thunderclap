extern "C" char DAT_00434578[];
class Ref {
  public:
    virtual void F(int);
};
class Obj {
  public:
    unsigned a;
    unsigned b;
    Ref* member;
    void Go();
};
void Obj::Go() {
    a = ((int)DAT_00434578);
    if (member)
        member->F(1);
}