// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CCameraManager,void,bool,bool,bool>::vfunc_2 @ 0x0009ab70
#include "compat/ptr.h"
struct CCameraManager;
struct Method3 {
    char pad[0x1c];
    void (__fastcall *callback)(CCameraManager *, Method3 *, unsigned int, unsigned int, unsigned int);
    void vfunc_2(CCameraManager *camera, const unsigned char *arguments, void *unused);
};
void Method3::vfunc_2(CCameraManager *camera, const unsigned char *arguments, void *unused) {
    unsigned int first = ((hulk_uintptr)arguments & ~255u) | arguments[0];
    callback(camera, this, first, arguments[4], arguments[8]);
}