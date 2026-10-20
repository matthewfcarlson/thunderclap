// FUN_0028c2a0 @ 0x0028c2a0
// equiv-map: ??0Channel@pure3d@@QAE@HPAVOwner@@@Z = 0x0028b420
extern void* __cdecl FUN_0008d6d0(unsigned int size) throw();
extern "C" void* __cdecl memset(void*, int, unsigned int) throw();

class Owner {
public:
    virtual void v0();
    void* FUN_002888c0(unsigned int size, int tag) throw();
};

namespace pure3d {

class Channel {
public:
    Channel(int count, Owner* owner) throw();
    virtual ~Channel() throw();
    char pad04[8];
    Owner* owner;          // 0x0c
    int count;             // 0x10
    char pad14[4];
};

class EntityChannel : public Channel {
public:
    EntityChannel(int count, Owner* owner) throw();
    virtual ~EntityChannel() throw();
    void* values;          // 0x18
};

EntityChannel::EntityChannel(int count_, Owner* owner_) throw() : Channel(count_, owner_)
{
    values = 0;
    if (owner == 0)
        values = FUN_0008d6d0(count << 2);
    else
        values = owner->FUN_002888c0(count << 2, 3);
    memset(values, 0, count << 2);
}

}
