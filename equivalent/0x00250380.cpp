// STATUS: equivalent (tools/equiv.py level 3: 1600 inputs, branch coverage 10/10)
// audio::SeqEventWait::vfunc_1 @ 0x00250380
struct Stream {
    char pad00[0x24];
    int indent;
};

struct Writer_250380 {
    Stream *out;
};

char FUN_00246f50(Stream *s, const char *fmt, ...);
char FUN_0024e600(Writer_250380 *w, const char *name, void *value);

namespace audio {

class SeqEvent {
public:
    virtual void v0();
    char vfunc_1(Writer_250380 *w);
    char pad04[4];
};

class SeqEventWait : public SeqEvent {
public:
    char field_08[4];
    int vfunc_1(Writer_250380 *w);
};

int SeqEventWait::vfunc_1(Writer_250380 *w)
{
    if (!SeqEvent::vfunc_1(w))
        return 0;
    if (!FUN_00246f50(w->out, "\n[\n"))
        return 0;
    w->out->indent++;
    if (!FUN_0024e600(w, "mExpression", &field_08))
        return 0;
    if (!FUN_00246f50(w->out, "\n"))
        return 0;
    w->out->indent--;
    if (!FUN_00246f50(w->out, "]\n"))
        return 0;
    return 1;
}

}
