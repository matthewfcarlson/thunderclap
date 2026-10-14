class Ref_af510 {
  public:
    virtual void f0();
    virtual void f1();
};
class Obj_af510 {
    char pad[0x2c];
    Ref_af510* ref;

  public:
    void clear();
};
void Obj_af510::clear() {
    if (ref) {
        ref->f1();
        ref = 0;
    }
}