struct Helper_12bcc0 {
    void run();
};
struct ThreatBallTrack {
    void* vptr;
    char pad04[0x14];
    Helper_12bcc0 h18;
    char pad1d[0x17];
    Helper_12bcc0 h30;
    ThreatBallTrack* other();
    ThreatBallTrack* vfunc_5(unsigned int);
};
extern void* threat_vftable_12bcc0;
void destroy(ThreatBallTrack*);
ThreatBallTrack* ThreatBallTrack::vfunc_5(unsigned int flags) {
    vptr = &threat_vftable_12bcc0;
    h30.run();
    h18.run();
    other();
    if (flags & 1)
        destroy(this);
    return this;
}