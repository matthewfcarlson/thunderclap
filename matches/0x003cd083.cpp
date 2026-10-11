// cl-flags: /O1
extern void* bv[];
extern void* v2[];
extern void* sv[];
extern int g1;
extern int g2;
struct Sub {
    void* vptr;
    Sub(int) throw();
};
struct N {
    N* next;
    N* prev;
};
struct Sub2 {
    void* vptr;
    char p[0x1c];
    void Init() throw();
};
struct Base {
    void* vptr;
    int a4;
    Base() throw() {
        vptr = bv;
        a4 = 1;
    }
};
class O : public Base {
  public:
    Sub s8;
    char pad[0x58 - 0xc];
    int* m58;
    int* m5c;
    Sub2 s60;
    char pad2[0x488 - 0x80];
    N arr[3];
    N n4a0;
    N n4a8;
    N n4b0;
    O(int x) throw();
};
O::O(int x) throw() : s8(x) {
    vptr = v2;
    s8.vptr = sv;
    m58 = &g1;
    m5c = &g2;
    s60.Init();
    for (int i = 0; i < 3; i++) {
        arr[i].prev = &arr[i];
        arr[i].next = &arr[i];
    }
    n4a0.prev = &n4a0;
    n4a0.next = &n4a0;
    n4a8.prev = &n4a8;
    n4a8.next = &n4a8;
    n4b0.prev = &n4b0;
    n4b0.next = &n4b0;
    int* a = m58;
    *a = 0xc0;
    a = m5c;
    *a = 0x40;
}
