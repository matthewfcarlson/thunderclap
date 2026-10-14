// STATUS: equivalent (tools/equiv.py level 3: 171 inputs, branch coverage 50/50)
// FUN_001f3c00 @ 0x001f3c00
extern float DAT_004c7df4;

struct Id_1f3c00 {
    int lo;
    int hi;
};

struct Voice_1f3c00 {
    void FUN_001e8ac0();
};

struct Sound_1f3c00 {
    char pad;
};

struct Notifier_1f3c00 {
    void FUN_001e9a90(const char* name, int arg);
};

struct Channel {
    char pad00[4];
    Sound_1f3c00* sound;               // 0x04
    Voice_1f3c00* voice;               // 0x08
    char pad0c[4];
    int f10;                    // 0x10
    char b14;                   // 0x14
    char pad15[3];

    void FUN_001f3400(int arg);
    int FUN_001f3370(int* a);
};

struct Slot_1f3c00 {
    char pad00[8];
    Voice_1f3c00* voice;               // 0x08
    int value;                  // 0x0c
    int qty;                    // 0x10
    const char* name;           // 0x14
    char flag;                  // 0x18
    char pad19[3];

    void FUN_0027af60(int lo, int hi);
    void FUN_001f3720(Id_1f3c00* id, Voice_1f3c00* voice, int value, int qty, const char* name, int flag);
};

bool __cdecl FUN_00249b40(Sound_1f3c00* s);
void __cdecl FUN_0024af00(Sound_1f3c00* s);
void __cdecl FUN_00247890(Sound_1f3c00* s, float volume);
void __stdcall FUN_001f32b0(Voice_1f3c00* voice, bool active, int flag);

class Player_1f3c00 {
public:
    bool FUN_001f3c00(Voice_1f3c00* voice, int* value, Id_1f3c00* id, const char* name, int qty, int flag);
    int FUN_001f31a0(Id_1f3c00* id);

    char pad00[0x8c];
    Channel* channel;           // 0x8c
    int limit;                  // 0x90
    char b94;                   // 0x94
    char pad95[0xa0 - 0x95];
    Slot_1f3c00 slot;                  // 0xa0
    char pad_after_slot[0x334 - 0xa0 - sizeof(Slot_1f3c00)];
    float volume;               // 0x334
    Notifier_1f3c00* notifier;         // 0x338
};

bool Player_1f3c00::FUN_001f3c00(Voice_1f3c00* voice, int* value, Id_1f3c00* id, const char* name, int qty, int flag)
{
    int count = slot.qty;
    if (count < 99) {
        if (qty > count)
            return false;
        int v = *value;
        slot.FUN_0027af60(id->lo, id->hi);
        slot.voice = voice;
        slot.value = v;
        slot.qty = qty;
        slot.name = name;
        slot.flag = (char)flag;
        return true;
    }

    if (channel && channel->sound && !FUN_00249b40(channel->sound)) {
        int lim = limit;
        if (qty > lim)
            return false;
        if ((qty == 1 || qty == 3 || qty == 4) && lim == qty)
            return false;
    }

    int found = FUN_001f31a0(id);
    if (found == 0 && (id->lo | id->hi))
        return false;

    if (channel->voice) {
        if (channel->sound && !FUN_00249b40(channel->sound)) {
            channel->FUN_001f3400(0xfa);
            slot.FUN_001f3720(id, voice, *value, qty, name, flag);
            return true;
        }
        if (channel->voice != voice) {
            channel->voice->FUN_001e8ac0();
            channel->voice = 0;
            FUN_0024af00(channel->sound);
            channel->sound = 0;
            channel->b14 = 0;
        }
    }

    if (channel->voice != voice)
        FUN_001f32b0(voice, found != 0, flag);
    channel->f10 = found;
    if (channel->sound)
        FUN_00247890(channel->sound, DAT_004c7df4 * volume * 0.01f);
    if (channel->FUN_001f3370(value) == 0)
        return false;

    limit = qty;
    if (channel->sound && !FUN_00249b40(channel->sound) && name && *name) {
        notifier->FUN_001e9a90(name, 0x1f4);
        b94 = 1;
    }
    return true;
}
