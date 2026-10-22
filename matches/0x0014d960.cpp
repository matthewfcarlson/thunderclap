extern void* g_vftable_14d960[];
class Str_14d960 {
  public:
    void Init();
};
class Condition_14d960 {
  public:
    void* vptr;
    char pad[12];
    Str_14d960 s;
    void Fin();
};
class CollisionTargetNameCondition_14d960 : public Condition_14d960 {
  public:
    ~CollisionTargetNameCondition_14d960();
};
CollisionTargetNameCondition_14d960::~CollisionTargetNameCondition_14d960() {
    vptr = g_vftable_14d960;
    s.Init();
    Fin();
}
