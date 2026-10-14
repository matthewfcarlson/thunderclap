typedef unsigned int u32_262f70;
typedef unsigned char u8;
extern u32_262f70 __cdecl FUN_0024c2c0(void*);
extern u8 __cdecl FUN_0024c2b0(u32_262f70);
extern u32_262f70 __cdecl FUN_0024c2f0(void*);
namespace audio {
class HalRsdFileStream {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual u32_262f70 vfunc_3();
    char pad[0x28 - 4];
    u32_262f70 vfunc_3_impl();
};
u32_262f70 HalRsdFileStream::vfunc_3() {
    void* p = (char*)this + 0x28;
    u32_262f70 x = FUN_0024c2c0(p);
    if (FUN_0024c2b0(x))
        return FUN_0024c2f0(p);
    return 0x800;
}
} // namespace audio