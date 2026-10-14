class Ref_1b4f0 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_1b4f0 {
    char pad[0x24];

  public:
    Ref_1b4f0* ref;
    void F();
};
void Obj_1b4f0::F() {
    if (ref) {
        ref->B();
        ref = 0;
    }
}