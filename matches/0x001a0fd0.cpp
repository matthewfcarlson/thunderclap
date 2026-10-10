// cl-flags: /O2 /GR /GX

namespace hulkfight {
namespace motion {
class AccuracyLatencyTrack {
  public:
    virtual ~AccuracyLatencyTrack();
    int field_4;
    int field_8;
    int field_c;
    float field_10;
    int field_14;
    float field_18;
    void Init();
};
} // namespace motion
} // namespace hulkfight

namespace fight {
class TrackFactory {};
template <typename T> class TrackFactoryTemplate : public TrackFactory {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual T* vfunc_5();
};
} // namespace fight

namespace pure3d {
class Entity {};
} // namespace pure3d
namespace content {
class LoadObject {};
} // namespace content
namespace core {
class IRefCount {};
} // namespace core

extern "C" void* __cdecl Allocator(unsigned int size);

hulkfight::motion::AccuracyLatencyTrack*
fight::TrackFactoryTemplate<hulkfight::motion::AccuracyLatencyTrack>::vfunc_5() {
    hulkfight::motion::AccuracyLatencyTrack* track =
        (hulkfight::motion::AccuracyLatencyTrack*)Allocator(0x1c);
    if (track) {
        track->Init();
        *(int*)track = 0x41b318;
        track->field_c = 0;
        track->field_10 = -1.0f;
        track->field_14 = 0;
        track->field_18 = 1.0f;
        track->field_8 = 1;
        return track;
    }
    return 0;
}