class TrackFactoryCasterTemplate_18a310 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set(void*);
};
void* Find(const char*, TrackFactoryCasterTemplate_18a310*);
void Func(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_18a310 c;
    void* p = Find(name, &c);
    owner->Set(p);
}