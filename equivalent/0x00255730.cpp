// STATUS: equivalent (tools/equiv.py level 3: 101 inputs, branch coverage 24/24)
// audio::SeqEventCrossFade::vfunc_1 @ 0x00255730
struct Writer {
    char pad0[0x24];
    int indent;
};

struct Archive {
    Writer *writer;
};

struct NameBuf {
    char data[4];
};

struct BeatSet {
    char data[4];
};

struct TrackName {
    char data[0xc];
};

char FUN_00246f50(Writer *writer, const char *fmt, ...);
char FUN_0024eb60(Archive *ar, const char *name, unsigned int *value);
char FUN_00250ef0(Archive *ar, const char *name, char *value);
char FUN_0024e600(Archive *ar, const char *name, TrackName *value);
char FUN_0024eff0(Archive *ar, const char *name, NameBuf *value);
char FUN_00250640(Archive *ar, const char *name, BeatSet *value);

namespace audio {

class SeqEvent {
public:
    virtual char vfunc_0(Archive *ar);
    virtual char vfunc_1(Archive *ar);
    virtual char vfunc_2(Archive *ar);
    virtual char vfunc_3(Archive *ar);
    virtual char vfunc_4(Archive *ar);
    virtual char vfunc_5(Archive *ar);
    char pad04[4];
};

class SeqEventCrossFade : public SeqEvent {
public:
    virtual char vfunc_0(Archive *ar);
    virtual char vfunc_1(Archive *ar);
    unsigned int fadeInStartMs;
    unsigned int fadeInMs;
    unsigned int fadeOutStartMs;
    unsigned int fadeOutMs;
    char targetResume;
    char isSynchronous;
    char pad1a[2];
    TrackName seqTrackName;
    NameBuf beatLayerNameBuf;
    BeatSet beatSet;
};

char SeqEventCrossFade::vfunc_1(Archive *ar)
{
    if (!SeqEvent::vfunc_1(ar))
        return 0;
    if (!FUN_00246f50(ar->writer, "\n[\n"))
        return 0;
    ar->writer->indent++;
    if (!FUN_0024eb60(ar, "mFadeInStartMs", &fadeInStartMs))
        return 0;
    if (!FUN_0024eb60(ar, "mFadeInMs", &fadeInMs))
        return 0;
    if (!FUN_0024eb60(ar, "mFadeOutStartMs", &fadeOutStartMs))
        return 0;
    if (!FUN_0024eb60(ar, "mFadeOutMs", &fadeOutMs))
        return 0;
    if (!FUN_00250ef0(ar, "mTargetResume", &targetResume))
        return 0;
    if (!FUN_00250ef0(ar, "mIsSynchronous", &isSynchronous))
        return 0;
    if (!FUN_0024e600(ar, "mSeqTrackName", &seqTrackName))
        return 0;
    if (!FUN_0024eff0(ar, "mBeatLayerNameBuf", &beatLayerNameBuf))
        return 0;
    if (!FUN_00250640(ar, "mBeatSet", &beatSet))
        return 0;
    ar->writer->indent--;
    if (!FUN_00246f50(ar->writer, "]\n"))
        return 0;
    return 1;
}

}
