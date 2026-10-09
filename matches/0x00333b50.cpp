extern "C" void __stdcall FUN_0033eb70(void*, void*);
extern "C" void __cdecl FUN_003351a0(int);
extern "C" int DAT_00555ba0;
extern "C" unsigned char DAT_00555b9c;
extern "C" void __cdecl target(int param_1) {
    FUN_0033eb70((void*)0x3338a0, (void*)0x3338c0);
    DAT_00555ba0 = param_1;
    FUN_003351a0(param_1);
    DAT_00555b9c = 1;
}
