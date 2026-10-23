#include "decls/address.h"
struct Field {
    char space[12];
    Field* FUN_0023fc40(const char*, int);
    void FUN_00240060();
};
namespace audio {
struct SeqEventVarPitchRandType {
    void** vtable;
    void FUN_002605e0(Field*, __int64*, int, int);
    SeqEventVarPitchRandType* FUN_002534b0();
};
} // namespace audio
extern void* DAT_0042a16c[];
audio::SeqEventVarPitchRandType* audio::SeqEventVarPitchRandType::FUN_002534b0() {
    __int64 id = FUN_002672f0("SeqEventVarPitchRand", 0, 0);
    Field field;
    FUN_002605e0(field.FUN_0023fc40("Pitch?", 0), &id, 16, 4);
    field.FUN_00240060();
    vtable = DAT_0042a16c;
    return this;
}