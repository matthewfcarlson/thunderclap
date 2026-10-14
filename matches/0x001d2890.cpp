typedef unsigned int U_1d2890;
extern "C" {
void __cdecl FUN_00213380(void*, const char*, int);
void __cdecl FUN_00213600(void*, int);
void __cdecl FUN_002133d0(void*, const char*);
void __cdecl FUN_00339a60(void*, U_1d2890, U_1d2890, const char*);
int __cdecl FUN_002139f0(void*, int, int, int);
void __cdecl FUN_00213190(void*, int);
void __cdecl FUN_00212d80(void*, int);
int __cdecl FUN_00213290(void*, int);
void __cdecl FUN_00212e20(void*, int);
void __cdecl FUN_00213870(void*, int, U_1d2890);
extern const char* DAT_004c5cf8;
}
struct Object {
    char pad[8];
    void* state;
    char pad2[0x546c - 12];
    U_1d2890 counter;
    U_1d2890 run(U_1d2890 a, U_1d2890 b, U_1d2890 c);
};
U_1d2890 Object::run(U_1d2890 a, U_1d2890 b, U_1d2890 c) {
    FUN_00213380(state, "coroutine", 9);
    FUN_00213600(state, -10001);
    FUN_002133d0(state, "create");
    FUN_00213600(state, -2);
    FUN_00339a60(state, a, b, "anon_coroutine");
    if (FUN_002139f0(state, 1, 1, 0)) {
        FUN_00213190(state, -1);
        FUN_00212d80(state, 0);
        return 0;
    }
    if (!FUN_00213290(state, -1)) {
        FUN_00212d80(state, 0);
        return 0;
    }
    FUN_002133d0(state, DAT_004c5cf8);
    FUN_00213600(state, -10000);
    FUN_00212e20(state, -2);
    ++counter;
    if (!counter)
        counter = 1;
    U_1d2890 result = counter;
    FUN_00213870(state, -2, result);
    FUN_00212d80(state, -3);
    return result;
}
