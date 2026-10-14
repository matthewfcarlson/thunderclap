typedef unsigned int size_t;
void* __cdecl operator new(size_t);
inline void* __cdecl operator new(size_t, void* p) {
    return p;
}
extern "C" void* __cdecl memcpy(void*, const void*, size_t);
extern int gCount;
class Base {
  public:
    Base();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Base* v3();
    int a;
    int count;
    int b;
};
class Payload {
  public:
    Payload();
    int length;
    char data[0xdc];
};
class CScenarioParams : public Base {
  public:
    Payload payload;
    CScenarioParams() {}
    virtual void v2();
    virtual CScenarioParams* v3();
};
CScenarioParams* CScenarioParams::v3() {
    CScenarioParams* q = (CScenarioParams*)operator new(0xf0);
    if (q) {
        Payload* src = &payload;
        q = new (q) CScenarioParams;
        memcpy(&q->payload, src, src->length);
        int n = ++gCount;
        q->count = n;
        return q;
    }
    return 0;
}