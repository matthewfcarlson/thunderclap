// STATUS: equivalent (tools/equiv.py level 3: 19928 inputs, branch coverage 2/2)
// CSoundResourceManager::vfunc_3 @ 0x001ea630
// cl-flags: /GS
#include "compat/ptr.h"
#include "gen/global.h"


struct Text_1ea630 {
    char data[0x2c];
    void FUN_00247270(const char *s, int len, int flags);
};
struct Handle_1ea630 {
    char data[0xa0];
    void FUN_002458f0(Text_1ea630 *src);
};
int __cdecl FUN_00246100(Handle_1ea630 *h);

struct Frame_1ea630 {
    Text_1ea630 text;
    Handle_1ea630 handle;
};

struct CSoundResourceManager_nv_1ea630 {
    void FUN_001ea5a0(int id);
};

void CSoundResourceManager::vfunc_3(hulk_intptr __p0, int unused) { const char * name = (const char *)__p0;

    Frame_1ea630 f;
    int len = 0;
    while (name[len] != 0)
        len++;
    f.text.FUN_00247270(name, len, 0);
    f.handle.FUN_002458f0(&f.text);
    ((CSoundResourceManager_nv_1ea630*)this)->FUN_001ea5a0(FUN_00246100(&f.handle));
}
