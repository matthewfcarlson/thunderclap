// STATUS: equivalent (tools/equiv.py level 3: 1186 inputs, branch coverage 10/10)
// audio::SeqEventLogicOr::vfunc_1 @ 0x00254fc0
struct Writer {
    char pad0[0x24];
    int indent;
};

struct Archive {
    Writer *writer;
};

struct Spread {
    char data[4];
};

char FUN_00246f50(Writer *writer, const char *fmt, ...);
char FUN_00252470(Archive *ar, const char *name, Spread *value);

namespace audio {

class SeqEvent {
public:
    virtual char vfunc_0(Archive *ar);
    virtual char vfunc_1(Archive *ar);
    virtual char vfunc_2(Archive *ar);
    virtual char vfunc_3(Archive *ar);
    virtual char vfunc_4(Archive *ar);
    char pad04[0x10];
};

class SeqEventContainer {
public:
    char vfunc_1(Archive *ar);
};

class SeqEventLogicOr : public SeqEvent {
public:
    virtual char vfunc_1(Archive *ar);
    Spread spread;
};

char SeqEventLogicOr::vfunc_1(Archive *ar)
{
    if (!SeqEvent::vfunc_1(ar))
        return 0;
    if (!FUN_00246f50(ar->writer, "\n[\n"))
        return 0;
    ar->writer->indent++;
    if (!FUN_00252470(ar, "mSpread", &spread))
        return 0;
    if (!((SeqEventContainer *)this)->vfunc_1(ar))
        return 0;
    ar->writer->indent--;
    if (!FUN_00246f50(ar->writer, "]\n"))
        return 0;
    return 1;
}

}
