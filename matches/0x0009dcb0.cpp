void* operator new(unsigned int) throw();
struct Function_9dcb0 {
    Function_9dcb0(int a, int b) throw();
    virtual void f();
    char pad[0x14];
};
struct Method0_9dcb0 : Function_9dcb0 {
    Method0_9dcb0(int id, int a, int b) throw();
    virtual void h();
    char c;
    int a;
    int b;
};
struct Closure0_9dcb0 : Method0_9dcb0 {
    Closure0_9dcb0(int id, int a, int b) throw();
    virtual void h();
};
extern char gg[];
char GetFlag(void*) throw();
struct Owner_9dcb0 {
    void Set(int, Closure0_9dcb0*) throw();
    void Make(int id, int a, int b) throw();
};
Method0_9dcb0::Method0_9dcb0(int id, int x, int y) throw() : Function_9dcb0(id, 0) {
    this->a = y;
    c = GetFlag(gg);
    b = x;
}
Closure0_9dcb0::Closure0_9dcb0(int id, int x, int y) throw() : Method0_9dcb0(id, x, y) {}
void Method0_9dcb0::h() {}
void Closure0_9dcb0::h() {}
void Owner_9dcb0::Make(int id, int a, int b) throw() {
    Closure0_9dcb0* p = new Closure0_9dcb0(id, a, b);
    Set(id, p);
}
