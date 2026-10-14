// STATUS: equivalent (tools/equiv.py level 3: 1534 inputs, branch coverage 10/10)
// audio::SeqEventClip::vfunc_1 @ 0x00256070
// 0x00256070: audio::SeqEventClip::vfunc_1: write the event (base fields, then two named values) to a text stream
struct Stream {
    char pad00[0x24];
    int indent;
};

struct Writer {
    Stream* out;
};

char FUN_00246f50(Stream* s, const char* fmt, ...);
char FUN_00250ef0(Writer* w, const char* name, void* value);
char FUN_00254000(Writer* w, const char* name, void* value);

namespace audio {

class SeqEvent {
public:
    virtual void v0();
    char vfunc_1(Writer* w);
    char pad04[4];
};

class SeqEventClip : public SeqEvent {
public:
    char field_08[4];
    char field_0c[4];
    char field_10[4];
    int vfunc_1(Writer* w);
};

int SeqEventClip::vfunc_1(Writer* w)
{
    if (!SeqEvent::vfunc_1(w))
        return 0;
    if (!FUN_00246f50(w->out, "\n[\n"))
        return 0;
    w->out->indent++;
    if (!FUN_00250ef0(w, "mIsLooping", &field_08))
        return 0;
    if (!FUN_00254000(w, "mRsdFile", &field_10))
        return 0;
    w->out->indent--;
    if (!FUN_00246f50(w->out, "]\n"))
        return 0;
    return 1;
}

}
