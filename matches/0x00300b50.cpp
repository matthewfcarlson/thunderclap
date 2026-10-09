extern void __cdecl Release(void*);
class Obj {
  public:
    void Init();
    void* p0;
    void* q0;
    char x[8];
    void* p1;
    void* q1;
    char y[8];
    void* p2;
    void* q2;
    char z[8];
    void* p3;
    void* q3;
    char w[8];
    void* p4;
    void* q4;
    void Run();
};
void Obj::Run() {
    Init();
    void* p = p4;
    q4 = p;
    if (p)
        Release(p);
    p = p3;
    q3 = p;
    if (p)
        Release(p);
    p = p2;
    q2 = p;
    if (p)
        Release(p);
    p = p1;
    q1 = p;
    if (p)
        Release(p);
    p = p0;
    q0 = p;
    if (p)
        Release(p);
}