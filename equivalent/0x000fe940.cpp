// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// FUN_000fe940 @ 0x000fe940
// 0x000fe940: fetch (or lazily create) the CRangedAgent in *slot
struct CAgent {
    virtual void AddRef();
    virtual void Release();
};

struct CRangedAgent : CAgent {
    CRangedAgent *FUN_001076f0(struct AgentHost_fe940 *host);
};

struct AgentHost_fe940 {
    CAgent *FUN_000fdd30(const void *type);
};

extern char DAT_004a1b68;

int __cdecl FUN_00266da0(int v);
void *__cdecl FUN_0008d690(unsigned int size);

void __cdecl FUN_000fe940(AgentHost_fe940 *host, CAgent **slot)
{
    CAgent *found = host->FUN_000fdd30(&DAT_004a1b68);
    if (found) {
        CRangedAgent *agent = dynamic_cast<CRangedAgent *>(found);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
    }
    if (*slot == 0) {
        int mark = FUN_00266da0(0xc);
        CRangedAgent *agent = (CRangedAgent *)FUN_0008d690(0xb0);
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
