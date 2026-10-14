// STATUS: equivalent (tools/equiv.py level 3: 1543 inputs, branch coverage 12/12)
// audio::SeqEventLogicRepeat::vfunc_1 @ 0x00254b90
// audio::SeqEventLogicRepeat::vfunc_1: write the event (base fields, then min/max repeat counts) to a text stream
struct Writer_254b90 {
    char pad00[0x24];
    int indent;
};

struct Archive_254b90 {
    Writer_254b90* writer;
};

char FUN_00246f50(Writer_254b90* writer, const char* fmt, ...);
char FUN_0024eb60(Archive_254b90* ar, const char* name, unsigned int* value);

namespace audio {

class SeqEvent {
public:
    virtual char vfunc_0(Archive_254b90* ar);
    virtual char vfunc_1(Archive_254b90* ar);
    char pad04[4];
};

class SeqEventContainer : public SeqEvent {
public:
    virtual char vfunc_0(Archive_254b90* ar);
    virtual char vfunc_1(Archive_254b90* ar);
    char pad08[12];
};

class SeqEventLogicRepeat : public SeqEventContainer {
public:
    virtual char vfunc_0(Archive_254b90* ar);
    virtual char vfunc_1(Archive_254b90* ar);
    unsigned int minTimes;
    unsigned int maxTimes;
};

char SeqEventLogicRepeat::vfunc_1(Archive_254b90* ar)
{
    if (!SeqEvent::vfunc_1(ar))
        return 0;
    if (!FUN_00246f50(ar->writer, "\n[\n"))
        return 0;
    ar->writer->indent++;
    if (!SeqEventContainer::vfunc_1(ar))
        return 0;
    if (!FUN_0024eb60(ar, "mMinTimes", &minTimes))
        return 0;
    if (!FUN_0024eb60(ar, "mMaxTimes", &maxTimes))
        return 0;
    ar->writer->indent--;
    if (!FUN_00246f50(ar->writer, "]\n"))
        return 0;
    return 1;
}

}
