// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// audio::Clip::vfunc_5 @ 0x00245680
// audio::Clip::vfunc_5 @ 0x00245680: loads a clip from a content stream, logging on failure
struct Stream {
    int FUN_00246f00(void *dst, int size, int count, int flag);
};

struct Loader {
    Stream *stream;
    void **name;
    void *source;
};

struct Names {
    const char *FUN_0023fb00();
};

struct Decoder {
    void *FUN_0025cbc0(Stream *stream, void *context, unsigned int version, void *source);
};

void *__cdecl FUN_0025c040();
Decoder *__cdecl FUN_00247530(void *registry);
void *__cdecl FUN_0024c710();
void *__cdecl FUN_00245390(void *decoded, void *source);
int __cdecl FUN_00246f50(void *log, const char *format, const char *arg);

namespace audio {
class Clip {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool vfunc_5(Loader *loader);
    char pad04[0x24];
    void *data;
    void *FUN_00243390();
};
}

bool audio::Clip::vfunc_5(Loader *loader)
{
    Loader *l = loader;
    l->stream->FUN_00246f00(&loader, 4, 1, 1);
    Decoder *decoder = FUN_00247530(FUN_0025c040());
    void *decoded;
    if (decoder) {
        void *source = l->source;
        FUN_00243390();
        decoded = decoder->FUN_0025cbc0(l->stream, FUN_0024c710(), (unsigned int)loader, source);
    } else {
        decoded = 0;
    }
    data = FUN_00245390(decoded, l->source);
    if (data == 0) {
        FUN_00243390();
        void *log = *l->name;
        FUN_00246f50(log, "Failed to load clip '%s'\n", ((Names *)FUN_0024c710())->FUN_0023fb00());
        return false;
    }
    return true;
}
