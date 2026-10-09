extern "C" int vtable;
void thunk(int);
class DriftToPositionTrack { public: int vf; char pad[0x24]; int value; void f(); void tail(); };
void DriftToPositionTrack::f() { vf = (int)&vtable; thunk(value); tail(); }