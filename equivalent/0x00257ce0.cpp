// STATUS: equivalent (tools/equiv.py level 3: 407 inputs, branch coverage 10/10)
// FUN_00257ce0 @ 0x00257ce0
struct Stream;
struct Sub_257ce0 { char data[4]; void FUN_002607a0(); };

namespace audio {
class SeqTrack {
public:
    virtual ~SeqTrack() throw() { sub.FUN_002607a0(); }
    virtual bool vfunc_1(Stream *s);
    char pad04[0x18];
    Sub_257ce0 sub;
};
}

struct Pool_257ce0 { audio::SeqTrack *FUN_00262090(); };
void *__cdecl FUN_00262030();
Pool_257ce0 *__cdecl FUN_00247530(void *pool);
void __cdecl FUN_00247550(void *pool, audio::SeqTrack *t);
bool __cdecl FUN_0025abd0(Stream *s, unsigned int *count);

// The stream pointer's stack slot doubles as the out-count.
union StreamArg_257ce0 {
    Stream *stream;
    unsigned int count;
};

class Mix {
public:
    void FUN_00257c20(audio::SeqTrack *t);
    bool FUN_00257ce0(StreamArg_257ce0 arg);
};

bool Mix::FUN_00257ce0(StreamArg_257ce0 arg)
{
    Stream *s = arg.stream;
    if (!FUN_0025abd0(s, &arg.count))
        return false;
    for (unsigned int i = 0; i < arg.count; i++) {
        Pool_257ce0 *p = FUN_00247530(FUN_00262030());
        audio::SeqTrack *t = p ? p->FUN_00262090() : 0;
        if (!t->vfunc_1(s)) {
            t->audio::SeqTrack::~SeqTrack();
            FUN_00247550(FUN_00262030(), t);
            return false;
        }
        FUN_00257c20(t);
    }
    return true;
}
