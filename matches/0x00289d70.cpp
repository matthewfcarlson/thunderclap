extern "C" char DAT_0042c8c4[];
class AnimationGroup {
  public:
    int x;
    void vfunc_1();
};
struct Sub {
    void Helper();
};
class Thing : public AnimationGroup {
  public:
    char pad[4];
    Sub sub;
    void Target();
};
void Thing::Target() {
    *(void**)this = (void*)((int)DAT_0042c8c4);
    AnimationGroup::vfunc_1();
    sub.Helper();
}