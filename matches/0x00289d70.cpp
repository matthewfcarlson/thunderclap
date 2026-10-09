class AnimationGroup { public: int x; void vfunc_1(); };
struct Sub { void Helper(); };
class Thing : public AnimationGroup { public: char pad[4]; Sub sub; void Target(); };
void Thing::Target() { *(void**)this = (void*)0x42c8c4; AnimationGroup::vfunc_1(); sub.Helper(); }