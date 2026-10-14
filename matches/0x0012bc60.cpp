struct Sub_12bc60 {
    void F();
};
struct ThreatAngleCondition {
    void* vf;
    char pad[0x14];
    Sub_12bc60 sub;
    ThreatAngleCondition* vfunc_5(int);
    void Second();
};
void Cleanup(ThreatAngleCondition*);
extern char vtable_12bc60[];
ThreatAngleCondition* ThreatAngleCondition::vfunc_5(int flag) {
    vf = vtable_12bc60;
    sub.F();
    Second();
    if (flag & 1)
        Cleanup(this);
    return this;
}