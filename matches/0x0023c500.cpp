extern "C" char DAT_0042886c[];
struct ThisCall_0023c640 {
    void BaseInit(int);
};
class Store {
  public:
    void* vptr;
};
Store* __fastcall target(Store* self) {
    ((ThisCall_0023c640*)(self))->BaseInit(2);
    self->vptr = (void*)((int)DAT_0042886c);
    return self;
}
