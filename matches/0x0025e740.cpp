class Result_25e740 {
  public:
    void finish();
};
class EntityType {
  public:
    virtual void vfunc_0();
};
class MetaEntityType : public EntityType {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Result_25e740* vfunc_3();
};
void MetaEntityType::vfunc_0() {
    EntityType::vfunc_0();
    Result_25e740* r = vfunc_3();
    r->finish();
}