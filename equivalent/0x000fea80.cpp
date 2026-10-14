// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000fea80 @ 0x000fea80
// FUN_000fea80: fetch (or lazily create) the CChaseAgent in *slot
struct CAgent {
    virtual void AddRef();
    virtual void Release();
};

struct CChaseAgent : CAgent {
    CChaseAgent *FUN_000fcb10(struct AgentHost *host);
};

struct AgentHost {
    CAgent *FUN_000fdd30(const void *type);
};

extern char DAT_004a1a44;

int __cdecl FUN_00266da0(int v);
void *__cdecl FUN_0008d690(unsigned int size);

void __cdecl FUN_000fea80(AgentHost *host, CAgent **slot)
{
    CAgent *found = host->FUN_000fdd30(&DAT_004a1a44);
    if (found) {
        CChaseAgent *agent = dynamic_cast<CChaseAgent *>(found);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
    }
    if (*slot == 0) {
        int mark = FUN_00266da0(0xc);
        CChaseAgent *agent = (CChaseAgent *)FUN_0008d690(0x74);
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
