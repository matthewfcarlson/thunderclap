// STATUS: equivalent (tools/equiv.py level 3: 1186 inputs, branch coverage 10/10)
// audio::SeqEventSilence::vfunc_1 @ 0x00254850
// 0x00254850: audio::SeqEventSilence::vfunc_1: write the event (base fields, then two named values) to a text stream
struct Stream {
    char pad00[0x24];
    int indent;
};

struct Writer {
    Stream* out;
};

char FUN_00246f50(Stream* s, const char* fmt, ...);
char FUN_0024eb60(Writer* w, const char* name, void* value);
char FUN_0024eb60(Writer* w, const char* name, void* value);

namespace audio {

class SeqEvent {
public:
    virtual void v0();
    char vfunc_1(Writer* w);
    char pad04[4];
};

class SeqEventSilence : public SeqEvent {
public:
    char field_08[4];
    char field_0c[4];
    char field_10[4];
    int vfunc_1(Writer* w);
};

int SeqEventSilence::vfunc_1(Writer* w)
{
    if (!SeqEvent::vfunc_1(w))
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
