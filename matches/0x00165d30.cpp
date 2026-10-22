extern void* g_vftable_165d30[];
class Str_165d30 {
  public:
    void Init();
};
class Condition_165d30 {
  public:
    void* vptr;
    char pad[12];
    Str_165d30 s;
    void Fin();
};
class RayCastTargetCondition_165d30 : public Condition_165d30 {
  public:
    ~RayCastTargetCondition_165d30();
};
RayCastTargetCondition_165d30::~RayCastTargetCondition_165d30() {
    vptr = g_vftable_165d30;
    s.Init();
    Fin();
}
