// cl-flags: /O2 /GR /GX
#include "gen/fight.h"

#include "compat/ptr.h"
extern "C" char DAT_0041b318[];

namespace hulkfight {
namespace motion {
class AccuracyLatencyTrack_1a0fd0 {
  public:
    virtual ~AccuracyLatencyTrack_1a0fd0();
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
class TrackFactory_1a0fd0 {};
} // namespace fight

namespace pure3d {
class Entity_1a0fd0 {};
} // namespace pure3d
namespace content {
class LoadObject_1a0fd0 {};
} // namespace content
namespace core {
class IRefCount_1a0fd0 {};
} // namespace core

extern "C" void* __cdecl Allocator(unsigned int size);
template <> void* fight::TrackFactoryTemplate<hulkfight::motion::AccuracyLatencyTrack>::vfunc_5() {
    hulkfight::motion::AccuracyLatencyTrack_1a0fd0* track =
        (hulkfight::motion::AccuracyLatencyTrack_1a0fd0*)Allocator(0x1c);
    if (track) {
        track->Init();
        *(hulk_intptr*)track = ((hulk_intptr)DAT_0041b318);
        track->field_c = 0;
        track->field_10 = -1.0f;
        track->field_14 = 0;
        track->field_18 = 1.0f;
        track->field_8 = 1;
        return (void*)(track);
    }
    return (void*)(0);
}
