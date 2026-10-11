extern "C" char DAT_0042886c[];
void __stdcall BaseInit(int);
class Store {
  public:
    void* vptr;
};
Store* __fastcall target(Store* self) {
    BaseInit(2);
    self->vptr = (void*)((int)DAT_0042886c);
    return self;
}
