// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// FUN_000fec60 @ 0x000fec60
// 0x000fec60: fetch (or lazily create) the CPathGraphAgent in *slot
#include "gen/owners.h"
struct CAgent_fec60 {
    virtual void AddRef();
    virtual void Release();
};

struct CPathGraphAgent_fec60 : CAgent_fec60 {
    CPathGraphAgent_fec60 *FUN_00105f50(struct AgentHost_fec60 *host);
};

struct AgentHost_fec60 {
};

extern char DAT_004a1bdc;

int __cdecl FUN_00266da0(int v);
void *__cdecl FUN_0008d690(unsigned int size);

void __cdecl FUN_000fec60(AgentHost_fec60 *host, CAgent_fec60 **slot)
{
    CAgent_fec60 *found = ((CAgent_fec60 *)((owners::Container_fdd30 *)host)->FUN_000fdd30((hulk_intptr)(&DAT_004a1bdc)));
    if (found) {
        CPathGraphAgent_fec60 *agent = dynamic_cast<CPathGraphAgent_fec60 *>(found);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
    }
    if (*slot == 0) {
        int mark = FUN_00266da0(0xc);
        CPathGraphAgent_fec60 *agent = (CPathGraphAgent_fec60 *)FUN_0008d690(0xf4);
        if (agent)
            agent = agent->FUN_00105f50(host);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
        FUN_00266da0(mark);
    }
}
