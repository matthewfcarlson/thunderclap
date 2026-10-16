namespace hulkfight {
namespace ai {
class MotionClosestWaypointTrack {};
} // namespace ai
} // namespace hulkfight
namespace fight {
template <class T> class TrackFactoryCasterTemplate {
  public:
    TrackFactoryCasterTemplate();
    virtual void dummy();
};
} // namespace fight
fight::TrackFactoryCasterTemplate<hulkfight::ai::MotionClosestWaypointTrack>::TrackFactoryCasterTemplate() {}