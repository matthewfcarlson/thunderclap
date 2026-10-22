extern void* g_vt_14d870[];
struct Sub_14d870 {
    void Fin() throw();
};
class Condition_14d870 {
  public:
    void* vptr;
    ~Condition_14d870() throw();
};
class CollisionSourceNodeCondition_14d870 : public Condition_14d870 {
  public:
    char pad[0x10 - 4];
    Sub_14d870 sub;
    ~CollisionSourceNodeCondition_14d870() throw();
};
CollisionSourceNodeCondition_14d870::~CollisionSourceNodeCondition_14d870() throw() {
    vptr = g_vt_14d870;
    sub.Fin();
}
