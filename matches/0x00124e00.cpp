extern void* g_vA[];
void operator delete(void*);
struct Sub_124e00 {
    void* v;
    void Fin();
};
class Condition_124e00 {
  public:
    void* vptr;
    void Fin();
};
class TargetArcCondition_124e00 : public Condition_124e00 {
  public:
    char pad[0x18 - 4];
    Sub_124e00 sub;
    TargetArcCondition_124e00* f5(unsigned char flags);
};
TargetArcCondition_124e00* TargetArcCondition_124e00::f5(unsigned char flags) {
    vptr = g_vA;
    sub.Fin();
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
