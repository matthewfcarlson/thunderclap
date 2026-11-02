typedef unsigned int u32_247ba0;
namespace audio {
class StreamPlayerAllocator {
  public:
    virtual void vfunc_0(u32_247ba0 a, u32_247ba0 b, u32_247ba0 c, u32_247ba0 d);
    virtual void vfunc_1();
};
} // namespace audio
extern "C" void * __cdecl FUN_0024be00(int, int, int, int, int, int, int);
void audio::StreamPlayerAllocator::vfunc_0(u32_247ba0 a, u32_247ba0 b, u32_247ba0 c, u32_247ba0 d) {
    FUN_0024be00((unsigned int)c, 1, (unsigned int)b, (unsigned int)d, 0, 0, 1);
}