extern void* g_vftable_14d790[];
class Str_14d790 {
  public:
    void Init();
};
class Condition_14d790 {
  public:
    void* vptr;
    char pad[12];
    Str_14d790 s;
    void Fin();
};
class CollisionThrownObjectCondition_14d790 : public Condition_14d790 {
  public:
    ~CollisionThrownObjectCondition_14d790();
};
CollisionThrownObjectCondition_14d790::~CollisionThrownObjectCondition_14d790() {
    vptr = g_vftable_14d790;
    s.Init();
    Fin();
}
