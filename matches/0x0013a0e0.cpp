extern void* g_vt_13a0e0[];
struct Sub_13a0e0 {
    void Fin() throw();
};
class Condition_13a0e0 {
  public:
    void* vptr;
    ~Condition_13a0e0() throw();
};
class FrameCondition_13a0e0 : public Condition_13a0e0 {
  public:
    char pad[0x10 - 4];
    Sub_13a0e0 sub;
    ~FrameCondition_13a0e0() throw();
};
FrameCondition_13a0e0::~FrameCondition_13a0e0() throw() {
    vptr = g_vt_13a0e0;
    sub.Fin();
}
