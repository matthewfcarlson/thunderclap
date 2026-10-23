#include "decls/address.h"
struct Field {
    char space[12];
    Field* FUN_0023fc40(const char*, int);
    void FUN_00240060();
};
namespace audio {
struct SeqEventClipType {
    void** vtable;
    void FUN_002605e0(Field*, __int64*, int, int);
    SeqEventClipType* FUN_00255f70();
};
} // namespace audio
extern void* DAT_0042a584[];
audio::SeqEventClipType* audio::SeqEventClipType::FUN_00255f70() {
    __int64 id = FUN_002672f0("SeqEventClip", 0, 0);
    Field field;
    FUN_002605e0(field.FUN_0023fc40("Clip", 0), &id, 0x28, 8);
    field.FUN_00240060();
    vtable = DAT_0042a584;
    return this;
}
