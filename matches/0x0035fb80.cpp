class Thing {
  public:
    int get();
};
extern Thing gThing;
extern "C" __int64 __cdecl calc(int, int, int);
extern __int64 gResult;
extern "C" void _ReadWriteBarrier();
void target() {
    int x = gThing.get();
    _ReadWriteBarrier();
    gResult = calc(x, 0, 0);
}