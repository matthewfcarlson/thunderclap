struct Sub {
    void F();
};
struct ThreatAngleCondition {
    void* vf;
    char pad[0x14];
    Sub sub;
    ThreatAngleCondition* vfunc_5(int);
    void Second();
};
void Cleanup(ThreatAngleCondition*);
extern char vtable[];
ThreatAngleCondition* ThreatAngleCondition::vfunc_5(int flag) {
    vf = vtable;
    sub.F();
    Second();
    if (flag & 1)
        Cleanup(this);
    return this;
}