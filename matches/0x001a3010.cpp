extern void* g_vftable_1a3010[];
class Str_1a3010 {
  public:
    void Init();
};
class Condition_1a3010 {
  public:
    void* vptr;
    char pad[12];
    Str_1a3010 s;
    void Fin();
};
class Event_PropTypeCondition_1a3010 : public Condition_1a3010 {
  public:
    ~Event_PropTypeCondition_1a3010();
};
Event_PropTypeCondition_1a3010::~Event_PropTypeCondition_1a3010() {
    vptr = g_vftable_1a3010;
    s.Init();
    Fin();
}
