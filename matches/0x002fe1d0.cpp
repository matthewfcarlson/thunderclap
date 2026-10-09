class PhysicsThing {
  public:
    int a[4];
    int b;
    unsigned char c;
};
extern void BaseCtor();
PhysicsThing* __fastcall Target(PhysicsThing* self) {
    BaseCtor();
    *(int*)self = 0x431968;
    self->b = 0;
    self->c = 1;
    return self;
}