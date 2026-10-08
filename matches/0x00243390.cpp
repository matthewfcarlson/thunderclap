// Same code shape as 0x00059810 (propagated; names are from that function)
class CFightParamsCollision { char pad[0x18]; public: CFightParamsCollision* vfunc_3(); };
CFightParamsCollision* CFightParamsCollision::vfunc_3() { return (CFightParamsCollision*)((char*)this + 0x18); }