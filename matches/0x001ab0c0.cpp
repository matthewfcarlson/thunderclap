extern void* g_vftable_1ab0c0[];
class Str_1ab0c0 {
  public:
    void Init();
};
class Condition_1ab0c0 {
  public:
    void* vptr;
    char pad[12];
    Str_1ab0c0 s;
    void Fin();
};
class Event_PathNameCondition_1ab0c0 : public Condition_1ab0c0 {
  public:
    ~Event_PathNameCondition_1ab0c0();
};
Event_PathNameCondition_1ab0c0::~Event_PathNameCondition_1ab0c0() {
    vptr = g_vftable_1ab0c0;
    s.Init();
    Fin();
}
