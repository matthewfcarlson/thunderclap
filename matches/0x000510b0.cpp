extern void* g_vftable_510b0[];
class ConditionFactoryCaster_510b0 {
  public:
    void* vptr;
    ConditionFactoryCaster_510b0() { vptr = g_vftable_510b0; }
};
class ConditionFactoryCasterTemplate_510b0 : public ConditionFactoryCaster_510b0 {
  public:
    virtual void Dummy();
    ConditionFactoryCasterTemplate_510b0();
};
ConditionFactoryCasterTemplate_510b0::ConditionFactoryCasterTemplate_510b0() {
    vptr = g_vftable_510b0;
}