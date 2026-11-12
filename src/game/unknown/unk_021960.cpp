// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00021960..0x00021f20 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "gen/fight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fde8cdef {
#define TREE_TU_END }
namespace fn_fde8cdef {} using namespace fn_fde8cdef;
namespace fn_fde8cdef { extern "C" char DAT_003f3574[], DAT_003f381c[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
namespace fn_fde8cdef { extern "C" char DAT_003f359c[], DAT_003f3390[], DAT_003f3754[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fde8cdef {
extern void* g_vftable_003f3574[];
class Ref_21960 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21960 {
  public:
    void* vptr;
};
class CStunAnimationAction_21960 : public CAction_21960 {
  public:
    char pad[0x18];
    Ref_21960* m2;
    char pad2[0x4];
    Ref_21960* m1;
    CStunAnimationAction_21960* f2(unsigned char flags);
};
class Ref_219c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_219c0 {
  public:
    void* vptr;
};
class CKeyPoseAction_219c0 : public CAction_219c0 {
  public:
    char pad[0x1c - 4];
    Ref_219c0* m1c;
    char pad2[4];
    Ref_219c0* m24;
    CKeyPoseAction_219c0* f2(unsigned char flags);
};
extern void* hulk_at_003f3390[];
class Ref_21a20 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21a20 {
  public:
    void* vptr;
};
class CSoundAction_21a20 : public CAction_21a20 {
  public:
    char pad[24];
    Ref_21a20* m;
    CSoundAction_21a20* f2(unsigned char flags);
};
extern void* g_vftable_21a60[];
class Ref_21a60 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21a60 {
  public:
    void* vptr;
};
class CComboMessageAction_21a60 : public CAction_21a60 {
  public:
    char pad[24];
    Ref_21a60* m;
    CComboMessageAction_21a60* f2(unsigned char flags);
};
extern void* hulk_at_003f3614[];
class Ref_21aa0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21aa0 {
  public:
    void* vptr;
};
class CMoveAction_21aa0 : public CAction_21aa0 {
  public:
    char pad[0x18];
    Ref_21aa0* m1c;
    char pad2[4];
    Ref_21aa0* m24;
    CMoveAction_21aa0* f2(unsigned char flags);
};
extern void* g_vftable_21b00[];
class Ref_21b00 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21b00 {
  public:
    void* vptr;
};
class CMoveAddAction_21b00 : public CAction_21b00 {
  public:
    char pad[24];
    Ref_21b00* m;
    CMoveAddAction_21b00* f2(unsigned char flags);
};
extern void* g_vftable_21b40[];
class Ref_21b40 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21b40 {
  public:
    void* vptr;
};
class CMoveAddYAction_21b40 : public CAction_21b40 {
  public:
    char pad[0x1c - 4];
    Ref_21b40* m;
    CMoveAddYAction_21b40* f2(unsigned char flags);
};
extern void* hulk_at_003f368c[];
class Ref_21b80 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21b80 {
  public:
    void* vptr;
};
class CSweepAction_21b80 : public CAction_21b80 {
  public:
    char pad[0x18];
    Ref_21b80* m1c;
    char pad2[4];
    Ref_21b80* m24;
    CSweepAction_21b80* f2(unsigned char flags);
};
extern void* g_vftable_21c00[];
class Ref_21c00 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21c00 {
  public:
    void* vptr;
};
class CDamageAction_21c00 : public CAction_21c00 {
  public:
    char pad[0x1c - 4];
    Ref_21c00* m1c;
    CDamageAction_21c00* f2(unsigned char flags);
};
extern void* g_vftable_21c40[];
class Ref_21c40 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21c40 {
  public:
    void* vptr;
};
class CDrainHealthAction_21c40 : public CAction_21c40 {
  public:
    char pad[0x1c - 4];
    Ref_21c40* m;
    CDrainHealthAction_21c40* f2(unsigned char flags);
};
extern void* g_vftable_21c80[];
class Ref_21c80 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21c80 {
  public:
    void* vptr;
};
class CComboTimerAction_21c80 : public CAction_21c80 {
  public:
    char pad[24];
    Ref_21c80* m;
    CComboTimerAction_21c80* f2(unsigned char flags);
};
class Ref_21cc0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21cc0 {
  public:
    void* vptr;
};
class CGrappleLocoStrafe4Action_21cc0 : public CAction_21cc0 {
  public:
    char pad[0x1c - 4];
    Ref_21cc0* m1c;
    char pad2[4];
    Ref_21cc0* m24;
    CGrappleLocoStrafe4Action_21cc0* f2(unsigned char flags);
};
extern void* g_vftable_21d20[];
class Ref_21d20 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21d20 {
  public:
    void* vptr;
};
class CGrappleAttachAction_21d20 : public CAction_21d20 {
  public:
    char pad[24];
    Ref_21d20* m;
    CGrappleAttachAction_21d20* f2(unsigned char flags);
};
extern void* g_vftable_21d60[];
class Ref_21d60 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21d60 {
  public:
    void* vptr;
};
class CGrappleSwapAction_21d60 : public CAction_21d60 {
  public:
    char pad[0x1c - 4];
    Ref_21d60* m1c;
    CGrappleSwapAction_21d60* f2(unsigned char flags);
};
extern void* g_vftable_21da0[];
class Ref_21da0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21da0 {
  public:
    void* vptr;
};
class CGrappleDetachAction_21da0 : public CAction_21da0 {
  public:
    char pad[24];
    Ref_21da0* m;
    CGrappleDetachAction_21da0* f2(unsigned char flags);
};
extern void* g_vftable_003f381c[];
class Ref_21e00 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21e00 {
  public:
    void* vptr;
};
class CSmartPropAttachAction_21e00 : public CAction_21e00 {
  public:
    char pad[0x18];
    Ref_21e00* m2;
    char pad2[0x4];
    Ref_21e00* m1;
    CSmartPropAttachAction_21e00* f2(unsigned char flags);
};
extern void* hulk_at_003f3844[];
class Ref_21e60 {
  public:
    virtual void F0();
    virtual void Release();
};
class CAction_21e60 {
  public:
    void* vptr;
};
class CSmartPropUpdateAttachmentAction_21e60 : public CAction_21e60 {
  public:
    char pad[0x18];
    Ref_21e60* m1c;
    char pad2[4];
    Ref_21e60* m24;
    CSmartPropUpdateAttachmentAction_21e60* f2(unsigned char flags);
};


// 0x00021960 CStunAnimationAction::vfunc_2 (82 B): matches/0x00021960.cpp
// sym: ?f2@CStunAnimationAction_21960@fn_fde8cdef@@QAEPAV12@E@Z
CStunAnimationAction_21960* CStunAnimationAction_21960::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3574);
    _ReadWriteBarrier();
    if (m1) {
        m1->Release();
        m1 = 0;
    }
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m2) {
        m2->Release();
        m2 = 0;
    }
    ((fight::Action *)(CAction_21960 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x000219c0 CKeyPoseAction::vfunc_2 (82 B): matches/0x000219c0.cpp
// sym: ?f2@CKeyPoseAction_219c0@fn_fde8cdef@@QAEPAV12@E@Z
CKeyPoseAction_219c0* CKeyPoseAction_219c0::f2(unsigned char flags) {
    vptr = (void**)DAT_003f359c;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = (void**)DAT_003f3390;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_219c0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00021a20 CSoundAction::vfunc_2 (57 B): matches/0x00021a20.cpp
// sym: ?f2@CSoundAction_21a20@fn_fde8cdef@@QAEPAV12@E@Z
CSoundAction_21a20* CSoundAction_21a20::f2(unsigned char flags) {
    vptr = hulk_at_003f3390;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_21a20 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00021a60 CComboMessageAction::vfunc_2 (57 B): matches/0x00021a60.cpp
// sym: ?f2@CComboMessageAction_21a60@fn_fde8cdef@@QAEPAV12@E@Z
CComboMessageAction_21a60* CComboMessageAction_21a60::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_21a60 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00021aa0 CMoveAction::vfunc_2 (82 B): matches/0x00021aa0.cpp
// sym: ?f2@CMoveAction_21aa0@fn_fde8cdef@@QAEPAV12@E@Z
CMoveAction_21aa0* CMoveAction_21aa0::f2(unsigned char flags) {
    vptr = hulk_at_003f3614;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = (void**)DAT_003f3390;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_21aa0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00021b00 CMoveAddAction::vfunc_2 (57 B): matches/0x00021b00.cpp
// sym: ?f2@CMoveAddAction_21b00@fn_fde8cdef@@QAEPAV12@E@Z
CMoveAddAction_21b00* CMoveAddAction_21b00::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_21b00 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00021b40 CMoveAddYAction::vfunc_2 (57 B): matches/0x00021b40.cpp
// sym: ?f2@CMoveAddYAction_21b40@fn_fde8cdef@@QAEPAV12@E@Z
CMoveAddYAction_21b40* CMoveAddYAction_21b40::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_21b40 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00021b80 CSweepAction::vfunc_2 (82 B): matches/0x00021b80.cpp
// sym: ?f2@CSweepAction_21b80@fn_fde8cdef@@QAEPAV12@E@Z
CSweepAction_21b80* CSweepAction_21b80::f2(unsigned char flags) {
    vptr = hulk_at_003f368c;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = (void**)DAT_003f3390;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_21b80 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_fde8cdef

// 0x00021be0 CAutoTargetAction::vfunc_2 (30 B): matches/0x00021be0.cpp
// sym: ??_GCAutoTargetAction@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CAutoTargetAction::~CAutoTargetAction() {}

namespace fn_fde8cdef {

// 0x00021c00 CDamageAction::vfunc_2 (57 B): matches/0x00021c00.cpp
// sym: ?f2@CDamageAction_21c00@fn_fde8cdef@@QAEPAV12@E@Z
CDamageAction_21c00* CDamageAction_21c00::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_21c00 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00021c40 CDrainHealthAction::vfunc_2 (57 B): matches/0x00021c40.cpp
// sym: ?f2@CDrainHealthAction_21c40@fn_fde8cdef@@QAEPAV12@E@Z
CDrainHealthAction_21c40* CDrainHealthAction_21c40::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_21c40 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00021c80 CComboTimerAction::vfunc_2 (57 B): matches/0x00021c80.cpp
// sym: ?f2@CComboTimerAction_21c80@fn_fde8cdef@@QAEPAV12@E@Z
CComboTimerAction_21c80* CComboTimerAction_21c80::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_21c80 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00021cc0 CGrappleLocoStrafe4Action::vfunc_2 (82 B): matches/0x00021cc0.cpp
// sym: ?f2@CGrappleLocoStrafe4Action_21cc0@fn_fde8cdef@@QAEPAV12@E@Z
CGrappleLocoStrafe4Action_21cc0* CGrappleLocoStrafe4Action_21cc0::f2(unsigned char flags) {
    vptr = (void**)DAT_003f3754;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = (void**)DAT_003f3390;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_21cc0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00021d20 CGrappleAttachAction::vfunc_2 (57 B): matches/0x00021d20.cpp
// sym: ?f2@CGrappleAttachAction_21d20@fn_fde8cdef@@QAEPAV12@E@Z
CGrappleAttachAction_21d20* CGrappleAttachAction_21d20::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_21d20 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00021d60 CGrappleSwapAction::vfunc_2 (57 B): matches/0x00021d60.cpp
// sym: ?f2@CGrappleSwapAction_21d60@fn_fde8cdef@@QAEPAV12@E@Z
CGrappleSwapAction_21d60* CGrappleSwapAction_21d60::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_21d60 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00021da0 CGrappleDetachAction::vfunc_2 (57 B): matches/0x00021da0.cpp
// sym: ?f2@CGrappleDetachAction_21da0@fn_fde8cdef@@QAEPAV12@E@Z
CGrappleDetachAction_21da0* CGrappleDetachAction_21da0::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(CAction_21da0 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_fde8cdef

// 0x00021de0 CGrabAction::vfunc_2 (30 B): matches/0x00021de0.cpp
// sym: ??_GCGrabAction@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CGrabAction::~CGrabAction() {}

namespace fn_fde8cdef {

// 0x00021e00 CSmartPropAttachAction::vfunc_2 (82 B): matches/0x00021e00.cpp
// sym: ?f2@CSmartPropAttachAction_21e00@fn_fde8cdef@@QAEPAV12@E@Z
CSmartPropAttachAction_21e00* CSmartPropAttachAction_21e00::f2(unsigned char flags) {
    vptr = ((void**)DAT_003f381c);
    _ReadWriteBarrier();
    if (m1) {
        m1->Release();
        m1 = 0;
    }
    vptr = ((void**)DAT_003f3390);
    _ReadWriteBarrier();
    if (m2) {
        m2->Release();
        m2 = 0;
    }
    ((fight::Action *)(CAction_21e00 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x00021e60 CSmartPropUpdateAttachmentAction::vfunc_2 (82 B): matches/0x00021e60.cpp
// sym: ?f2@CSmartPropUpdateAttachmentAction_21e60@fn_fde8cdef@@QAEPAV12@E@Z
CSmartPropUpdateAttachmentAction_21e60* CSmartPropUpdateAttachmentAction_21e60::f2(unsigned char flags) {
    vptr = hulk_at_003f3844;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    vptr = (void**)DAT_003f3390;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    ((fight::Action *)(CAction_21e60 *)this)->FUN_002326a0();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_fde8cdef

// 0x00021ec0 CSmartPropSpawnAction::vfunc_2 (82 B): matches/0x00021ec0.cpp [wrapped: conflict: CSmartPropSpawnAction]
// sym: ?vfunc_2@CSmartPropSpawnAction@fn_00021ec0@@QAEPAV12@E@Z
namespace fn_00021ec0 {
extern void* hulk_at_003f386c[];
extern void* g_vftCAction[];

struct IRef_21ec0 {
    virtual void vfunc_0();
    virtual void Release();
};

void DestroyAction_0008d330(void* p);

class CSmartPropSpawnAction {
  public:
    void* volatile m_vftable;
    char m_pad0[0x18];
    IRef_21ec0* volatile m_pField1C;
    char m_pad4[0x4];
    IRef_21ec0* volatile m_pField24;
    char m_pad8[0x40];

    CSmartPropSpawnAction* vfunc_2(unsigned char flags);
    void CleanUp_002326a0();
};

CSmartPropSpawnAction* CSmartPropSpawnAction::vfunc_2(unsigned char flags) {
    IRef_21ec0* p;

    m_vftable = (void*)hulk_at_003f386c;
    p = m_pField24;
    if (p != 0) {
        p->Release();
        m_pField24 = 0;
    }
    m_vftable = (void*)g_vftCAction;
    p = m_pField1C;
    if (p != 0) {
        p->Release();
        m_pField1C = 0;
    }
    CleanUp_002326a0();
    if (flags & 1) {
        DestroyAction_0008d330(this);
    }
    return this;
}
} // namespace fn_00021ec0

