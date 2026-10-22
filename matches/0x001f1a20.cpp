// STATUS: equivalent (tools/equiv.py level 3: 2855 inputs, branch coverage 11/12, incomplete)
// FUN_001f1a20 @ 0x001f1a20
// cl-flags: /GS
#include "decls/data/game/unknown.h"
#include "gen/global.h"

extern "C" void * __cdecl memset(void *, int, unsigned int);
extern "C" char * __cdecl strcat(char *, const char *);

class Mgr_1f1a20 {
public:
    void FUN_001ef260(void *p);
};

struct CSoundCommand_PlayAmbienceEvent_1f1a20 {
    void *FUN_001f0880(const char *name, int b, int c);
};

void *__cdecl FUN_0008d710(int size, int tag);


struct Frame_1f1a20 {
    Mgr_1f1a20 *mgr;
    char buf[0x40];
};

void __stdcall FUN_001f1a20(const char *name, int b, int c)
{
    Frame_1f1a20 f;
    if (name != 0) {
        if (b != 0) {
            f.mgr = (*(Mgr_1f1a20**)&DAT_004e3710);
            if (f.mgr != 0) {
                memset(f.buf, 0, sizeof f.buf);
                strcat(f.buf, name);
                CSoundCommand_PlayAmbienceEvent *j = (CSoundCommand_PlayAmbienceEvent *)FUN_0008d710(0x20, 6);
                f.mgr->FUN_001ef260(j != 0 ? ((CSoundCommand_PlayAmbienceEvent_1f1a20*)(j))->FUN_001f0880(name, b, c) : 0);
            }
        }
    }
}
