class Ref {
  public:
    virtual void v0();
    virtual void v1();
};
class Elem {
  public:
    char d[8];
    ~Elem() throw();
};
void operator delete(void*);
class StringChannel {
  public:
    virtual void a();
    virtual void b();
    char pad[8];
    Ref* volatile mRef;
    char pad2[4];
    void* m14;
    Elem* m18;
    void vfunc_1();
};
void StringChannel::vfunc_1() {
    if (mRef == 0 && m18 != 0) {
        int* base = (int*)m18 - 1;
        int n = *base;
        Elem* e = m18 + n;
        n--;
        if (n >= 0) {
            int c = n + 1;
            do {
                e--;
                e->~Elem();
                c--;
            } while (c != 0);
        }
        operator delete(base);
    }
    m18 = 0;
    if (mRef == 0) {
        operator delete(m14);
        m14 = 0;
    } else {
        Ref* r = mRef;
        if (r != 0) {
            r->v1();
            mRef = 0;
        }
        m14 = 0;
    }
}
