#include "decls/data/game/global.h"
// data: gmgr = DAT_0052c2b0

struct Buf_294500 {
    char pad[12];
    void put(void* p, unsigned int v);
};
struct Sub_294500 {
    unsigned int getval();
};
struct Mgr_294500 {
    Sub_294500* sub;
};
struct Obj_294500 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual unsigned int get();
};
class Target_294500 {
  public:
    char pad[0x18];
    Obj_294500* obj;
    void run(int a, int b, int c, Buf_294500* out);
};
void Target_294500::run(int a, int b, int c, Buf_294500* out) {
    Buf_294500 local;
    local.put(&a, (*(Mgr_294500**)&DAT_0052c2b0)->sub->getval());
    if (obj) {
        unsigned int v = obj->get();
        out->put(&local, v);
    }
}
