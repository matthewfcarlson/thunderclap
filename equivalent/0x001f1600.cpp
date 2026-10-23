// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 8/8)
// FUN_001f1600 @ 0x001f1600
#include "decls/data/game/unknown.h"
#include "gen/global.h"

class Mgr_1f1600 {
public:
    void FUN_001ef260(void *p);
};

struct CSoundCommand_PlayTunableEvent_nv_1f1600 {
    void *FUN_001f0230(int a, int b, int c, int d, int e, int f);
};

void *__cdecl FUN_0008d710(int size, int tag);

void __stdcall FUN_001f1600(int a, int b, int c, int d, int e, int f)
{
    if (a == 0 || b == 0)
        return;
    Mgr_1f1600 *m = (*(Mgr_1f1600**)&DAT_004e3710);
    if (m == 0)
        return;
    CSoundCommand_PlayTunableEvent *j = (CSoundCommand_PlayTunableEvent *)FUN_0008d710(0x28, 6);
    if (j != 0) {
        m->FUN_001ef260(((CSoundCommand_PlayTunableEvent_nv_1f1600*)(((CSoundCommand_PlayTunableEvent*)(j))))->FUN_001f0230(a, b, c, d, e, f));
    } else {
        m->FUN_001ef260(0);
    }
}
