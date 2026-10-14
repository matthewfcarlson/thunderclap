extern void* v_3cf335[];
extern int g_3cf335;
struct N_3cf335 {
    N_3cf335* next;
    N_3cf335* prev;
};
class O_3cf335 {
  public:
    void* vptr;
    N_3cf335 n0;
    N_3cf335 n1;
    int pad;
    int pad2;
    int* m1c;
    O_3cf335() throw();
};
O_3cf335::O_3cf335() throw() {
    n0.prev = &n0;
    n0.next = &n0;
    vptr = v_3cf335;
    m1c = &g_3cf335;
    n1.prev = &n1;
    n1.next = &n1;
}
