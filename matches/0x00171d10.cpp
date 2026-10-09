struct B { int go(); }; struct A { B* go(); }; struct C { void go(const char*); }; struct D { void go(void*,int); };
class TeleportRelativeAction { public: char pad[0x20]; A* mTarget; char pad2[4]; bool vfunc_3(void*,int); };
bool TeleportRelativeAction::vfunc_3(void*,int) {
 int r = mTarget->go()->go();
 ((C*)((char*)this+0x28))->go("teleport_failed");
 if (!mTarget) return false;
 if (r) ((D*)r)->go((char*)this+0x28,0);
 return true;
}