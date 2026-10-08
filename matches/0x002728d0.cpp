// Same code shape as 0x00196630 (propagated; names are from that function)
class ProjectileMissile { public: char pad[0x60]; ProjectileMissile* vfunc_3(); };
ProjectileMissile* ProjectileMissile::vfunc_3() { return (ProjectileMissile*)((char*)this + 0x60); }