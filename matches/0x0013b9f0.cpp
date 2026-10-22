extern "C" void _ReadWriteBarrier();
extern void* g_vftable_13b9f0[];
class ConditionFactoryCaster_13b9f0 {
  public:
    void* vptr;
    ConditionFactoryCaster_13b9f0() { vptr = 0; }
};
class ConditionFactoryCasterTemplate_13b9f0 : public ConditionFactoryCaster_13b9f0 {
  public:
    ConditionFactoryCasterTemplate_13b9f0();
};
ConditionFactoryCasterTemplate_13b9f0::ConditionFactoryCasterTemplate_13b9f0() {
    vptr = g_vftable_13b9f0;
    _ReadWriteBarrier();
}
