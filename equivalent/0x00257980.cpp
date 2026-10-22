// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::SequenceType::vfunc_2 @ 0x00257980
#include "decls/data/engine/audio.h"

typedef unsigned int size_t;
void* __cdecl FUN_00247530(void*);
namespace om { struct EntityType { virtual void vfunc_0(); virtual void vfunc_1(); }; }
namespace audio {
struct Sequence : om::EntityType {
    virtual void vfunc_2();
    char pad[0x24];
    void* firstEntry;
    void* firstAnchor;
    void* firstHead;
    void* firstTail;
    int firstCount;
    int field3c;
    int field40;
    void* secondEntry;
    void* secondAnchor;
    void* secondHead;
    void* secondTail;
    int secondCount;
};
struct SequenceType : om::EntityType { virtual Sequence* vfunc_2(); };
}
struct Sequence_257980 { void FUN_00244ea0(void*); };
__forceinline void* operator new(size_t, void* p) { return p; }
audio::Sequence* audio::SequenceType::vfunc_2() {
    audio::Sequence* result = (audio::Sequence*)FUN_00247530(((char*)((char*)&DAT_004e75b8 + 104)));
    if (result) {
        ((Sequence_257980*)result)->FUN_00244ea0(((char*)((char*)&DAT_004e75b8 + 104)));
        result = new (result) audio::Sequence;
        result->firstCount = 0;
        result->firstHead = &result->firstAnchor;
        result->firstTail = &result->firstAnchor;
        result->firstEntry = &result->firstAnchor;
        result->firstAnchor = &result->firstAnchor;
        result->field3c = 0;
        result->field40 = 0;
        result->secondCount = 0;
        result->secondHead = &result->secondAnchor;
        result->secondTail = &result->secondAnchor;
        result->secondEntry = &result->secondAnchor;
        result->secondAnchor = &result->secondAnchor;
    }
    return result;
}