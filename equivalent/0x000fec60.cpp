// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// FUN_000fec60 @ 0x000fec60
// 0x000fec60: fetch (or lazily create) the CPathGraphAgent in *slot
struct CAgent {
    virtual void AddRef();
    virtual void Release();
};

struct CPathGraphAgent : CAgent {
    CPathGraphAgent *FUN_00105f50(struct AgentHost *host);
};

struct AgentHost {
    CAgent *FUN_000fdd30(const void *type);
};

extern char DAT_004a1bdc;

int __cdecl FUN_00266da0(int v);
void *__cdecl FUN_0008d690(unsigned int size);

void __cdecl FUN_000fec60(AgentHost *host, CAgent **slot)
{
    CAgent *found = host->FUN_000fdd30(&DAT_004a1bdc);
    if (found) {
        CPathGraphAgent *agent = dynamic_cast<CPathGraphAgent *>(found);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
    }
    if (*slot == 0) {
        int mark = FUN_00266da0(0xc);
        CPathGraphAgent *agent = (CPathGraphAgent *)FUN_0008d690(0xf4);
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
