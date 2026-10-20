// STATUS: equivalent (tools/equiv.py level 3: 19941 inputs, branch coverage 2/2)
// audio::SeqEventChannelVolumesType::vfunc_3 @ 0x00252070
#include "gen/audio.h"

#include "decls/data/engine/audio.h"

typedef unsigned int size_t;
inline void* __cdecl operator new(size_t, void* p) { return p; }
void* __cdecl FUN_00247530(void*);
int __cdecl FUN_002673a0(const char*, int);
namespace audio {
struct SeqEventChannelVolumes_252070 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    int fields[5];
    int capacity;
    int name;
    void FUN_0025fd00();
};

}
void* audio::SeqEventChannelVolumesType::vfunc_3() {
    SeqEventChannelVolumes_252070* result = (SeqEventChannelVolumes_252070*)FUN_00247530(((char*)((char*)&DAT_004e6d28 + 8)));
    if (!result) return (void*)(0);
    result->FUN_0025fd00();
    new (result) SeqEventChannelVolumes_252070;
    result->capacity = 1000;
    result->name = FUN_002673a0("stitched", 0);
    result->fields[1] = 0;
    result->fields[2] = 0;
    result->fields[3] = 0;
    result->fields[4] = 0;
    return (void*)(result);
}
