struct Callee_35140 {
    int Run(int);
};
struct Obj_35140 {
    char pad[0x1d68];
    int Target(int);
};
int Obj_35140::Target(int a0) {
    return ((Callee_35140*)((char*)this + 0x1d68))->Run(a0);
}