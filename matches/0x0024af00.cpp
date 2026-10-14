typedef unsigned int uint;
struct Obj_24af00 {
    void Clean();
};
extern void __cdecl FUN_00247550(void*, void*);
extern char DAT_004e5fa8;
void __cdecl FUN_0024af00(Obj_24af00* param_1) {
    if (param_1) {
        param_1->Clean();
        FUN_00247550(&DAT_004e5fa8, param_1);
    }
}