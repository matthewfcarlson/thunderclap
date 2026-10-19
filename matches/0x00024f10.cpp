extern "C" void _ReadWriteBarrier();
void* __stdcall Get();
class Obj {
  public:
    void Run(int);
};
void FUN_00024f10() {
    ((Obj*)Get())->Run(1);
    _ReadWriteBarrier();
}