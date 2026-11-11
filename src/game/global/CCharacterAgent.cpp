// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000fc760..0x000fc800 (kind game, layer game, confidence medium), dominant class CCharacterAgent
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_f27c94ec {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f27c94ec {} using namespace fn_f27c94ec;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f27c94ec {
extern void* hulk_at_0040cfe4[];
class Ref_fc7c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CCharacterAgent_fc7c0 {
  public:
    void* vptr;
    char pad[0x54];
    Ref_fc7c0* m58;
    void Fin_000fc460();
    void* Del(unsigned char flags);
};

} // namespace fn_f27c94ec

// 0x000fc760 FUN_000fc760 (95 B): matches/0x000fc760.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CCharacterAgent@fn_000fc760@@QAE@PAVAgentOwner@1@@Z
namespace fn_000fc760 {
class AgentOwner {
  public:
    virtual void Init();
};
class BaseAgent {
  public:
    virtual void Dummy();
    BaseAgent();
    int a;
    int b;
    char c;
    char pad[3];
    int d;
    int fields[16];
    int neg;
};
class CCharacterAgent : public BaseAgent {
  public:
    virtual void Dummy();
    CCharacterAgent(AgentOwner* p);
    AgentOwner* owner;
};
BaseAgent::BaseAgent() {
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    neg = -1;
    for (int i = 0; i < 16; i++)
        fields[i] = 0;
}
CCharacterAgent::CCharacterAgent(AgentOwner* p) {
    owner = p;
    p->Init();
}
} // namespace fn_000fc760

namespace fn_f27c94ec {

// 0x000fc7c0 CCharacterAgent::vfunc_2 (53 B): matches/0x000fc7c0.cpp
// sym: ?Del@CCharacterAgent_fc7c0@fn_f27c94ec@@QAEPAXE@Z
void* CCharacterAgent_fc7c0::Del(unsigned char flags) {
    Ref_fc7c0* r = m58;
    vptr = hulk_at_0040cfe4;
    r->Release();
    m58 = 0;
    Fin_000fc460();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f27c94ec
