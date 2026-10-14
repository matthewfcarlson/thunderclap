// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001dc2d0 @ 0x001dc2d0
struct Tracker_1dc2d0 {
    int FUN_001d5c70(int value);
};

class Player_1dc2d0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void Play(int value, int mode);
    void FUN_001d63b0(int handle);

    char pad04[0xe8];
    Tracker_1dc2d0 *tracker;   // +0xec
};

struct Voice_1dc2d0 {
    char pad0[0x18];
    Player_1dc2d0 *player;     // +0x18
    char pad1c[4];
    unsigned short state;   // +0x20
    short channel;      // +0x22
    char pad24[2];
    unsigned char value;    // +0x26
    char pad27;
};

struct Channel {
    char pad0[0x10];
    unsigned char flags;    // +0x10
    char pad11[3];
};

class Mixer {
public:
    int FUN_001dc2d0(int index, int value);

    char pad0[0x608];
    Voice_1dc2d0 voices[1];
};

int Mixer::FUN_001dc2d0(int index, int value) {
    if (index < 0) {
        return -1;
    }
    Voice_1dc2d0 *voice = &voices[index];
    Channel *channel = (Channel *)((char *)this + 0x14608) + voice->channel;
    if ((channel->flags & 1) && voice->player != 0) {
        voice->player->Play(value, 1);
        int handle = voice->player->tracker->FUN_001d5c70(value);
        if (handle > 0) {
            voice->player->FUN_001d63b0(handle);
        }
    } else {
        voice->value = (unsigned char)value;
        voice->state = 0xfde8;
        channel->flags &= 0xfb;
    }
    return value;
}
