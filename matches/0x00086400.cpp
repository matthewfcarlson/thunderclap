struct Inner {
    char pad[0x18];
};
struct Mid {
    char pad[0x18];
    Inner* p18;
};
struct Outer {
    char pad[0x54];
    Mid* p54;
};
extern Outer* gGlobal;
struct Final {
    void Run();
};
struct Obj {
    int a;
    char pad[4];
    int c;
    void Run();
};
void Obj::Run() {
    a = c;
    c = 0;
    ((Final*)gGlobal->p54->p18)->Run();
}
