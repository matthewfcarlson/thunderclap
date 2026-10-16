class Caster {
  public:
    virtual void cast();
};
extern void* findTrack(int, Caster*);
class Holder {
  public:
    void put(void*);
};
void target(Holder* h, int n) {
    Caster c;
    void* p = findTrack(n, &c);
    h->put(p);
}