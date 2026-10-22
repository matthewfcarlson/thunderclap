class Child_2fe680 {
  public:
    virtual void f0();
    virtual void f1();
};
struct SimulatedObject_2fe680 {
    void Tail();
};
extern int gVtable_2fe680;
class SimulatedObject {
  public:
    void* vftable;
    char pad[0x18];
    Child_2fe680* member;
    void Finish();
};
void SimulatedObject::Finish() {
    vftable = &gVtable_2fe680;
    if (member)
        member->f1();
    ((SimulatedObject_2fe680*)this)->Tail();
}