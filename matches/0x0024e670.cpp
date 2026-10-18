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
extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
audio::SeqEventNestTrackType* audio::SeqEventNestTrackType::FUN_0024e670() {
    __int64 id = FUN_002672f0("SeqEventNestTrack", 0, 0);
    Field field;
    FUN_002605e0(field.FUN_0023fc40("Nest", 0), &id, 0x14, 4);
    field.FUN_00240060();
    vtable = DAT_004298b0;
    return this;
}
