extern "C" char DAT_00429440[];
extern "C" char DAT_004e6330[];
extern "C" char DAT_004e6338[];
extern void __stdcall FUN_002584d0(void*, void*, void*, int);
class X_24d6b0 {
  public:
    int m;
    X_24d6b0();
};
X_24d6b0::X_24d6b0() {
    FUN_002584d0((void*)((int)DAT_004e6338), (void*)((int)DAT_004e6330), (void*)0x30, 4);
    m = ((int)DAT_00429440);
}