// STATUS: equivalent (tools/equiv.py level 3: 2532 inputs, branch coverage 10/10)
// FUN_000befc0 @ 0x000befc0
#include "decls/data/engine/content.h"
#include "decls/data/game/global.h"

extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" char* __cdecl _strncpy(char* dst, const char* src, unsigned int n);

class Request {
public:
    virtual void v0();
    virtual void Release();
    char pad08[0xc];
    int state;
    int result;
    bool FUN_00266750();
    int FUN_00266700();
};

class Streamer {
public:
    void FUN_00265810(char* name, Request** out);
    int FUN_00264870();
    void FUN_00264860(int value);
};

class Inventory {
public:
    void FUN_00266220(int value);
};

void __cdecl FUN_00087990();

struct Frame {
    Request* request;
    char name[0x100];
    int pad104;
    Inventory* inventory;
    int param;
    char flag;
    unsigned int cookie;
};

class Loader {
public:
    void FUN_000bd1b0(int arg);
    void FUN_000befc0(const char* name, int param, bool pump);
};

void Loader::FUN_000befc0(const char* name, int param, bool pump)
{
    Frame fr;
    fr.cookie = DAT_004d9968;
    fr.inventory = (*(Inventory**)&DAT_004dd9cc);
    fr.request = 0;
    fr.name[0] = 0;
    fr.pad104 = 0;
    fr.param = 0;
    fr.flag = 0;
    if (name != 0)
        _strncpy(fr.name, name, 0xff);
    fr.flag = 0;
    fr.param = param;
    (*(Streamer**)&DAT_00527c58)->FUN_00265810(fr.name, &fr.request);
    int saved = (*(Streamer**)&DAT_00527c58)->FUN_00264870();
    (*(Streamer**)&DAT_00527c58)->FUN_00264860(250000);
    while (!fr.request->FUN_00266750()) {
        FUN_00087990();
        if (pump)
            FUN_000bd1b0(0);
    }
    (*(Streamer**)&DAT_00527c58)->FUN_00264860(saved);
    (*(Inventory**)&DAT_004dd9cc)->FUN_00266220(fr.request->FUN_00266700());
    if (fr.request != 0)
        fr.request->Release();
    __security_check_cookie(fr.cookie);
}
