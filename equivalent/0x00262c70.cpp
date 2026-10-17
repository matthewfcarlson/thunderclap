// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 5/5)
// audio::HalRadicalAdpcmDecodeStream::vfunc_1 @ 0x00262c70
namespace audio {
class HalStream {
public:
    virtual void vfunc_0();
    virtual int vfunc_1();
};
class HalRadicalAdpcmDecodeStream : public HalStream {
public:
    char padding[0x18];
    unsigned int state;
    virtual int vfunc_1();
};
int HalRadicalAdpcmDecodeStream::vfunc_1() {
    switch (state) {
    case 0: return 0;
    case 1: return 1;
    case 2:
    case 3:
    case 4: return 2;
    default: return 3;
    }
}
}
