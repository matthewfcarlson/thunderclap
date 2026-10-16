// STATUS: equivalent (tools/equiv.py level 3: 2853 inputs, branch coverage 11/12, incomplete)
// FUN_001f1ad0 @ 0x001f1ad0
#include "decls/data/game/unknown.h"

extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" void * __cdecl memset(void *, int, unsigned int);
extern "C" char * __cdecl strcat(char *, const char *);
extern unsigned int DAT_004d9968;

class Mgr_1f1ad0 {
public:
    void FUN_001ef260(void *p);
};

class Job_1f1ad0 {
public:
    void *FUN_001f08f0(const char *name, int b, int c);
};

void *__cdecl FUN_0008d710(int size, int tag);


struct Frame_1f1ad0 {
    Mgr_1f1ad0 *mgr;
    char buf[0x40];
    unsigned int cookie;
};

void __stdcall FUN_001f1ad0(const char *name, int b, int c)
{
    Frame_1f1ad0 f;
    f.cookie = DAT_004d9968;
    if (name != 0) {
        if (b != 0) {
            f.mgr = (*(Mgr_1f1ad0**)&DAT_004e3710);
            if (f.mgr != 0) {
                memset(f.buf, 0, sizeof f.buf);
                strcat(f.buf, name);
                Job_1f1ad0 *j = (Job_1f1ad0 *)FUN_0008d710(0x20, 6);
                f.mgr->FUN_001ef260(j != 0 ? j->FUN_001f08f0(name, b, c) : 0);
            }
        }
    }
    __security_check_cookie(f.cookie);
}
