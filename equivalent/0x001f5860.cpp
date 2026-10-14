// STATUS: equivalent (tools/equiv.py level 3: 160 inputs, branch coverage 36/44, incomplete)
// FUN_001f5860 @ 0x001f5860
char __cdecl FUN_002478f0(void *voice);
void __cdecl FUN_002485c0(void *voice, void *params, int a, int b);
void __cdecl FUN_0024a800(void *voice, int value);
int __cdecl FUN_00247930(void *voice, void *sound);
void __cdecl FUN_00247a90(void *voice, void *sound, int flag);
void __cdecl FUN_002497e0(void *sound);

class Emitter_1f5860 {
public:
    virtual void start(unsigned __int64 id);
    virtual void stop(unsigned __int64 id);
};

struct Owner_1f5860 {
    char padd0[0xd0];
    Emitter_1f5860 *emitter;        // 0xd0
};

class SoundSlot {
public:
    char pad0[4];
    void *voice;             // 0x04
    char pad08[4];
    Owner_1f5860 *owner;            // 0x0c
    char *params;            // 0x10
    char pad14[4];
    void *sound;             // 0x18
    char pending;            // 0x1c
    char active;             // 0x1d
    char pad1e[2];
    unsigned __int64 current; // 0x20
    int param28;             // 0x28
    unsigned __int64 FUN_001f57e0();
    char FUN_001f3550();
    void FUN_001f5860(float dt);
};

void SoundSlot::FUN_001f5860(float dt)
{
    if (voice) {
        if (FUN_002478f0(voice)) {
            if (params)
                FUN_002485c0(voice, params + 0x30, 0, param28);
        }
        FUN_0024a800(voice, (int)(dt * 1000.0f));
    }
    if (sound) {
        if (pending && FUN_00247930(voice, sound) == 2) {
            FUN_00247a90(voice, sound, 0);
            pending = 0;
        } else if (FUN_00247930(voice, sound) == 0) {
            FUN_002497e0(sound);
            sound = 0;
        }
    }
    if (!active || owner->emitter == 0)
        return;

    unsigned __int64 next = 0;
    if (sound == 0 || FUN_00247930(voice, sound) == 4)
        next = FUN_001f57e0();

    if (current == 0 && next != 0) {
        owner->emitter->start(next);
        current = next;
        return;
    }
    if (current != 0 && next == 0) {
        owner->emitter->stop(current);
        current = 0;
        return;
    }
    if (current != 0 && next != 0 && current != next) {
        owner->emitter->stop(current);
        owner->emitter->start(next);
        current = next;
        return;
    }
    if (current != 0) {
        if (voice == 0 || FUN_001f3550()) {
            owner->emitter->stop(current);
            current = 0;
        }
    }
}
