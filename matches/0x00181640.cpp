class Sub {
  public:
    void init();
};
class PropSpawnTrack {
  public:
    void* vftable;
    char pad4[0x0c];
    int mValue;
    char pad14[4];
    void finish();
    void run();
};
extern void __cdecl thunk(int);
void PropSpawnTrack::run() {
    vftable = (void*)0x41959c;
    thunk(mValue);
    ((Sub*)((char*)this + 0x18))->init();
    finish();
}