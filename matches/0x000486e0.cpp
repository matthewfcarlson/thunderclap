extern "C" char DAT_003f6d50[];
extern "C" void _ReadWriteBarrier();
class Obj_486e0 {
  public:
    void* vptr;
    void BaseF();
};
void __fastcall FUN_000486e0(Obj_486e0* p) {
    p->vptr = (void*)DAT_003f6d50;
    _ReadWriteBarrier();
    p->BaseF();
}
