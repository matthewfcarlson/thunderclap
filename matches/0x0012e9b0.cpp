extern "C" char DAT_00411314[];
typedef unsigned int u32_12e9b0;
struct NISSoundTrack {
    u32_12e9b0 vptr;
    char pad[12];
    u32_12e9b0 a, b, c;
    void BaseDestroy();
    void Destroy();
};
extern void __cdecl ReleaseThing(u32_12e9b0);
void NISSoundTrack::Destroy() {
    vptr = ((int)DAT_00411314);
    ReleaseThing(a);
    ReleaseThing(b);
    ReleaseThing(c);
    BaseDestroy();
}