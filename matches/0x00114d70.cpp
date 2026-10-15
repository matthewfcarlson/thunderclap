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
class TokenTrack : public BaseTrack {
  public:
    TokenTrack() throw() {
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
template <class T> class TrackFactoryTemplate {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual T* vfunc_5();
};
template <> hulkfight::ai::TokenTrack* TrackFactoryTemplate<hulkfight::ai::TokenTrack>::vfunc_5() {
    return new hulkfight::ai::TokenTrack;
}
} // namespace fight