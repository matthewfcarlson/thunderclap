// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// FUN_000fe940 @ 0x000fe940
// 0x000fe940: fetch (or lazily create) the CRangedAgent in *slot
#include "gen/owners.h"
struct CAgent_fe940 {
    virtual void AddRef();
    virtual void Release();
};

struct CRangedAgent_fe940 : CAgent_fe940 {
    CRangedAgent_fe940 *FUN_001076f0(struct AgentHost_fe940 *host);
};

struct AgentHost_fe940 {
};

extern char DAT_004a1b68;

int __cdecl FUN_00266da0(int v);
void *__cdecl FUN_0008d690(unsigned int size);

void __cdecl FUN_000fe940(AgentHost_fe940 *host, CAgent_fe940 **slot)
{
    CAgent_fe940 *found = ((CAgent_fe940 *)((owners::Container_fdd30 *)host)->FUN_000fdd30((hulk_intptr)(&DAT_004a1b68)));
    if (found) {
        CRangedAgent_fe940 *agent = dynamic_cast<CRangedAgent_fe940 *>(found);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
    }
    if (*slot == 0) {
        int mark = FUN_00266da0(0xc);
        CRangedAgent_fe940 *agent = (CRangedAgent_fe940 *)FUN_0008d690(0xb0);
        if (agent)
            agent = agent->FUN_001076f0(host);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
        FUN_00266da0(mark);
    }
}
