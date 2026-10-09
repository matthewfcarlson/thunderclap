class Helper { public: void Init(); };
extern char BallAndChainShootTrack_vftable;
class BallAndChainShootTrack { public: char pad[0x78]; void Construct(); };
class Base { public: void Finish(); };
void BallAndChainShootTrack::Construct() { *(void**)this = &BallAndChainShootTrack_vftable; ((Helper*)((char*)this + 0x78))->Init(); ((Helper*)((char*)this + 0x60))->Init(); ((Base*)this)->Finish(); }