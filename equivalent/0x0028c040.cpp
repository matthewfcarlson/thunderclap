// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 6/8, incomplete)
// FUN_0028c040 @ 0x0028c040
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
void thunk_FUN_00267090(void*) throw();
class Owner {
public:
    virtual void vfunc_0() throw();
    virtual void vfunc_1() throw();
};
namespace pure3d {
class Channel {
public:
    virtual ~Channel() throw() {}
    char pad4[8];
    Owner* owner;
    char pad10[4];
    void* frames;
};
class SimpleChannel : public Channel {
public:
    virtual ~SimpleChannel() throw() {
        if (owner != 0) {
            owner->vfunc_1();
            owner = 0;
        } else {
            thunk_FUN_00267090(frames);
        }
        frames = 0;
    }
};
class RotationChannel : public SimpleChannel {
public:
    virtual ~RotationChannel() throw();
};
RotationChannel::~RotationChannel() throw() {
    if (owner == 0) {
        thunk_FUN_00267090(frames);
    } else if (owner != 0) {
        owner->vfunc_1();
        owner = 0;
    }
    frames = 0;
}
}
