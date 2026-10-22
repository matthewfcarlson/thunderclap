extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1b6530[];
extern void* g_base_1b6530[];
void operator delete(void*);
struct Elem_1b6530 {
    char b[0x138];
    void Fini();
};
class CCollisionManager_1b6530 {
  public:
    void* vptr;
    char pad[0xc];
    Elem_1b6530 arr[4];
    char pad2[0xa4];
    void* m594;
    void* m598;
    ~CCollisionManager_1b6530();
};
CCollisionManager_1b6530::~CCollisionManager_1b6530() {
    *(void* volatile*)&vptr = g_vftable_1b6530;

    void* t = *(void* volatile*)&m594;
    m598 = t;
    if (t)
        operator delete(t);
    Elem_1b6530* p = arr + 4;
    int i = 4;
    do {
        p--;
        p->Fini();
        i--;
    } while (i);
    vptr = g_base_1b6530;
}
