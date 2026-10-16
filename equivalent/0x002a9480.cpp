// STATUS: equivalent (tools/equiv.py level 3: 222 inputs, branch coverage 8/8)
// pure3d::TextureAnimationController::vfunc_7 @ 0x002a9480
#include "gen/pure3d.h"

namespace pure3d {
class Channel_2a9480 {
public:
    virtual void v0();
};
class EntityChannel_2a9480 : public Channel_2a9480 {
public:
    virtual void v1();
    char pad04[4];
    int field8;              // 0x08
    void FUN_0028ac00(int arg, class Entity_2a9480 **out);
};
class Entity_2a9480 {
public:
    virtual void v0();
    char pad04[0xc];
    int field10;             // 0x10
};
class Texture_2a9480 : public Entity_2a9480 {
public:
    virtual void v1();
};
}

struct ChannelList_2a9480 {
    char pad00[0x14];
    int count;               // 0x14
    pure3d::Channel_2a9480 *FUN_00288950(int index);
};

struct ChannelSource {
    ChannelList_2a9480 *FUN_00288a10(int flag);
};

class Receiver_2a9480 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void Apply(int a, int b);        // slot 5
};

struct Binding_2a9480 {
    char pad00[0x10];
    Receiver_2a9480 *receiver;      // 0x10
};

void pure3d::TextureAnimationController::vfunc_7() {
    ChannelList_2a9480 *list = (*(ChannelSource * *)&this->f_3c)->FUN_00288a10(0);
    for (int i = list->count - 1; i >= 0; i--) {
        pure3d::EntityChannel_2a9480 *channel = dynamic_cast<pure3d::EntityChannel_2a9480 *>(list->FUN_00288950(i));
        if (channel == 0)
            continue;
        pure3d::Entity_2a9480 *entity;
        channel->FUN_0028ac00((*(int *)&this->f_34), &entity);
        pure3d::Texture_2a9480 *texture = dynamic_cast<pure3d::Texture_2a9480 *>(entity);
        int target = channel->field8;
        if (texture == 0)
            continue;
        (*(Binding_2a9480 * *)&this->f_40)->receiver->Apply(target, texture->field10);
    }
}
