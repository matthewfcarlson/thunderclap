class Sub_13a530 {
  public:
    void Init();
};
extern void* AnimationVelocityScaledTrack_vftable;
class AnimationVelocityScaledTrack {
  public:
    void* vf;
    char pad[0x3c];
    void Finish();
    void Build();
};
void AnimationVelocityScaledTrack::Build() {
    vf = &AnimationVelocityScaledTrack_vftable;
    ((Sub_13a530*)((char*)this + 0x40))->Init();
    ((Sub_13a530*)((char*)this + 0x18))->Init();
    Finish();
}