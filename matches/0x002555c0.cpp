typedef unsigned __int64 U64;
U64 __cdecl GetType(const char*, int, int) throw();
struct Tmp {
    int a, b, c;
    Tmp* Init(const char*, int) throw();
    ~Tmp() throw();
};
struct Base {
    Base(Tmp*, const U64*, int, int) throw();
    virtual void f();
};
struct Cross : Base {
    Cross() throw();
    virtual void f();
};
Cross::Cross() throw() : Base(Tmp().Init("X-Fade", 0), &(U64 const&)(GetType("SeqEventCrossFade", 0, 0)), 0x34, 4) {}