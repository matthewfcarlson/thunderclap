class Seq;
class Player_1ef410;
class SoundSystem_1ef410 {
  public:
    Player_1ef410* player;
    Seq* sequences;
};
extern SoundSystem_1ef410* volatile gSound_1ef410;
extern volatile int gCount_1ef410;
extern int gMiss, gFail;
class Seq {
  public:
    Seq* Find(void*);
};
class Player_1ef410 {
  public:
    void* Play(Seq*, int);
};
class Event_1ef410 {
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
    Event_1ef410 event;

  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
};
void CSoundCommand_PlaySequenceEvent::vfunc_1(int x, int y) {
    SoundSystem_1ef410* sys = gSound_1ef410;
    ++gCount_1ef410;
    Seq* s = sys->sequences->Find(&id);
    if (!s) {
        ++gMiss;
        return;
    }
    int arg = x;
    SoundSystem_1ef410* sys2 = gSound_1ef410;
    void* p = sys2->player->Play(s, arg);
    if (p) {
        ((Event_1ef410*)p)->Apply(&event);
        return;
    }
    ++gFail;
}