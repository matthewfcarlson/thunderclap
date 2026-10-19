class Caster_18b080 {
  public:
    virtual void cast();
};
extern void* findTrack(int, Caster_18b080*);
class Holder {
  public:
    void put(void*);
};
void target(Holder* h, int n) {
    Caster_18b080 c;
    void* p = findTrack(n, &c);
    h->put(p);
}