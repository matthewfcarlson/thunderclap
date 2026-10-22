extern void* g_vftable_18cd40[];
class Str_18cd40 {
  public:
    void Init();
};
class Condition_18cd40 {
  public:
    void* vptr;
    char pad[12];
    Str_18cd40 s;
    void Fin();
};
class GrappleVarCompareCondition_18cd40 : public Condition_18cd40 {
  public:
    ~GrappleVarCompareCondition_18cd40();
};
GrappleVarCompareCondition_18cd40::~GrappleVarCompareCondition_18cd40() {
    vptr = g_vftable_18cd40;
    s.Init();
    Fin();
}
