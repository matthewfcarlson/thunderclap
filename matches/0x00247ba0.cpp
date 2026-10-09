typedef unsigned int u32;
namespace audio {
class StreamPlayerAllocator {
  public:
    virtual void vfunc_0(u32 a, u32 b, u32 c, u32 d);
    virtual void vfunc_1();
};
} // namespace audio
extern void __cdecl FUN_0024be00(u32, u32, u32, u32, u32, u32, u32);
void audio::StreamPlayerAllocator::vfunc_0(u32 a, u32 b, u32 c, u32 d) {
    FUN_0024be00(c, 1, b, d, 0, 0, 1);
}