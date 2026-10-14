void* operator new(unsigned int) throw();
struct Info_1bb690 {};
extern Info_1bb690 gInfo;
char GetFlag(Info_1bb690*) throw();
struct Root_1bb690 {
    Root_1bb690(void* h, int z) throw();
    virtual void Run();
    char pad[0x14];
};
struct M_1bb690 : Root_1bb690 {
    char f;
    int a;
    int b;
    M_1bb690(void* h, int y, int x) throw() : Root_1bb690(h, 0) {
        a = y;
        f = GetFlag(&gInfo);
        b = x;
    }
};
struct C_1bb690 : M_1bb690 {
    virtual void Run();
    C_1bb690(void* h, int y, int x) throw() : M_1bb690(h, y, x) {}
};
struct Owner_1bb690 {
    void Make(void* h, int x, int y);
    void Reg(void* h, M_1bb690* c);
};
void Owner_1bb690::Make(void* h, int x, int y) {
    C_1bb690* c = new C_1bb690(h, y, x);
    Reg(h, c);
}