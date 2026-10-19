// STATUS: equivalent (tools/equiv.py level 3: 19025 inputs, branch coverage 11/12, incomplete)
// FUN_001f1b80 @ 0x001f1b80
// cl-flags: /GS
#include "decls/data/game/unknown.h"

extern "C" void * __cdecl memset(void *, int, unsigned int);
extern "C" char * __cdecl strcat(char *, const char *);

class Mgr_1f1b80 {
public:
    void FUN_001ef260(void *p);
};

class Job_1f1b80 {
public:
    void *FUN_001f0960(const char *name, int b, int c);
};

void *__cdecl FUN_0008d710(int size, int tag);


struct Frame_1f1b80 {
    Mgr_1f1b80 *mgr;
    char buf[0x40];
};

void __stdcall FUN_001f1b80(const char *name, int b, int c)
{
    Frame_1f1b80 f;
    if (name != 0) {
        if (b != 0) {
            f.mgr = (*(Mgr_1f1b80**)&DAT_004e3710);
            if (f.mgr != 0) {
                memset(f.buf, 0, sizeof f.buf);
                strcat(f.buf, name);
                Job_1f1b80 *j = (Job_1f1b80 *)FUN_0008d710(0x20, 6);
                f.mgr->FUN_001ef260(j != 0 ? j->FUN_001f0960(name, b, c) : 0);
            }
        }
    }
}
