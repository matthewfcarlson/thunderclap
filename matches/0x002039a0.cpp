struct RandState_2039a0 {
    unsigned int a;
    unsigned int b;
};
extern RandState_2039a0* __cdecl FUN_000964d0();
class Obj_2039a0 {
  public:
    void Set(int);
    void FUN_002039a0(int, int);
};
void Obj_2039a0::FUN_002039a0(int lo, int hi) {
    RandState_2039a0* p = FUN_000964d0();
    unsigned int* pa = &p->a;
    unsigned int* pb = &p->b;
    *pa = (*pa & 0xffff) * 0x9069 + (*pa >> 16);
    *pb = (*pb & 0xffff) * 0x4650 + (*pb >> 16);
    unsigned int value = (*pa << 16) + (*pb & 0xffff);
    Set(value % (hi - lo + 1) + lo);
}