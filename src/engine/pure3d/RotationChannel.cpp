// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028dfc0..0x0028e0c0 (kind game, layer engine, confidence medium), dominant class pure3d::RotationChannel
#include "tree_prelude.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fd3f7d78 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fd3f7d78 {} using namespace fn_fd3f7d78;
#include "engine/pure3d.h"


// 0x0028dfc0 pure3d::IntChannel::vfunc_0 (30 B): matches/0x0028dfc0.cpp
// sym: ?vfunc_0@IntChannel_28dfc0@fn_0028dfc0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `pure3d::IntChannel::~IntChannel() {}` stood for it, which natively defines no
// function for the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's body
// 0x0028ba20, then (flags & 1) operator delete.
namespace fn_0028dfc0 {
struct IntChannel_28dfc0 {
    void FUN_0028ba20();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* IntChannel_28dfc0::vfunc_0(unsigned int flags) {
    FUN_0028ba20();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_0028dfc0
// (x64t21) the destructor itself, which other objects' code references:
pure3d::IntChannel::~IntChannel() {}


// 0x0028dfe0 pure3d::Float1Channel::vfunc_0 (30 B): matches/0x0028dfe0.cpp
// sym: ?vfunc_0@Float1Channel_28dfe0@fn_0028dfe0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `pure3d::Float1Channel::~Float1Channel() {}` stood for it, which natively
// defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's
// body 0x0028bb10, then (flags & 1) operator delete.
namespace fn_0028dfe0 {
struct Float1Channel_28dfe0 {
    void FUN_0028bb10();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Float1Channel_28dfe0::vfunc_0(unsigned int flags) {
    FUN_0028bb10();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_0028dfe0
// (x64t21) the destructor itself, which other objects' code references:
pure3d::Float1Channel::~Float1Channel() {}


// 0x0028e000 pure3d::Float2Channel::vfunc_0 (30 B): matches/0x0028e000.cpp
// sym: ?vfunc_0@Float2Channel_28e000@fn_0028e000@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `pure3d::Float2Channel::~Float2Channel() {}` stood for it, which natively
// defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's
// body 0x0028bc20, then (flags & 1) operator delete.
namespace fn_0028e000 {
struct Float2Channel_28e000 {
    void FUN_0028bc20();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* Float2Channel_28e000::vfunc_0(unsigned int flags) {
    FUN_0028bc20();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_0028e000
// (x64t21) the destructor itself, which other objects' code references:
pure3d::Float2Channel::~Float2Channel() {}


// 0x0028e020 pure3d::VectorChannel::vfunc_0 (30 B): matches/0x0028e020.cpp
// sym: ?vfunc_0@VectorChannel_28e020@fn_0028e020@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `pure3d::VectorChannel::~VectorChannel() {}` stood for it, which natively
// defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's
// body 0x0028bcd0, then (flags & 1) operator delete.
namespace fn_0028e020 {
struct VectorChannel_28e020 {
    void FUN_0028bcd0();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* VectorChannel_28e020::vfunc_0(unsigned int flags) {
    FUN_0028bcd0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_0028e020
// (x64t21) the destructor itself, which other objects' code references:
pure3d::VectorChannel::~VectorChannel() {}


// 0x0028e0a0 pure3d::RotationChannel::vfunc_0 (30 B): matches/0x0028e0a0.cpp
// sym: ?vfunc_0@RotationChannel_28e0a0@fn_0028e0a0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `pure3d::RotationChannel::~RotationChannel() {}` stood for it, which natively
// defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's
// body 0x0028c040, then (flags & 1) operator delete.
namespace fn_0028e0a0 {
struct RotationChannel_28e0a0 {
    void FUN_0028c040();   // the destructor's body
    void* vfunc_0(unsigned int flags);
};
void* RotationChannel_28e0a0::vfunc_0(unsigned int flags) {
    FUN_0028c040();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_0028e0a0
// (x64t21) the destructor itself, which other objects' code references:
pure3d::RotationChannel::~RotationChannel() {}

