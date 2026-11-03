// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000feb20 @ 0x000feb20
// FUN_000feb20: fetch (or lazily create) the CMoveAgent in *slot
#include "gen/owners.h"
struct CAgent_feb20 {
    virtual void AddRef();
    virtual void Release();
};

struct CMoveAgent_feb20 : CAgent_feb20 {
    CMoveAgent_feb20 *FUN_00102ac0(struct AgentHost_feb20 *host);
};

struct AgentHost_feb20 {
};

extern char DAT_004a1ba4;

int __cdecl FUN_00266da0(int v);
void *__cdecl FUN_0008d690(unsigned int size);

void __cdecl FUN_000feb20(AgentHost_feb20 *host, CAgent_feb20 **slot)
{
    CAgent_feb20 *found = ((CAgent_feb20 *)((owners::Container_fdd30 *)host)->FUN_000fdd30((hulk_intptr)(&DAT_004a1ba4)));
    if (found) {
        CMoveAgent_feb20 *agent = dynamic_cast<CMoveAgent_feb20 *>(found);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
    }
    if (*slot == 0) {
        int mark = FUN_00266da0(0xc);
        CMoveAgent_feb20 *agent = (CMoveAgent_feb20 *)FUN_0008d690(0x78);
        if (agent)
            agent = agent->FUN_00102ac0(host);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
        FUN_00266da0(mark);
    }
}
