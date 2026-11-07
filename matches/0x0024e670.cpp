#include "decls/address.h"
#include "decls/data/records.h"
struct Field {
    char space[12];
    Field* FUN_0023fc40(const char*, int);
    void FUN_00240060();
};
namespace audio {
struct SeqEventNestTrackType {
    void** vtable;
    void FUN_002605e0(Field*, __int64*, int, int);
    SeqEventNestTrackType* FUN_0024e670();
};
} // namespace audio
extern void* DAT_004298b0[];
audio::SeqEventNestTrackType* audio::SeqEventNestTrackType::FUN_0024e670() {
    HULK_SIZE32(AudioSeqEventNestTrack, 0x14);
    __int64 id = FUN_002672f0("SeqEventNestTrack", 0, 0);
    Field field;
    FUN_002605e0(field.FUN_0023fc40("Nest", 0), &id, (int)sizeof(AudioSeqEventNestTrack), (int)__alignof(AudioSeqEventNestTrack));
    field.FUN_00240060();
    vtable = DAT_004298b0;
    return this;
}
