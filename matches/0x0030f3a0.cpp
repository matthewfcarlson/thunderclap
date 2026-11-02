// Same code shape as 0x00222050 (propagated; names are from that function)
extern "C" void __fastcall FUN_0022b980(void*);
class Obj_30f3a0 {
  public:
    char pad[0x40];
    volatile int a, b, c, d, e;
    Obj_30f3a0();
};
Obj_30f3a0::Obj_30f3a0() {
    FUN_0022b980((void*)(this));
    c = 0;
    b = 0;
    a = 0;
    d = 0x3f800000;
    e = 0;
}