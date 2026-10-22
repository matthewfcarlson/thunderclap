extern void* g_vftable_1663f0[];
class Str_1663f0 {
  public:
    void Init();
};
class Condition_1663f0 {
  public:
    void* vptr;
    char pad[12];
    Str_1663f0 s;
    void Fin();
};
class RayCastCondition_1663f0 : public Condition_1663f0 {
  public:
    ~RayCastCondition_1663f0();
};
RayCastCondition_1663f0::~RayCastCondition_1663f0() {
    vptr = g_vftable_1663f0;
    s.Init();
    Fin();
}
