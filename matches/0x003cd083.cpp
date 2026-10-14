// cl-flags: /O1
extern void* bv[];
extern void* v2_3cd083[];
extern void* sv[];
extern int g1_3cd083;
extern int g2_3cd083;
struct Sub_3cd083 {
    void* vptr;
    Sub_3cd083(int) throw();
};
struct N_3cd083 {
    N_3cd083* next;
    N_3cd083* prev;
};
struct Sub2_3cd083 {
    void* vptr;
    char p[0x1c];
    void Init() throw();
};
struct Base_3cd083 {
    void* vptr;
    int a4;
    Base_3cd083() throw() {
        vptr = bv;
        a4 = 1;
    }
};
class O_3cd083 : public Base_3cd083 {
  public:
    Sub_3cd083 s8;
    char pad[0x58 - 0xc];
    int* m58;
    int* m5c;
    Sub2_3cd083 s60;
    char pad2[0x488 - 0x80];
    N_3cd083 arr[3];
    N_3cd083 n4a0;
    N_3cd083 n4a8;
    N_3cd083 n4b0;
    O_3cd083(int x) throw();
};
O_3cd083::O_3cd083(int x) throw() : s8(x) {
    vptr = v2_3cd083;
    s8.vptr = sv;
    m58 = &g1_3cd083;
    m5c = &g2_3cd083;
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
