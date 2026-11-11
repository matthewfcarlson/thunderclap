// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028edb0..0x0028f240 (kind game, layer engine, confidence high), dominant class pure3d::ShaderVectorBroadcast
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0028eea0 pure3d::ShaderFloatBroadcast::vfunc_3 (35 B): matches/0x0028eea0.cpp [isolated: on include/gen/, and its TU merges more functions without the headers; on include/gen/ and not mergeable]
// sym: ?vfunc_3@ShaderFloatBroadcast@pure3d@@UAEHPAX@Z
#include "gen/pure3d.h"

class Receiver_28eea0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void invoke(int, int);
};

hulk_intptr pure3d::ShaderFloatBroadcast::vfunc_3(void* __p0) { void * p = (void *)__p0;

    if (p) {
        Receiver_28eea0* r = *(Receiver_28eea0**)((char*)p + 16);
        r->invoke(this->f_08, this->f_0c);
    }
    return (hulk_intptr)p;
}

