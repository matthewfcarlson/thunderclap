struct Callee {
    void Run();
};
struct Obj {
    char pad[0x1d68];
    void Target();
};
void Obj::Target() {
    ((Callee*)((char*)this + 0x1d68))->Run();
}