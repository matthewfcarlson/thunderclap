extern void* vA[];
void* __cdecl FUN_0008d6d0(unsigned n) throw();
struct Buf_30e480 {
    char* a;
    char* b;
    char* c;
    int pad;
    Buf_30e480() throw() : a(0), b(0), c(0) {}
};
struct Base_30e480 {
    void* vptr;
    Base_30e480() throw() { vptr = vA; }
};
class O_30e480 : public Base_30e480 {
  public:
    int m4, m8, mc;
    char c10;
    Buf_30e480 b0, b1, b2, b3;
    O_30e480() throw();
};
O_30e480::O_30e480() throw() {
    m8 = 0;
    m4 = 0x14;
    mc = 0;
    c10 = 0;
    char* p = (char*)FUN_0008d6d0(0x28000);
    b0.a = p;
    if (p) {
        b0.b = p;
        b0.c = p + 0x28000;
    } else {
        b0.b = 0;
        b0.c = 0;
    }
    p = (char*)FUN_0008d6d0(0x8000);
    b1.a = p;
    if (p) {
        b1.b = p;
        b1.c = p + 0x8000;
    } else {
        b1.b = 0;
        b1.c = 0;
    }
    p = (char*)FUN_0008d6d0(0x148000);
    b2.a = p;
    if (p) {
        b2.b = p;
        b2.c = p + 0x148000;
    } else {
        b2.b = 0;
        b2.c = 0;
    }
    p = (char*)FUN_0008d6d0(0x8000);
    b3.a = p;
    if (p) {
        b3.b = p;
        b3.c = p + 0x8000;
    } else {
        b3.b = 0;
        b3.c = 0;
    }
}
