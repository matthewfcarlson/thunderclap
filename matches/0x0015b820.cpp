extern void* g_vftable_15b820[];
class Str_15b820 {
  public:
    void Init();
};
class Condition_15b820 {
  public:
    void* vptr;
    char pad[12];
    Str_15b820 s;
    void Fin();
};
class JointPlantedCondition_15b820 : public Condition_15b820 {
  public:
    ~JointPlantedCondition_15b820();
};
JointPlantedCondition_15b820::~JointPlantedCondition_15b820() {
    vptr = g_vftable_15b820;
    s.Init();
    Fin();
}
