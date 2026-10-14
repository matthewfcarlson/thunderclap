void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct Elem_312db0 {
    char d[24];
    Elem_312db0() throw();
};
class BufMgr {
  public:
    char pad[0x2020];
    int cap;
    Elem_312db0* buf1;
    void* buf2;
    void* buf3;
    void Resize(int n);
};
void BufMgr::Resize(int n) {
    if (cap >= n)
        return;
    Elem_312db0* o = buf1;
    cap = n;
    operator delete(o);
    operator delete(buf2);
    operator delete(buf3);
    buf1 = new Elem_312db0[n];
    buf2 = operator new(n * 2);
    buf3 = operator new(n * 2);
}
