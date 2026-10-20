struct Temp {
    unsigned int FUN_0030f100();
};
struct Obj {
    void* context;
    char data[24];
    unsigned char flag;
    char pad1[3];
    char output[64];
    unsigned int value;
    void FUN_002fd730();
};
Temp* __fastcall FUN_0030edf0(void* context);
void __cdecl FUN_002ef760(void* output, unsigned int result, float scale, unsigned int value, void* data);
void Obj::FUN_002fd730() {
    if (!flag) {
        flag = 1;
        FUN_002ef760(output, FUN_0030edf0(context)->FUN_0030f100(), 1.0f, value, data);
    }
}