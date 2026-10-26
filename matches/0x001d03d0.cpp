#include "decls/data/game/global.h"
// data: gCount_1d03d0 = DAT_004e23c8

typedef unsigned int size_t;
void* __cdecl operator new(size_t);
inline void* __cdecl operator new(size_t, void* p) {
    return p;
}
extern "C" void* __cdecl memcpy(void*, const void*, size_t);
class Params_1d03d0 {
  public:
    Params_1d03d0();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Params_1d03d0* v3();
    int a;
    int count;
    int b;
};
class Payload_1d03d0 {
  public:
    Payload_1d03d0();
    int length;
    char data[0xdc];
};
class CScenarioParams : public Params_1d03d0 {
  public:
    Payload_1d03d0 payload;
    CScenarioParams() {}
    virtual void v2();
    virtual CScenarioParams* v3();
};
CScenarioParams* CScenarioParams::v3() {
    CScenarioParams* q = (CScenarioParams*)operator new(0xf0);
    if (q) {
        Payload_1d03d0* src = &payload;
        q = new (q) CScenarioParams;
        memcpy(&q->payload, src, src->length);
        int n = ++(*(int*)&DAT_004e23c8);
        q->count = n;
        return q;
    }
    return 0;
}