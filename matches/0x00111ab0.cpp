namespace hulkfight {
namespace ai {
class SemaphoreWaitTrack;
}
} // namespace hulkfight
namespace fight {
template <class T> class TrackFactoryCasterTemplate {
  public:
    TrackFactoryCasterTemplate();
    virtual void f();
};
template <> TrackFactoryCasterTemplate<hulkfight::ai::SemaphoreWaitTrack>::TrackFactoryCasterTemplate() {}
} // namespace fight