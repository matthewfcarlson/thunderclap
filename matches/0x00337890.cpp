extern "C" char DAT_00434578[];
class Ref_337890 {
  public:
    virtual void F(int);
};
class Obj_337890 {
  public:
    unsigned a;
    unsigned b;
    Ref_337890* member;
    void Go();
};
void Obj_337890::Go() {
    a = ((int)DAT_00434578);
    if (member)
        member->F(1);
}