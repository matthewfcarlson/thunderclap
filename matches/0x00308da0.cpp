class HairclubPhysicsObject {
  public:
    int vftable;
    char pad4[0x20];
    int field24;
    char pad28[0x1d0];
    int field1f8;
};
extern void BaseCtor();
HairclubPhysicsObject* __fastcall FUN_00308da0(HairclubPhysicsObject* self) {
    BaseCtor();
    self->vftable = 0x431d1c;
    self->field1f8 = 0;
    self->field24 = 2;
    return self;
}