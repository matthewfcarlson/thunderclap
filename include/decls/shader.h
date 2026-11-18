// (sweep-allocsize) pure3d::Shader (RTTI .?AVShader@pure3d@@, vftable 0x0042cb44) as the sources that allocate it see
// it: the game builds a default shader with `FUN_00263ea0(0x20)` and its constructor 0x0028edb0 (ShaderVectorBroadcast.cpp:
// Entity's constructor 0x0027b070, the vftable, the flag and the value cleared, the pddi shader from the device
// DAT_0052c2a0's "simple"). The allocations are sizeof(HulkShader): 0x20 on the 32-bit builds, natively Entity's 0x14
// bytes, the pddi shader on 8 and the words after it (gen/pure3d.h's pure3d::Shader declares the words up to 0x1c; the
// allocation keeps one more, which the constructor does not write). Only the TUs that allocate it include this header
// (D74). Declare no namespaces here.
#ifndef HULK_DECLS_SHADER_H
#define HULK_DECLS_SHADER_H

#include "compat/ptr.h"

#ifndef HULK_SIZE32   // (as records.h defines it: a compile error on the 32-bit builds unless sizeof(T) is n)
#define HULK_SIZE32_CAT2(a, b) a##b
#define HULK_SIZE32_CAT(a, b) HULK_SIZE32_CAT2(a, b)
#define HULK_SIZE32(T, n) \
    typedef char HULK_SIZE32_CAT(hulk_size32_, __LINE__)[(sizeof(void*) != 4 || sizeof(T) == (n)) ? 1 : -1]
#endif

struct HulkShader {
    void* vftable;         // +0x00
    int refs;              // +0x04 content::LoadObject's reference count
    int name[2];           // +0x08 pure3d::Entity's name hash
    void* shader;          // +0x10 the pddi shader (natively +0x18)
    unsigned char flag;    // +0x14
    unsigned int value;    // +0x18
    int last;              // +0x1c the allocation's last word
};
HULK_SIZE32(HulkShader, 0x20);

#endif
