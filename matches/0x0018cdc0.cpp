extern void* g_vftable_18cdc0[];
class Str_18cdc0 {
  public:
    void Init();
};
class Condition_18cdc0 {
  public:
    void* vptr;
    char pad[12];
    Str_18cdc0 s;
    void Fin();
};
class VarCompareCondition_18cdc0 : public Condition_18cdc0 {
  public:
    ~VarCompareCondition_18cdc0();
};
VarCompareCondition_18cdc0::~VarCompareCondition_18cdc0() {
    vptr = g_vftable_18cdc0;
    s.Init();
    Fin();
}
