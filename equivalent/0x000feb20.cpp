// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000feb20 @ 0x000feb20
// FUN_000feb20: fetch (or lazily create) the CMoveAgent in *slot
struct CAgent {
    virtual void AddRef();
    virtual void Release();
};

struct CMoveAgent : CAgent {
    CMoveAgent *FUN_00102ac0(struct AgentHost_feb20 *host);
};

struct AgentHost_feb20 {
    CAgent *FUN_000fdd30(const void *type);
};

extern char DAT_004a1ba4;

int __cdecl FUN_00266da0(int v);
void *__cdecl FUN_0008d690(unsigned int size);

void __cdecl FUN_000feb20(AgentHost_feb20 *host, CAgent **slot)
{
    CAgent *found = host->FUN_000fdd30(&DAT_004a1ba4);
    if (found) {
        CMoveAgent *agent = dynamic_cast<CMoveAgent *>(found);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
    }
    if (*slot == 0) {
        int mark = FUN_00266da0(0xc);
        CMoveAgent *agent = (CMoveAgent *)FUN_0008d690(0x78);
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
