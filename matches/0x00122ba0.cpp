class Caster_122ba0 {
  public:
    virtual void cast();
};
class TrackCaster : public Caster_122ba0 {
  public:
    virtual void cast();
};
class Receiver {
  public:
    void attach(void*);
};
void* find(void*, Caster_122ba0*);
void FUN_00122ba0(Receiver* r, void* obj) {
    TrackCaster caster;
    r->attach(find(obj, &caster));
}