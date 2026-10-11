extern "C" char DAT_00411314[];
typedef unsigned int u32;
struct NISSoundTrack {
    u32 vptr;
    char pad[12];
    u32 a, b, c;
    void BaseDestroy();
    void Destroy();
};
extern void __cdecl ReleaseThing(u32);
void NISSoundTrack::Destroy() {
    vptr = ((int)DAT_00411314);
    ReleaseThing(a);
    ReleaseThing(b);
    ReleaseThing(c);
    BaseDestroy();
}