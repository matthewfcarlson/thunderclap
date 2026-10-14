// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 13/14, incomplete)
// FUN_000fe9e0 @ 0x000fe9e0
// 0x000fe9e0: fetch (or lazily create) the CHand2HandAgent in *slot
struct CAgent {
    virtual void AddRef();
    virtual void Release();
};

struct CHand2HandAgent : CAgent {
    CHand2HandAgent *FUN_000ff180(struct AgentHost_fe9e0 *host);
};

struct AgentHost_fe9e0 {
    CAgent *FUN_000fdd30(const void *type);
};

extern char DAT_004a1b84;

int __cdecl FUN_00266da0(int v);
void *__cdecl FUN_0008d690(unsigned int size);

void __cdecl FUN_000fe9e0(AgentHost_fe9e0 *host, CAgent **slot)
{
    CAgent *found = host->FUN_000fdd30(&DAT_004a1b84);
    if (found) {
        CHand2HandAgent *agent = dynamic_cast<CHand2HandAgent *>(found);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
    }
    if (*slot == 0) {
        int mark = FUN_00266da0(0xc);
        CHand2HandAgent *agent = (CHand2HandAgent *)FUN_0008d690(0x1a0);
        if (agent)
            agent = agent->FUN_000ff180(host);
        if (agent)
            agent->AddRef();
        if (*slot)
            (*slot)->Release();
        *slot = agent;
        FUN_00266da0(mark);
    }
}
