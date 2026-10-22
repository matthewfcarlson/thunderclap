extern void* g_vt_1a30f0[];
struct Sub_1a30f0 {
    void Fin() throw();
};
class Condition_1a30f0 {
  public:
    void* vptr;
    ~Condition_1a30f0() throw();
};
class Event_PropNameCondition_1a30f0 : public Condition_1a30f0 {
  public:
    char pad[0x10 - 4];
    Sub_1a30f0 sub;
    ~Event_PropNameCondition_1a30f0() throw();
};
Event_PropNameCondition_1a30f0::~Event_PropNameCondition_1a30f0() throw() {
    vptr = g_vt_1a30f0;
    sub.Fin();
}
