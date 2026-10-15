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
class CSoundCommand {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};
class CSoundCommand_PlayFightDialogueEvent : public CSoundCommand {
  public:
    char pad[12];
    int ident;
    char pad2[8];
    int data;
    unsigned char type;
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};
void CSoundCommand_PlayFightDialogueEvent::vfunc_1(int a, int b) {
    Global* global = g;
    Resolver* resolver = global->resolver;
    int id = resolver->Resolve(&ident);
    if (id)
        g->player->Play(id, &pad2[4], a, data, type);
}