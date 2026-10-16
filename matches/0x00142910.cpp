class Caster {
  public:
    virtual void Cast();
};
struct Result;
Result* find(const char*, Caster*);
class Manager {
  public:
    void Add(Result*);
};
void func(Manager* mgr) {
    Caster c;
    mgr->Add(find("wallVelocity", &c));
}