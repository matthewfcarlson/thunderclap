struct Callee_35140 {
    void Run();
};
struct Obj_35140 {
    char pad[0x1d68];
    void Target();
};
void Obj_35140::Target() {
    ((Callee_35140*)((char*)this + 0x1d68))->Run();
}