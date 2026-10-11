extern void* v0[];
extern void* v1[];
extern void* v2[];
extern void* v3[];
extern void* v4[];
extern int g_id;
extern "C" void _ReadWriteBarrier();
class O;
extern O* g_o;
void FUN_002705f0() throw();
class O {
  public:
    void* p0;
    void* p1;
    int id;
    int m0c;
    int a, b, c, d;
    float f;
    char x, y;
    O() throw();
};
O::O() throw() {
    *(void* volatile*)&p0 = v0;
    *(void* volatile*)&p1 = v1;
    id = g_id;
    FUN_002705f0();
    *(void* volatile*)&p1 = v2;
    m0c = 0;
    FUN_002705f0();
    *(void* volatile*)&p0 = v3;
    p1 = v4;
    _ReadWriteBarrier();
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    x = 0;
    y = 0;
    f = 1.0f;
    g_o = this;
}
