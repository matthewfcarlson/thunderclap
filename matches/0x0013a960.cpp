// Same code shape as 0x0012bcc0 (propagated; names are from that function)
struct Helper_13a960 {
    void run();
};
struct AnimationPhaseMatchedTrack_13a960 {
    void* vptr;
    char pad04[0x14];
    Helper_13a960 h18;
    char pad1d[0x17];
    Helper_13a960 h30;
    AnimationPhaseMatchedTrack_13a960* other();
    AnimationPhaseMatchedTrack_13a960* vfunc_5(unsigned int);
};
extern void* threat_vftable_13a960;
void destroy(AnimationPhaseMatchedTrack_13a960*);
AnimationPhaseMatchedTrack_13a960* AnimationPhaseMatchedTrack_13a960::vfunc_5(unsigned int flags) {
    vptr = &threat_vftable_13a960;
    h30.run();
    h18.run();
    other();
    if (flags & 1)
        destroy(this);
    return this;
}