typedef unsigned int u32;
extern void __cdecl ReleaseThing(u32);
struct DebugPrintTrack {
    u32 vftable;
    char pad4[0x10];
    u32 a;
    u32 b;
    void Cleanup();
};
extern void __fastcall Finish(DebugPrintTrack*);
void DebugPrintTrack::Cleanup() {
    vftable = 0x411374;
    ReleaseThing(a);
    ReleaseThing(b);
    Finish(this);
}