struct Inner_86400 {
    char pad[0x18];
};
struct Mid_86400 {
    char pad[0x18];
    Inner_86400* p18;
};
struct Outer_86400 {
    char pad[0x54];
    Mid_86400* p54;
};
extern Outer_86400* gGlobal_86400;
struct Final_86400 {
    void Run();
};
struct Obj_86400 {
    int a;
    char pad[4];
    int c;
    void Run();
};
void Obj_86400::Run() {
    a = c;
    c = 0;
    ((Final_86400*)gGlobal_86400->p54->p18)->Run();
}
