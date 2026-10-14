// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0033dca0 @ 0x0033dca0
extern int __cdecl FUN_00212f70(void*, int);
extern int __cdecl FUN_00213120(void*, int);
extern void __cdecl FUN_00212d80(void*, int);
extern void __cdecl FUN_002133d0(void*, const char*);
extern const char* DAT_004350b4[];
extern int DAT_004350a4[];
extern const char* __cdecl FUN_00339e60(void*, int, const char*, int);
extern int __cdecl FUN_00338e50(const char*, const char**);
extern int __cdecl FUN_00339fe0(void*, int, int);
extern void __cdecl FUN_00339c30(void*, int, const char*);
extern int __cdecl FUN_00213ba0(void*, int, int);
extern void __cdecl FUN_00213360(void*, int);
int __cdecl FUN_0033dca0(void* state) {
    if (FUN_00212f70(state, 1)) {
        int value = FUN_00213120(state, 1);
        FUN_00212d80(state, 0);
        const char* option;
        if (value == 0) option = "collect";
        else if (value >= 10000) option = "stop";
        else option = "restart";
        FUN_002133d0(state, option);
    }
    const char* option = FUN_00339e60(state, 1, "collect", 0);
    int index = FUN_00338e50(option, DAT_004350b4);
    int value = FUN_00339fe0(state, 2, 0);
    if (index < 0) FUN_00339c30(state, 1, "invalid option");
    int result = FUN_00213ba0(state, DAT_004350a4[index], value);
    FUN_00213360(state, result);
    return 1;
}
