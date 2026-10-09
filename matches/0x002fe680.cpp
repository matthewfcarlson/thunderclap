class Child {
  public:
    virtual void f0();
    virtual void f1();
};
struct TailTarget {
    void Tail();
};
extern int gVtable;
class SimulatedObject {
  public:
    void* vftable;
    char pad[0x18];
    Child* member;
    void Finish();
};
void SimulatedObject::Finish() {
    vftable = &gVtable;
    if (member)
        member->f1();
    ((TailTarget*)this)->Tail();
}