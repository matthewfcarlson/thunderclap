extern "C" int __stdcall FUN_0020e1a1(int, int, int);
extern "C" int __stdcall FUN_0020d7ff(int, int, int);
struct Global {
    char pad[0x28];
    int field28;
    char pad2[4];
    int field30;
};
extern Global* DAT_004e5ce0;
int __cdecl target(int param) {
    int result = FUN_0020e1a1(DAT_004e5ce0->field28, 0, param);
    if (result) {
        int value = FUN_0020d7ff(DAT_004e5ce0->field28, 0, result);
        DAT_004e5ce0->field30 += value;
    }
    return result;
}