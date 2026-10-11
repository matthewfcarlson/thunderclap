extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
extern void* g_base[];
void operator delete(void*);
struct Elem {
    char b[0x138];
    void Fini();
};
class Obj {
  public:
    void* vptr;
    char pad[0xc];
    Elem arr[4];
    char pad2[0xa4];
    void* m594;
    void* m598;
    ~Obj();
};
Obj::~Obj() {
    *(void* volatile*)&vptr = g_vftable;

    void* t = *(void* volatile*)&m594;
    m598 = t;
    if (t)
        operator delete(t);
    Elem* p = arr + 4;
    int i = 4;
    do {
        p--;
        p->Fini();
        i--;
    } while (i);
    vptr = g_base;
}
