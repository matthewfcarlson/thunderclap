typedef unsigned __int64 U64;
U64 __cdecl GetType(const char*, int, int) throw();
struct Tmp {
    int a, b, c;
    Tmp* Init(const char*, int) throw();
    ~Tmp() throw();
};
struct SeqEventType_2555c0 {
    SeqEventType_2555c0(Tmp*, const U64*, int, int) throw();
    virtual void f();
};
struct SeqEventCrossFadeType_2555c0 : SeqEventType_2555c0 {
    SeqEventCrossFadeType_2555c0() throw();
    virtual void f();
};
SeqEventCrossFadeType_2555c0::SeqEventCrossFadeType_2555c0() throw() : SeqEventType_2555c0(Tmp().Init("X-Fade", 0), &(U64 const&)(GetType("SeqEventCrossFade", 0, 0)), 0x34, 4) {}