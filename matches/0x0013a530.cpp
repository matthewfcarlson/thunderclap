class Sub { public: void Init(); };
extern void* AnimationVelocityScaledTrack_vftable;
class AnimationVelocityScaledTrack { public: void* vf; char pad[0x3c]; void Finish(); void Build(); };
void AnimationVelocityScaledTrack::Build() {
    vf = &AnimationVelocityScaledTrack_vftable;
    ((Sub*)((char*)this + 0x40))->Init();
    ((Sub*)((char*)this + 0x18))->Init();
    Finish();
}