extern int vtable;
struct Sub { void Init(); void Finish(); };
class BallAndChainReturnTrack { public: char pad[0x60]; void Build(); };
void BallAndChainReturnTrack::Build() { *(int*)this = (int)&vtable; ((Sub*)((char*)this+0x60))->Init(); ((Sub*)((char*)this+0x48))->Init(); ((Sub*)this)->Finish(); }
