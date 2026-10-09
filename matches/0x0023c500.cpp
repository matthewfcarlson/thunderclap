void __stdcall BaseInit(int);
class Store {
  public:
    void* vptr;
};
Store* __fastcall target(Store* self) {
    BaseInit(2);
    self->vptr = (void*)0x42886c;
    return self;
}
