// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00254620..0x00254a50 (kind game, layer engine, confidence high), dominant class audio::SeqEventSilence
// (tree_prelude.h: not needed)


// 0x00254850 audio::SeqEventSilence::vfunc_1 (129 B): equivalent/0x00254850.cpp [isolated: compile error C2732: linkage specification contradicts earlier specification for 'fn_00254850::FUN_0024eb60']
// sym: ?vfunc_1@SeqEventSilence@audio@fn_f4dcd3fd@@QAEHPAUWriter_254850@3@@Z @93d2e3874a6d @w8d6b3899068a
namespace fn_f4dcd3fd {} using namespace fn_f4dcd3fd;
namespace fn_f4dcd3fd {
// STATUS: equivalent (tools/equiv.py level 3: 1186 inputs, branch coverage 10/10)
// audio::SeqEventSilence::vfunc_1 @ 0x00254850
// 0x00254850: audio::SeqEventSilence::vfunc_1: write the event (base fields, then two named values) to a text stream
struct Stream {
    char pad00[0x24];
    int indent;
};

struct Writer_254850 {
    Stream* out;
};

char FUN_00246f50(Stream* s, const char* fmt, ...);
extern "C" char FUN_0024eb60(Writer_254850* w, const char* name, void* value);
extern "C" char FUN_0024eb60(Writer_254850* w, const char* name, void* value);

namespace audio {

class SeqEvent {
public:
    virtual void v0();
    char vfunc_1_0025fd40(Writer_254850* w);
    char pad04[4];
};

class SeqEventSilence : public SeqEvent {
public:
    char field_08[4];
    char field_0c[4];
    char field_10[4];
    int vfunc_1(Writer_254850* w);
};

int SeqEventSilence::vfunc_1(Writer_254850* w)
{
    if (!SeqEvent::vfunc_1_0025fd40(w))
        return 0;
    if (!FUN_00246f50(w->out, "\n[\n"))
        return 0;
    w->out->indent++;
    if (!FUN_0024eb60(w, "mMinTimeMs", &field_08))
        return 0;
    if (!FUN_0024eb60(w, "mMaxTimeMs", &field_0c))
        return 0;
    w->out->indent--;
    if (!FUN_00246f50(w->out, "]"))
        return 0;
    return 1;
}

}
} // namespace fn_f4dcd3fd

