// STATUS: equivalent (tools/equiv.py level 3: 1534 inputs, branch coverage 10/10)
// audio::SeqEventVarPitchRand::vfunc_1 @ 0x002535a0
// 0x002535a0: audio::SeqEventVarPitchRand::vfunc_1: write the event (base fields, then two named values) to a text stream
struct Stream {
    char pad00[0x24];
    int indent;
};

struct Writer_2535a0 {
    Stream* out;
};

char FUN_00246f50(Stream* s, const char* fmt, ...);
char FUN_00252470(Writer_2535a0* w, const char* name, void* value);
char FUN_00252470(Writer_2535a0* w, const char* name, void* value);

namespace audio {

class SeqEvent {
public:
    virtual void v0();
    char vfunc_1(Writer_2535a0* w);
    char pad04[4];
};

class SeqEventVarPitchRand : public SeqEvent {
public:
    char field_08[4];
    char field_0c[4];
    char field_10[4];
    int vfunc_1(Writer_2535a0* w);
};

int SeqEventVarPitchRand::vfunc_1(Writer_2535a0* w)
{
    if (!SeqEvent::vfunc_1(w))
        return 0;
    if (!FUN_00246f50(w->out, "\n[\n"))
        return 0;
    w->out->indent++;
    if (!FUN_00252470(w, "mMinPitch", &field_08))
        return 0;
    if (!FUN_00252470(w, "mMaxPitch", &field_0c))
        return 0;
    w->out->indent--;
    if (!FUN_00246f50(w->out, "]\n"))
        return 0;
    return 1;
}

}
