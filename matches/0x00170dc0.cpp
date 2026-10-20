// Same code shape as 0x000f99b0 (propagated; names are from that function)
extern int rawVtable;
class TeleportToLocatorTrack_170dc0 {
  public:
    int* vptr;
    char pad[12];
    int mArg;
    void finish();
    void run();
};
extern void __cdecl thunk(int);
void TeleportToLocatorTrack_170dc0::run() {
    vptr = &rawVtable;
    thunk(mArg);
    finish();
}