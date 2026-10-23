#include "gen/fight.h"

typedef unsigned int size_t;
void* __cdecl operator new(size_t) throw();
namespace hulkfight {
namespace ai {
class BaseTrack {
  public:
    BaseTrack() throw();
    virtual void v0();
    char pad[4];
};
class TokenTrack_114d70 : public BaseTrack {
  public:
    TokenTrack_114d70() throw() {
        *(int*)((char*)this + 12) = 0;
        *(float*)((char*)this + 16) = -1.0f;
        *((char*)this + 20) = 0;
        *(int*)((char*)this + 8) = 1;
    }
    virtual void v0();
    char pad2[16];
};
} // namespace ai
} // namespace hulkfight
namespace fight {

} // namespace fight
template <> void* fight::TrackFactoryTemplate<hulkfight::ai::TokenTrack>::vfunc_5() {
    return (void*)(new hulkfight::ai::TokenTrack_114d70);
}
