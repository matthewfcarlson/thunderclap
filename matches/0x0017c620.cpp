namespace fight {
class TrackFactoryCasterTemplate {
  public:
    virtual void Cast();
};
} // namespace fight
class Thing {
  public:
    void Set(void*);
};
extern "C" void* Find(const char*, fight::TrackFactoryCasterTemplate*);
void Function(Thing* thing, const char* name) {
    fight::TrackFactoryCasterTemplate caster;
    thing->Set(Find(name, &caster));
}
