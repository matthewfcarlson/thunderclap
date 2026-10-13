extern "C" char DAT_003f6d50[];
extern "C" void _ReadWriteBarrier();
class Obj {
  public:
    void* vptr;
    void BaseF();
};
void __fastcall FUN_000486e0(Obj* p) {
    p->vptr = (void*)DAT_003f6d50;
    _ReadWriteBarrier();
    p->BaseF();
}
