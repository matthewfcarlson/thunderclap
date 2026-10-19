// STATUS: equivalent (tools/equiv.py level 3: 3566 inputs, branch coverage 8/8)
// FUN_000bc3c0 @ 0x000bc3c0
// cl-flags: /GS
#include "decls/data/engine/content.h"

extern "C" char* strncpy(char*, const char*, unsigned int);

class Request {
  public:
    virtual void v0();
    virtual void Release();
    bool FUN_00266750();
    int FUN_00266700();
};
class Target_bc3c0 {
  public:
    void FUN_00266220(int value);
};
class Manager_bc3c0 {
  public:
    void FUN_00265810(const char* name, struct RequestState* state);
    int FUN_00264870();
    void FUN_00264860(int value);
};
struct RequestState {
    Request* request;
    char name[0x100];
    int field104;
    int field108;
    int arg;
    char field110;
};
void __cdecl FUN_00087990();

void __stdcall FUN_000bc3c0(const char* src, Target_bc3c0* target, int arg) {
    struct Frame {
        RequestState st;
    } frame;
    RequestState& st = frame.st;
    st.request = 0;
    st.name[0] = 0;
    st.field104 = 0;
    st.field108 = 0;
    st.arg = 0;
    st.field110 = 0;
    if (src != 0)
        strncpy(st.name, src, 0xff);
    st.arg = arg;
    st.field110 = 0;
    (*(Manager_bc3c0**)&DAT_00527c58)->FUN_00265810(st.name, &st);
    int saved = (*(Manager_bc3c0**)&DAT_00527c58)->FUN_00264870();
    (*(Manager_bc3c0**)&DAT_00527c58)->FUN_00264860(0x3d090);
    if (!st.request->FUN_00266750()) {
        do {
            FUN_00087990();
        } while (!st.request->FUN_00266750());
    }
    (*(Manager_bc3c0**)&DAT_00527c58)->FUN_00264860(saved);
    target->FUN_00266220(st.request->FUN_00266700());
    Request* r = st.request;
    if (r != 0)
        r->Release();
}
