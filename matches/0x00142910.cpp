class Caster_142910 {
  public:
    virtual void Cast();
};
struct Result;
Result* find(const char*, Caster_142910*);
class Manager {
  public:
    void Add(Result*);
};
void func(Manager* mgr) {
    Caster_142910 c;
    mgr->Add(find("wallVelocity", &c));
}