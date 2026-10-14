// STATUS: equivalent (tools/equiv.py level 3: 140 inputs, branch coverage 10/10)
// FUN_00285f50 @ 0x00285f50
// equiv-map: ??1Entity@pure3d@@UAE@XZ = 0x0027afd0
class RefObj {
public:
    virtual void AddRef();
    virtual void Release();
};
struct Track {
    char pad0[0x28];
    RefObj* owner;
};
namespace pure3d {
class Entity {
public:
    virtual ~Entity() throw();
    char pad04[0x28 - 4];
};
class FrameController : public Entity {
public:
    virtual ~FrameController() throw() {}
};
class BlendFrameController : public FrameController {
public:
    virtual ~BlendFrameController() throw();
    unsigned int count;
    Track tracks[5];
};
BlendFrameController::~BlendFrameController() throw() {
    for (unsigned int i = 0; i < count; i++) {
        if (tracks[i].owner) {
            tracks[i].owner->Release();
            tracks[i].owner = 0;
        }
    }
    for (int k = 4; k >= 0; k--) {
        if (tracks[k].owner) {
            tracks[k].owner->Release();
            tracks[k].owner = 0;
        }
    }
}
}
