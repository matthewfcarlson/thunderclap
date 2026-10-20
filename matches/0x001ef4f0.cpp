struct Lookup {
    int FUN_001e98b0(int*);
};
struct Player {
    void FUN_001f3c00(int, int*, int, int, int, unsigned char);
};
struct SoundSystem {
    Player* player;
    Lookup* lookup;
};
extern SoundSystem* DAT_004e370c;
class CSoundCommand_PlayDialogueEvent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
    char pad[12];
    int lookupKey;
    int identifier;
    int data;
    unsigned char flag;
};
void CSoundCommand_PlayDialogueEvent::vfunc_1(int value, int unused) {
    SoundSystem* sys = DAT_004e370c;
    Lookup* lookup = sys->lookup;
    int result = lookup->FUN_001e98b0(&lookupKey);
    if (result) {
        int v = value;
        int* p = &data;
        unsigned char f = flag;
        DAT_004e370c->player->FUN_001f3c00(result, p, v, 0, 0, f);
    }
}