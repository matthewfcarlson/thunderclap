// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 5/6, incomplete)
// FUN_0028bdb0 @ 0x0028bdb0
// equiv-map: ??1Channel@pure3d@@UAE@XZ = 0x0028bcd0
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
    virtual ~Channel() throw();
    char pad4[8];
    Owner* owner;
    char pad10[4];
    void* frames;
};
class Vector1DOFChannel : public Channel {
public:
    virtual ~Vector1DOFChannel() throw();
    char pad18[16];
    void* values;
};
pure3d::Vector1DOFChannel::~Vector1DOFChannel() throw() {
    if (owner == 0)
        thunk_FUN_00267090(values);
    values = 0;
    if (owner == 0) {
        thunk_FUN_00267090(frames);
        frames = 0;
    } else {
        if (owner != 0) {
            owner->vfunc_1();
            owner = 0;
        }
        frames = 0;
    }
}
}
