extern "C" void _ReadWriteBarrier();
extern unsigned char ready;
class Obj {
  public:
    void Init();
};
extern Obj obj;
void __cdecl prep();
void __cdecl stage(int);
int __cdecl first();
void* __cdecl second(int, int);
void* __cdecl FUN_0008d690(int x) {
    if (!ready) {
        prep();
        obj.Init();
        stage(30);
        ready = 1;
    }
    return second(first(), x);
}