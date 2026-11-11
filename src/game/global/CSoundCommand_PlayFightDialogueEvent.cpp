// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001ef530..0x001ef570 (kind game, layer game, confidence medium), dominant class CSoundCommand_PlayFightDialogueEvent
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fcf5a062 {
#define TREE_TU_END }
namespace fn_fcf5a062 {} using namespace fn_fcf5a062;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fcf5a062 {
class Resolver {
  public:
    int Resolve(void*);
};
class Player {
  public:
    void Play(int, void*, int, int, unsigned char);
};
struct Global {
    Player* player;
    Resolver* resolver;
};
class CSoundCommand_1ef530 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};

} // namespace fn_fcf5a062

// 0x001ef530 CSoundCommand_PlayFightDialogueEvent::vfunc_1 (61 B): matches/0x001ef530.cpp
// sym: ?vfunc_1@CSoundCommand_PlayFightDialogueEvent@@UAEXHH@Z
void CSoundCommand_PlayFightDialogueEvent::vfunc_1(int a, int b) {
    Global* global = (*(Global**)&DAT_004e370c);
    Resolver* resolver = global->resolver;
    int id = resolver->Resolve(&this->f_10);
    if (id)
        (*(Global**)&DAT_004e370c)->player->Play(id, &(*(char (*)[8])&this->f_14)[4], a, this->f_1c, (*(unsigned char *)&this->f_20));
}

