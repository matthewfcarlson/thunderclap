// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 8/8)
// FUN_001f1670 @ 0x001f1670
#include "decls/data/game/unknown.h"
#include "gen/global.h"

class Mgr_1f1670 {
public:
    void FUN_001ef260(void *p);
};

struct CSoundCommand_SetLoopPitchEvent_nv_1f1670 {
    void *FUN_001f03a0(int a, int b, int c, int d, int e);
};

void *__cdecl FUN_0008d710(int size, int tag);

void __stdcall FUN_001f1670(int a, int b, int c, int d, int e)
{
    if (a == 0 || b == 0)
        return;
    Mgr_1f1670 *m = (*(Mgr_1f1670**)&DAT_004e3710);
    if (m == 0)
        return;
    CSoundCommand_SetLoopPitchEvent *j = (CSoundCommand_SetLoopPitchEvent *)FUN_0008d710(0x28, 6);
    if (j != 0) {
        m->FUN_001ef260(((CSoundCommand_SetLoopPitchEvent_nv_1f1670*)(((CSoundCommand_SetLoopPitchEvent*)(j))))->FUN_001f03a0(a, b, c, d, e));
    } else {
        m->FUN_001ef260(0);
    }
}
