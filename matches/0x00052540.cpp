typedef unsigned int u32;
extern "C" void* __cdecl thunk_FUN_0008d690(unsigned int);
class Helper { public: void Init(); };
class Init2 { public: void Init(unsigned int); };
class ConditionFactoryCasterTemplate {
public:
    void* vfunc_1(unsigned int);
};
void* ConditionFactoryCasterTemplate::vfunc_1(unsigned int arg) {
    void* p = thunk_FUN_0008d690(0x10);
    if (p) {
        ((Helper*)p)->Init();
        *(u32*)p = 0x3f8628;
        ((Init2*)((char*)p + 8))->Init(arg);
        return p;
    }
    return 0;
}