class Sub { public: void Init(); };
class CNameFlagConditionBase {
public:
    int m0;
    char pad[8];
    int mC;
    Sub sub;
    CNameFlagConditionBase();
};
extern void __stdcall FUN_00234590(int);
CNameFlagConditionBase::CNameFlagConditionBase() {
    FUN_00234590(0);
    m0 = 0x3f7010;
    mC = 0;
    sub.Init();
}