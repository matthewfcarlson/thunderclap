// Same code shape as 0x0012b640 (propagated; names are from that function)
extern int vtable_13a440;
class Helper_13a440 {
  public:
    void Init();
};
class Ender {
  public:
    void Finish();
};
class AnimationPhaseMatchedTrack_13a440 {
  public:
    virtual void v0();
    char pad[0x30 - 4];
    void Run();
};
void AnimationPhaseMatchedTrack_13a440::Run() {
    *(int*)this = (int)&vtable_13a440;
    ((Helper_13a440*)((char*)this + 0x30))->Init();
    ((Helper_13a440*)((char*)this + 0x18))->Init();
    ((Ender*)this)->Finish();
}
