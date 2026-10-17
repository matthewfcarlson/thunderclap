// STATUS: equivalent (tools/equiv.py level 3: 2886 inputs, branch coverage 2/2)
// audio::MixBuss::vfunc_0 @ 0x0025a330
struct BussData {
    char reserved[0x24];
    int nameCount;
};
unsigned int __cdecl FUN_00246f50(BussData *data, const char *format, ...);
namespace audio {
struct MixBuss {
    virtual unsigned int vfunc_0(BussData **data);
    virtual void vfunc_1();
};
}
unsigned int audio::MixBuss::vfunc_0(BussData **data)
{
    unsigned int result = FUN_00246f50(*data, "[\n");
    if ((unsigned char)result != 0) {
        ++(*data)->nameCount;
        result = FUN_00246f50(*data, "%s ", "mName");
    }
    return result & 0xffffff00U;
}