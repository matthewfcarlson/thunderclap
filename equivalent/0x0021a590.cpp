// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 7/8, incomplete)
// FUN_0021a590 @ 0x0021a590
#include "compat/ptr.h"
struct Stream { hulk_uintptr remaining; unsigned char *cursor; unsigned char *(__cdecl *refill)(void *, void *, unsigned int *); void *arg1; void *arg2; };
extern "C" unsigned int __cdecl FUN_0021a590(void *stream)
{
    if (((Stream *)stream)->remaining == 0) {
        unsigned int count = (unsigned int)((Stream *)stream);
        unsigned char *data = ((Stream *)stream)->refill(((Stream *)stream)->arg2, ((Stream *)stream)->arg1, &count);
        if (data == 0 || count == 0)
            return 0xffffffff;
        ((Stream *)stream)->cursor = data;
        ((Stream *)stream)->remaining = count - 1;
        ((Stream *)stream)->cursor = data + 1;
        ((Stream *)stream)->remaining = count;
        ((Stream *)stream)->cursor = data;
    }
    return *((Stream *)stream)->cursor;
}