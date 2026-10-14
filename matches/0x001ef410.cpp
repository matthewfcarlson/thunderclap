class Seq;
class Player;
class SoundSystem {
  public:
    Player* player;
    Seq* sequences;
};
extern SoundSystem* volatile gSound;
extern volatile int gCount;
extern int gMiss, gFail;
class Seq {
  public:
    Seq* Find(void*);
};
class Player {
  public:
    void* Play(Seq*, int);
};
class Event {
  public:
    void Apply(void*);
};
class CSoundCommand {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};
class CSoundCommand_PlaySequenceEvent : public CSoundCommand {
    char pad[12];
    int id;
    int pad2;
    Event event;

  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};
void CSoundCommand_PlaySequenceEvent::vfunc_1(int x, int y) {
    SoundSystem* sys = gSound;
    ++gCount;
    Seq* s = sys->sequences->Find(&id);
    if (!s) {
        ++gMiss;
        return;
    }
    int arg = x;
    SoundSystem* sys2 = gSound;
    void* p = sys2->player->Play(s, arg);
    if (p) {
        ((Event*)p)->Apply(&event);
        return;
    }
    ++gFail;
}