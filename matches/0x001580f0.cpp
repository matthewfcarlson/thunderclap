extern "C" char DAT_00415024[];
class B {
  public:
    void Fn(void*);
};
extern "C" void* FUN_002343e0(void*, void*);
void FUN_001580f0(B* b, void* a, void* x) {
    void* local;
    *(void**)&local = (void*)((int)DAT_00415024);
    void* p = FUN_002343e0(a, &local);
    b->Fn(p);
}