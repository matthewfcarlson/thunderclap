class Base_1d82a0 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_1d82a0 {
  public:
    char pad[0x21c];
    Base_1d82a0* ptr;
    void Do();
};
void __fastcall target(Obj_1d82a0* self) {
    self->Do();
    if (self->ptr) {
        self->ptr->B();
        self->ptr = 0;
    }
}