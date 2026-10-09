class Helper { public: void f(); };
class PropSpawnTrack { public: void **vptr; char pad4[12]; int m10; char pad14[4]; void target(); };
void thunk_FUN_00267090(int);
void PropSpawnTrack::target() { vptr = (void**)0x41959c; thunk_FUN_00267090(m10); ((Helper*)((char*)this + 0x18))->f(); ((Helper*)this)->f(); }