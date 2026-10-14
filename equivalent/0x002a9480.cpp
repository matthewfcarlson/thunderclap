// STATUS: equivalent (tools/equiv.py level 3: 222 inputs, branch coverage 8/8)
// pure3d::TextureAnimationController::vfunc_7 @ 0x002a9480
namespace pure3d {
class Channel {
public:
    virtual void v0();
};
class EntityChannel : public Channel {
public:
    virtual void v1();
    char pad04[4];
    int field8;              // 0x08
    void FUN_0028ac00(int arg, class Entity **out);
};
class Entity {
public:
    virtual void v0();
    char pad04[0xc];
    int field10;             // 0x10
};
class Texture : public Entity {
public:
    virtual void v1();
};
}

struct ChannelList {
    char pad00[0x14];
    int count;               // 0x14
    pure3d::Channel *FUN_00288950(int index);
};

struct ChannelSource {
    ChannelList *FUN_00288a10(int flag);
};

class Receiver {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void Apply(int a, int b);        // slot 5
};

struct Binding {
    char pad00[0x10];
    Receiver *receiver;      // 0x10
};

class TextureAnimationController {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void vfunc_7();
    char pad04[0x30];
    int param34;             // 0x34
    char pad38[4];
    ChannelSource *source;   // 0x3c
    Binding *binding;        // 0x40
};

void TextureAnimationController::vfunc_7() {
    ChannelList *list = source->FUN_00288a10(0);
    for (int i = list->count - 1; i >= 0; i--) {
        pure3d::EntityChannel *channel = dynamic_cast<pure3d::EntityChannel *>(list->FUN_00288950(i));
        if (channel == 0)
            continue;
        pure3d::Entity *entity;
        channel->FUN_0028ac00(param34, &entity);
        pure3d::Texture *texture = dynamic_cast<pure3d::Texture *>(entity);
        int target = channel->field8;
        if (texture == 0)
            continue;
        binding->receiver->Apply(target, texture->field10);
    }
}
