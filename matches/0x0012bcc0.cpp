struct Helper {
    void run();
};
struct ThreatBallTrack {
    void* vptr;
    char pad04[0x14];
    Helper h18;
    char pad1d[0x17];
    Helper h30;
    ThreatBallTrack* other();
    ThreatBallTrack* vfunc_5(unsigned int);
};
extern void* threat_vftable;
void destroy(ThreatBallTrack*);
ThreatBallTrack* ThreatBallTrack::vfunc_5(unsigned int flags) {
    vptr = &threat_vftable;
    h30.run();
    h18.run();
    other();
    if (flags & 1)
        destroy(this);
    return this;
}