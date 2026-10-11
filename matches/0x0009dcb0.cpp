void* operator new(unsigned int) throw();
struct Base {
    Base(int a, int b) throw();
    virtual void f();
    char pad[0x14];
};
struct Mth : Base {
    Mth(int id, int a, int b) throw();
    virtual void h();
    char c;
    int a;
    int b;
};
struct Clo : Mth {
    Clo(int id, int a, int b) throw();
    virtual void h();
};
extern char gg[];
char GetFlag(void*) throw();
struct Owner {
    void Set(int, Clo*) throw();
    void Make(int id, int a, int b) throw();
};
Mth::Mth(int id, int x, int y) throw() : Base(id, 0) {
    this->a = y;
    c = GetFlag(gg);
    b = x;
}
Clo::Clo(int id, int x, int y) throw() : Mth(id, x, y) {}
void Mth::h() {}
void Clo::h() {}
void Owner::Make(int id, int a, int b) throw() {
    Clo* p = new Clo(id, a, b);
    Set(id, p);
}
