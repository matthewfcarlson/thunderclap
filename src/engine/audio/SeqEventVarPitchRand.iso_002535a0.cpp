// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00253370..0x00253750 (kind game, layer engine, confidence high), dominant class audio::SeqEventVarPitchRand
// (tree_prelude.h: not needed)


// 0x002535a0 audio::SeqEventVarPitchRand::vfunc_1 (129 B): equivalent/0x002535a0.cpp [isolated: compile error C2732: linkage specification contradicts earlier specification for 'fn_002535a0::FUN_00252470']
// sym: ?vfunc_1@SeqEventVarPitchRand@audio@fn_f064a97a@@QAEHPAUWriter_2535a0@3@@Z
namespace fn_f064a97a {} using namespace fn_f064a97a;
namespace fn_f064a97a {
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
extern "C" char FUN_00252470(Writer_2535a0* w, const char* name, void* value);
extern "C" char FUN_00252470(Writer_2535a0* w, const char* name, void* value);

namespace audio {

class SeqEvent {
public:
    virtual void v0();
    char vfunc_1_0025fd40(Writer_2535a0* w);
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
    if (!SeqEvent::vfunc_1_0025fd40(w))
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
} // namespace fn_f064a97a

