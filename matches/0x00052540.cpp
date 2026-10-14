extern "C" char DAT_003f8628[];
typedef unsigned int u32_52540;
extern "C" void* __cdecl thunk_FUN_0008d690(unsigned int);
class Helper_52540 {
  public:
    void Init();
};
class Init2 {
  public:
    void Init(unsigned int);
};
class ConditionFactoryCasterTemplate {
  public:
    void* vfunc_1(unsigned int);
};
void* ConditionFactoryCasterTemplate::vfunc_1(unsigned int arg) {
    void* p = thunk_FUN_0008d690(0x10);
    if (p) {
        ((Helper_52540*)p)->Init();
        *(u32_52540*)p = ((int)DAT_003f8628);
        ((Init2*)((char*)p + 8))->Init(arg);
        return p;
    }
    return 0;
}