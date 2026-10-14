struct Obj_240c60 {
    char pad[0x28];
    int value;
};
struct State_240c60 {
    char pad[0x28];
    Obj_240c60* obj;
    int pad2;
    int count;
};
extern State_240c60* gState_240c60;
extern int __stdcall FUN_0020d7ff(Obj_240c60*, int, int);
extern void __stdcall FUN_0020c79c(Obj_240c60*, int, int);
void __cdecl FUN_00240c60(int param_1) {
    if (param_1) {
        int n = FUN_0020d7ff(gState_240c60->obj, 0, param_1);
        gState_240c60->count -= n;
        FUN_0020c79c(gState_240c60->obj, 0, param_1);
    }
}
