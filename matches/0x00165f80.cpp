extern void* g_vftable_165f80[];
class Str_165f80 {
  public:
    void Init();
};
class Condition_165f80 {
  public:
    void* vptr;
    char pad[12];
    Str_165f80 s;
    void Fin();
};
class RayCastConeCondition_165f80 : public Condition_165f80 {
  public:
    ~RayCastConeCondition_165f80();
};
RayCastConeCondition_165f80::~RayCastConeCondition_165f80() {
    vptr = g_vftable_165f80;
    s.Init();
    Fin();
}
