extern "C" void __cdecl thunk_FUN_00267090(void*);
void __cdecl operator delete(void* p);
struct Obj_104b20 {
  public:
    void* field0;
    char pad[8];
    void* fieldC;
    void* func(unsigned char b);
};
void* Obj_104b20::func(unsigned char b) {
    thunk_FUN_00267090(field0);
    thunk_FUN_00267090(fieldC);
    if (b & 1) {
        operator delete(this);
    }
    return this;
}
