extern "C" char DAT_00431968[];
class PhysicsThing {
  public:
    int a[4];
    int b;
    unsigned char c;
};
struct ThisCall_0027b070 {
    void BaseCtor();
};
PhysicsThing* __fastcall Target(PhysicsThing* self) {
    ((ThisCall_0027b070*)(self))->BaseCtor();
    *(int*)self = ((int)DAT_00431968);
    self->b = 0;
    self->c = 1;
    return self;
}