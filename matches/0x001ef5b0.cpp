struct Global {
    void* a;
    void* b;
};
extern Global* gSound;
struct Resolver {
    int Run(void*);
};
struct Player {
    void Run(int, void*);
};
class CSoundCommand_PlayMusicEvent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
    char pad[12];
};
void CSoundCommand_PlayMusicEvent::vfunc_1(int, int) {
    Resolver* r = (Resolver*)gSound->b;
    int x = r->Run((char*)this + 0x10);
    if (x) {
        Player* p = (Player*)gSound->a;
        p->Run(x, (char*)this + 0x18);
    }
}
