class Caster {
  public:
    virtual void cast();
};
class TrackCaster : public Caster {
  public:
    virtual void cast();
};
class Receiver {
  public:
    void attach(void*);
};
void* find(void*, Caster*);
void FUN_00122ba0(Receiver* r, void* obj) {
    TrackCaster caster;
    r->attach(find(obj, &caster));
}