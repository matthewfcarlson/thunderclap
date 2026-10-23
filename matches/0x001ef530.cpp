#include "gen/global.h"

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
extern Global* g;
class CSoundCommand_1ef530 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};

void CSoundCommand_PlayFightDialogueEvent::vfunc_1(int a, int b) {
    Global* global = g;
    Resolver* resolver = global->resolver;
    int id = resolver->Resolve(&this->f_10);
    if (id)
        g->player->Play(id, &(*(char (*)[8])&this->f_14)[4], a, this->f_1c, (*(unsigned char *)&this->f_20));
}
