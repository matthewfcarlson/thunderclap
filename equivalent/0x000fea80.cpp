// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000fea80 @ 0x000fea80
// FUN_000fea80: fetch (or lazily create) the CChaseAgent in *slot
#include "gen/owners.h"
struct CAgent_fea80 {
    virtual void AddRef();
    virtual void Release();
};

struct CChaseAgent_fea80 : CAgent_fea80 {
    CChaseAgent_fea80 *FUN_000fcb10(struct AgentHost_fea80 *host);
};

struct AgentHost_fea80 {
};

extern char DAT_004a1a44;

int __cdecl FUN_00266da0(int v);
void *__cdecl FUN_0008d690(unsigned int size);

void __cdecl FUN_000fea80(AgentHost_fea80 *host, CAgent_fea80 **slot)
{
    CAgent_fea80 *found = ((CAgent_fea80 *)((owners::Container_fdd30 *)host)->FUN_000fdd30((hulk_intptr)(&DAT_004a1a44)));
    if (found) {
        CChaseAgent_fea80 *agent = dynamic_cast<CChaseAgent_fea80 *>(found);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
    }
    if (*slot == 0) {
        int mark = FUN_00266da0(0xc);
        CChaseAgent_fea80 *agent = (CChaseAgent_fea80 *)FUN_0008d690(0x74);
        if (agent)
            agent = agent->FUN_000fcb10(host);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
        FUN_00266da0(mark);
    }
}
