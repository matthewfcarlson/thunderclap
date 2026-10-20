// STATUS: equivalent (tools/equiv.py level 3: 54 inputs, branch coverage 8/8)
// FUN_002e17c0 @ 0x002e17c0
#include "compat/ptr.h"
struct Mat_2e17c0 {
    char d[64];
};

void *__cdecl FUN_0008d6d0(unsigned int n);

struct MatVec {
    char pad0[8];
    Mat_2e17c0 *begin;
    Mat_2e17c0 *end;
};

namespace pure3d {
class BoneMatrixList {
public:
    BoneMatrixList(MatVec *src);
    virtual void f0();
    int f4;
    Mat_2e17c0 *begin;
    Mat_2e17c0 *end;
};
}

pure3d::BoneMatrixList::BoneMatrixList(MatVec *src)
{
    f4 = 0;
    hulk_uintptr n = src->end - src->begin;
    if (n != 0) {
        hulk_uintptr bytes = n * 64;
        begin = (Mat_2e17c0 *)FUN_0008d6d0(bytes);
        if (begin != 0) {
            end = (Mat_2e17c0 *)((char *)begin + bytes);
        } else {
            begin = 0;
            end = 0;
        }
    } else {
        begin = 0;
        end = 0;
    }
    n = src->end - src->begin;
    for (unsigned int i = 0; i < n; i++)
        begin[i] = src->begin[i];
}
