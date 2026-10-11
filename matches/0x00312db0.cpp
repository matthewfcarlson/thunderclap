void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct Elem {
    char d[24];
    Elem() throw();
};
class BufMgr {
  public:
    char pad[0x2020];
    int cap;
    Elem* buf1;
    void* buf2;
    void* buf3;
    void Resize(int n);
};
void BufMgr::Resize(int n) {
    if (cap >= n)
        return;
    Elem* o = buf1;
    cap = n;
    operator delete(o);
    operator delete(buf2);
    operator delete(buf3);
    buf1 = new Elem[n];
    buf2 = operator new(n * 2);
    buf3 = operator new(n * 2);
}
