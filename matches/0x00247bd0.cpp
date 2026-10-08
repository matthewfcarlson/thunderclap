typedef unsigned int u32;
namespace audio {
class StreamPlayerAllocator {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(u32, u32);
};
}
extern void __cdecl FUN_0024bf90(u32);
void audio::StreamPlayerAllocator::vfunc_1(u32 a, u32 b) {
    FUN_0024bf90(b);
}