// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// audio::HalRadicalAdpcmDecodeStream::vfunc_6 @ 0x00262da0
typedef unsigned int uint;
struct AdpcmHeader { uint info; };
uint __cdecl FUN_0024c4d0(AdpcmHeader* header, uint length);
namespace audio {
struct HalStream {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(uint offset, uint buffer, uint length);
};
struct HalRadicalAdpcmDecodeStream {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(uint offset, uint buffer, uint length);
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    HalStream* stream;
    AdpcmHeader header;
    uint start;
    uint end;
    uint decodedSize;
    char padding[4];
    uint state;
};
void HalRadicalAdpcmDecodeStream::vfunc_6(uint offset, uint buffer, uint length) {
    uint frames = ((header.info >> 4) & 31) * (FUN_0024c4d0(&header, length) >> 5);
    uint size = frames * 20;
    start = offset;
    decodedSize = size;
    end = offset - size + length;
    state = 3;
    stream->vfunc_6(end, buffer, size);
}
}
