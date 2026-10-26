#include "gen/global.h"
#include "decls/data/game/unknown.h"

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

void CSoundCommand_PlayFightDialogueEvent::vfunc_1(int a, int b) {
    Global* global = (*(Global**)&DAT_004e370c);
    Resolver* resolver = global->resolver;
    int id = resolver->Resolve(&this->f_10);
    if (id)
        (*(Global**)&DAT_004e370c)->player->Play(id, &(*(char (*)[8])&this->f_14)[4], a, this->f_1c, (*(unsigned char *)&this->f_20));
}
