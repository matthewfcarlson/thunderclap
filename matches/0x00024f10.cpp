extern "C" void _ReadWriteBarrier();
void* __stdcall Get(int);
class Obj {
  public:
    void Run();
};
void FUN_00024f10() {
    Obj* p = (Obj*)Get(1);
    p->Run();
    _ReadWriteBarrier();
}