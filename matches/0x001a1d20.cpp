class TrackFactoryCasterTemplate_1a1d20 {
  public:
    virtual void cast();
};
class Track {
  public:
    void* get(void*);
};
extern void* find(const char*, TrackFactoryCasterTemplate_1a1d20*);
void* func(Track* t, const char* name) {
    TrackFactoryCasterTemplate_1a1d20 c;
    return t->get(find(name, &c));
}