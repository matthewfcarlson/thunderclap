// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00068c80..0x00068cc0 (kind game, layer game, confidence high), dominant class CTrack
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fd4cb38a {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fd4cb38a {} using namespace fn_fd4cb38a;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fd4cb38a {
class CTrack {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual int f8(int a, int b);
    virtual void _m_vf9();
    virtual int vfunc_10(int, int, int);
    virtual int f11(int);
    virtual int f12(int);
};
class Track_68ca0 {
  public:
    virtual int vfunc_0();
};
namespace fight {
class Condition {
  public:
    virtual int vfunc_3();
};
}
namespace fight {
class Param {
  public:
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_4();
};
}
class CTrack_68ca0 : public Track_68ca0, public fight::Condition, public fight::Param {
  public:
    virtual int vfunc_0(int);
};


// 0x00068c80 CTrack::vfunc_8 (21 B): matches/0x00068c80.cpp
// sym: ?f8@CTrack@fn_fd4cb38a@@UAEHHH@Z
int CTrack::f8(int a, int b) {
    int r = f11(b);
    if (r == 0)
        r = a;
    return r;
}


// 0x00068ca0 CTrack::vfunc_11 (5 B): matches/0x00068ca0.cpp
// sym: ?vfunc_0@CTrack_68ca0@fn_fd4cb38a@@UAEHH@Z
// Same code shape as 0x00049c80 (propagated; names are from that function)
int CTrack_68ca0::vfunc_0(int) {
    return 0;
}


// 0x00068cb0 CTrack::vfunc_10 (13 B): matches/0x00068cb0.cpp
// sym: ?vfunc_10@CTrack@fn_fd4cb38a@@UAEHHHH@Z
int CTrack::vfunc_10(int a, int b, int c) {
    return f12(c);
}

} // namespace fn_fd4cb38a
