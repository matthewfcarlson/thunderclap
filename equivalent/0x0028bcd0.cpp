// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 6/8, incomplete)
// FUN_0028bcd0 @ 0x0028bcd0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
void thunk_FUN_00267090(void*) throw();
class Owner_28bcd0 {
public:
    virtual void vfunc_0() throw();
    virtual void vfunc_1() throw();
};
namespace pure3d {
class Channel {
public:
    virtual ~Channel() throw() {}
    char pad4[8];
    Owner_28bcd0* owner;
    char pad10[4];
    void* frames;
};
class SimpleChannel : public Channel {
public:
    __forceinline virtual ~SimpleChannel() throw() {
        if (owner == 0) {
            thunk_FUN_00267090(frames);
        } else if (owner != 0) {
            owner->vfunc_1();
            owner = 0;
        }
        frames = 0;
    }
};
class VectorChannel : public SimpleChannel {
public:
    virtual ~VectorChannel() throw();
};
VectorChannel::~VectorChannel() throw() {
    if (owner == 0) {
        thunk_FUN_00267090(frames);
    } else if (owner != 0) {
        owner->vfunc_1();
        owner = 0;
    }
    frames = 0;
}
}
