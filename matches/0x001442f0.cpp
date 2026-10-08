class Action { char pad[0x20]; public: int value; };
class SlowMotionAction : public Action { public: void vfunc_4(); };
struct Receiver { void call(int); };
struct GlobalObj { char pad[0x58]; Receiver* member; };
extern GlobalObj* gObj;
void SlowMotionAction::vfunc_4() { gObj->member->call(value); }