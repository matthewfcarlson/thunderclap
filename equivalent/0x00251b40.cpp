// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00251b40 @ 0x00251b40
// FUN_00251b40 @ 0x00251b40
#include "decls/address.h"
typedef __int64 Int64;
struct ChannelValue {
    char data[12];
    // equiv-conv: FUN_0023fc40 ecx stack stack
    ChannelValue *FUN_0023fc40(const char *, int);
    void FUN_00240060();
};
namespace audio {
struct SeqEventChannelVolumesType {
    virtual void placeholder();
    // equiv-conv: FUN_002605e0 ecx stack stack stack stack
    void FUN_002605e0(ChannelValue *, const Int64 *, int, int);
    SeqEventChannelVolumesType *FUN_00251b40();
};
}
audio::SeqEventChannelVolumesType *audio::SeqEventChannelVolumesType::FUN_00251b40() {
    Int64 value = FUN_002672f0("SeqEventChannelVolumes", 0, 0);
    ChannelValue channel;
    ChannelValue *result = channel.FUN_0023fc40("ChVol", 0);
    FUN_002605e0(result, &value, 32, 4);
    channel.FUN_00240060();
    SeqEventChannelVolumesType marker;
    *(unsigned int *)this = *(unsigned int *)&marker;
    return this;
}
