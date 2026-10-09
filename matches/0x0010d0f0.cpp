struct Tail { void Init(); };
struct SemaphoreClearTrack { void* vptr; char pad[0x14]; void Finish(); void Run(); };
extern void* vftable;
void SemaphoreClearTrack::Run() { vptr = &vftable; ((Tail*)((char*)this + 0x18))->Init(); Finish(); }