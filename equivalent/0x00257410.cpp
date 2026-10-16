// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 10/10)
// audio::Sequence::vfunc_3 @ 0x00257410
#include "gen/audio.h"

struct Stream_257410 {
    char pad0[0x24];
    int indent;
};

bool __cdecl FUN_00246f50(Stream_257410 *s, const char *fmt, ...);

namespace audio {
struct Sequence_nv_257410 {
    bool FUN_00257320(Stream_257410 **w);
    bool FUN_00257290(Stream_257410 **w);
};
}
bool audio::Sequence::vfunc_3(void* __p0) { Stream_257410 ** w = (Stream_257410 **)__p0;

    if (!FUN_00246f50(*w, "Version %d\n", 1))
        return false;
    if (!FUN_00246f50(*w, "[\n"))
        return false;
    (*w)->indent++;
    if (!((Sequence_nv_257410*)this)->FUN_00257320(w))
        return false;
    if (!((Sequence_nv_257410*)this)->FUN_00257290(w))
        return false;
    (*w)->indent--;
    if (!FUN_00246f50(*w, "]\n"))
        return false;
    return true;
}
