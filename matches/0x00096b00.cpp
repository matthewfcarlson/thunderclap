struct Helper_96b00 {
    char pad[8];
    bool Check(void*);
};
struct Obj_96b00 {
    char pad0[8];
    Helper_96b00* helper;
    int state;
    char pad10[0x40];
    int a;
    int b;
    int c;
};
extern "C" void __cdecl FUN_00096b00(void * self, int* out) {
    int n = ((Obj_96b00 *)self)->state;
    --n;
    if (n != 0) {
        out[0] = ((Obj_96b00 *)self)->a;
        out[1] = ((Obj_96b00 *)self)->b;
        out[2] = ((Obj_96b00 *)self)->c;
        return;
    }
    if (!((Obj_96b00 *)self)->helper->Check(out)) {
        out[0] = ((Obj_96b00 *)self)->a;
        out[1] = ((Obj_96b00 *)self)->b;
        out[2] = ((Obj_96b00 *)self)->c;
    }
}