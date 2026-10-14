typedef unsigned int u32_247ba0;
namespace audio {
class StreamPlayerAllocator {
  public:
    virtual void vfunc_0(u32_247ba0 a, u32_247ba0 b, u32_247ba0 c, u32_247ba0 d);
    virtual void vfunc_1();
};
} // namespace audio
extern void __cdecl FUN_0024be00(u32_247ba0, u32_247ba0, u32_247ba0, u32_247ba0, u32_247ba0, u32_247ba0, u32_247ba0);
void audio::StreamPlayerAllocator::vfunc_0(u32_247ba0 a, u32_247ba0 b, u32_247ba0 c, u32_247ba0 d) {
    FUN_0024be00(c, 1, b, d, 0, 0, 1);
}