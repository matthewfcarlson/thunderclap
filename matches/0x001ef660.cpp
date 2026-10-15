// Same code shape as 0x001ef5b0 (propagated; names are from that function)
struct Global_1ef660 {
    void* a;
    void* b;
};
extern Global_1ef660* gSound_1ef660;
struct Resolver_1ef660 {
    int Run(void*);
};
struct Player_1ef660 {
    void Run(int, void*);
};
class CSoundCommand_CueNISEvent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1(int, int);
    char pad[12];
};
void CSoundCommand_CueNISEvent::vfunc_1(int, int) {
    Resolver_1ef660* r = (Resolver_1ef660*)gSound_1ef660->b;
    int x = r->Run((char*)this + 0x10);
    if (x) {
        Player_1ef660* p = (Player_1ef660*)gSound_1ef660->a;
        p->Run(x, (char*)this + 0x18);
    }
}
