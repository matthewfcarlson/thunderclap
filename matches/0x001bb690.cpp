void* operator new(unsigned int) throw();
struct Info_1bb690 {};
extern Info_1bb690 gInfo;
char GetFlag(Info_1bb690*) throw();
struct Function_1bb690 {
    Function_1bb690(void* h, int z) throw();
    virtual void Run();
    char pad[0x14];
};
struct Method0_1bb690 : Function_1bb690 {
    char f;
    int a;
    int b;
    Method0_1bb690(void* h, int y, int x) throw() : Function_1bb690(h, 0) {
        a = y;
        f = GetFlag(&gInfo);
        b = x;
    }
};
struct Closure0_1bb690 : Method0_1bb690 {
    virtual void Run();
    Closure0_1bb690(void* h, int y, int x) throw() : Method0_1bb690(h, y, x) {}
};
struct Owner_1bb690 {
    void Make(void* h, int x, int y);
    void Reg(void* h, Method0_1bb690* c);
};
void Owner_1bb690::Make(void* h, int x, int y) {
    Closure0_1bb690* c = new Closure0_1bb690(h, y, x);
    Reg(h, c);
}