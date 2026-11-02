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
extern "C" void* FUN_00236ac0(const char*, fight::TrackFactoryCasterTemplate<hulkfight::NISSoundTrack>*);
extern "C" void FUN_00132500(TrackManager* manager, const char* name) {
    fight::TrackFactoryCasterTemplate<hulkfight::NISSoundTrack> caster;
    manager->Add(FUN_00236ac0(name, &caster));
}