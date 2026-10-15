struct Resolver {
    int Lookup(void*);
};
struct Player {
    void Play(int, void*, int, void*, int, unsigned char);
};
struct SoundMgr {
    Player* player;
    Resolver* resolver;
};
extern SoundMgr* gSoundMgr;
class CSoundCommand {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};
class CSoundCommand_PlayMissionDialogueEvent : public CSoundCommand {
  public:
    char pad0[12];
    int id;
    char pad1[8];
    int value;
    char pad2[0x20];
    unsigned char flag;
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};
void CSoundCommand_PlayMissionDialogueEvent::vfunc_1(int a, int b) {
    SoundMgr* mgr = gSoundMgr;
    Resolver* r = mgr->resolver;
    int item = r->Lookup(&id);
    if (item)
        gSoundMgr->player->Play(item, (char*)this + 0x18, a, (char*)this + 0x20, value, flag);
}