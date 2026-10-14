extern "C" char DAT_00411374[];
typedef unsigned int u32_12edc0;
extern void __cdecl ReleaseThing(u32_12edc0);
struct DebugPrintTrack {
    u32_12edc0 vftable;
    char pad4[0x10];
    u32_12edc0 a;
    u32_12edc0 b;
    void Cleanup();
};
extern void __fastcall Finish(DebugPrintTrack*);
void DebugPrintTrack::Cleanup() {
    vftable = ((int)DAT_00411374);
    ReleaseThing(a);
    ReleaseThing(b);
    Finish(this);
}