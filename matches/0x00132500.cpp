namespace hulkfight {
class NISSoundTrack;
}
namespace fight {
template <class T> class TrackFactoryCasterTemplate {
  public:
    virtual void Cast();
};
} // namespace fight
class TrackManager {
  public:
    void Add(void*);
};
extern "C" void* Lookup(const char*, fight::TrackFactoryCasterTemplate<hulkfight::NISSoundTrack>*);
void Make(TrackManager* manager, const char* name) {
    fight::TrackFactoryCasterTemplate<hulkfight::NISSoundTrack> caster;
    manager->Add(Lookup(name, &caster));
}