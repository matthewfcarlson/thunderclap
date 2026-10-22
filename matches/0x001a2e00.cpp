extern void* g_vt_1a2e00[];
struct Sub_1a2e00 {
    void Fin() throw();
};
class Condition_1a2e00 {
  public:
    void* vptr;
    ~Condition_1a2e00() throw();
};
class Event_StringCondition_1a2e00 : public Condition_1a2e00 {
  public:
    char pad[0x10 - 4];
    Sub_1a2e00 sub;
    ~Event_StringCondition_1a2e00() throw();
};
Event_StringCondition_1a2e00::~Event_StringCondition_1a2e00() throw() {
    vptr = g_vt_1a2e00;
    sub.Fin();
}
