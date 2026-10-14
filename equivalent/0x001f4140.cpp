// STATUS: equivalent (tools/equiv.py level 3: 103 inputs, branch coverage 30/30)
// FUN_001f4140 @ 0x001f4140
struct Sound;
struct Voice_1f4140 {
    char pad0[4];
    Sound *sound;           // 0x4
    int handle;             // 0x8
    char pad1[4];
    int owner;              // 0x10
    char finished;          // 0x14
    void FUN_001f32b0(int id, bool flag, int vol);
    int FUN_001f3370(void *state);
};
struct Names_1f4140 {
    void FUN_001e9a90(const char *name, int len);
    int FUN_001ea010(const char *group);
};
struct State_1f4140 {
    char pad[8];
    void FUN_001f36e0();
};
// equiv-conv: FUN_001e8ac0 ecx
void FUN_001e8ac0(int handle);
bool FUN_00249b40(Sound *s);
void FUN_0024af00(Sound *s);
void FUN_00247890(Sound *s, float volume);

class Player_1f4140 {
public:
    char pad0[0x8c];
    Voice_1f4140 *voice;           // 0x8c
    int f90;
    char f94;
    char pad1[0xa0 - 0x95];
    State_1f4140 state;            // 0xa0
    int id;                 // 0xa8
    int fac;
    int count;              // 0xb0
    const char *name;       // 0xb4
    char vol;               // 0xb8
    char pad4[0x334 - 0xb9];
    float gain;             // 0x334
    Names_1f4140 *names;           // 0x338
    int FUN_001f31a0(State_1f4140 *s);
    void FUN_001f4140(bool force);
};

void Player_1f4140::FUN_001f4140(bool force)
{
    if (voice == 0) return;
    if (voice->sound != 0) {
        if (!FUN_00249b40(voice->sound)) return;
    }
    if (count >= 999) return;
    int r = FUN_001f31a0(&state);
    int group = names->FUN_001ea010("front_end");
    if (!force) {
        if (id != group) return;
    }
    if (voice->handle != id) {
        FUN_001e8ac0(voice->handle);
        voice->handle = 0;
        FUN_0024af00(voice->sound);
        voice->sound = 0;
        voice->finished = 0;
    }
    if (voice->handle == 0) {
        voice->FUN_001f32b0(id, r != 0, (unsigned char)vol);
    }
    voice->owner = r;
    if (voice->sound != 0) {
        FUN_00247890(voice->sound, 100.0f * gain * 0.01f);
    }
    if (voice->FUN_001f3370(&fac) != 0) {
        f90 = count;
        if (voice->sound != 0) {
            if (!FUN_00249b40(voice->sound)) {
                if (name != 0) {
                    if (*name != 0) {
                        names->FUN_001e9a90(name, 0x32);
                        f94 = 1;
                    }
                }
            }
        }
    }
    state.FUN_001f36e0();
}
