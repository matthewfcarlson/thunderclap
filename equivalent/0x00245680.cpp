// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// audio::Clip::vfunc_5 @ 0x00245680
// audio::Clip::vfunc_5 @ 0x00245680: loads a clip from a content stream, logging on failure
#include "gen/audio.h"

struct Stream_245680 {
    int FUN_00246f00(void *dst, int size, int count, int flag);
};

struct Loader_245680 {
    Stream_245680 *stream;
    void **name;
    void *source;
};

struct Names_245680 {
    const char *FUN_0023fb00();
};

struct OmHalStream_nv_245680 {
    void *FUN_0025cbc0(Stream_245680 *stream, void *context, unsigned int version, void *source);
};

void *__cdecl FUN_0025c040();
::audio::OmHalStream *__cdecl FUN_00247530(void *registry);
void *__cdecl FUN_0024c710();
void *__cdecl FUN_00245390(void *decoded, void *source);
int __cdecl FUN_00246f50(void *log, const char *format, const char *arg);

namespace audio {
struct Clip_nv_245680 {
    void *FUN_00243390();
};
}
bool audio::Clip::vfunc_5(int __p0) { Loader_245680 * loader = (Loader_245680 *)__p0;

    Loader_245680 *l = loader;
    l->stream->FUN_00246f00(&loader, 4, 1, 1);
    ::audio::OmHalStream *decoder = FUN_00247530(FUN_0025c040());
    void *decoded;
    if (decoder) {
        void *source = l->source;
        ((Clip_nv_245680*)this)->FUN_00243390();
        decoded = ((OmHalStream_nv_245680*)(decoder))->FUN_0025cbc0(l->stream, FUN_0024c710(), (unsigned int)loader, source);
    } else {
        decoded = 0;
    }
    (*(void * *)&this->f_28) = FUN_00245390(decoded, l->source);
    if ((*(void * *)&this->f_28) == 0) {
        ((Clip_nv_245680*)this)->FUN_00243390();
        void *log = *l->name;
        FUN_00246f50(log, "Failed to load clip '%s'\n", ((Names_245680 *)FUN_0024c710())->FUN_0023fb00());
        return false;
    }
    return true;
}
