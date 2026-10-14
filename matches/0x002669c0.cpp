class Inner_2669c0 {
  public:
    virtual void f();
    virtual void g();
};
class Outer_2669c0 {
  public:
    char pad[0x284];
    Inner_2669c0* p;
};
void __fastcall target(Outer_2669c0* self) {
    self->p->g();
}