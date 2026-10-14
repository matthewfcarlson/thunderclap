// STATUS: equivalent (tools/equiv.py level 3: 82 inputs, branch coverage 27/28, incomplete)
// FUN_001f3ec0 @ 0x001f3ec0
extern float DAT_004c7df8;

struct Voice_1f3ec0 {
    char pad0[4];
    void *sound;
    char pad8[0x10 - 8];
    int flags;
    char pad14[0x1d - 0x14];
    char tag;
    void FUN_001f32b0(int a, bool b, int c);
};

void __cdecl FUN_00247890(void *sound, float volume);

class VoicePool_1f3ec0 {
public:
    Voice_1f3ec0 *FUN_001f3ec0(int a, int unused, int flags, int c, char tag);

    char pad0[8];
    Voice_1f3ec0 *voices[32];
    int count;
    Voice_1f3ec0 *reserved8c;
    char pad90[0xc0 - 0x90];
    Voice_1f3ec0 *reservedC0;
    Voice_1f3ec0 *reservedC4;
    Voice_1f3ec0 *reservedC8;
    Voice_1f3ec0 *reservedCC;
    char padd0[0x334 - 0xd0];
    float volumeScale;
};

Voice_1f3ec0 *VoicePool_1f3ec0::FUN_001f3ec0(int a, int unused, int flags, int c, char tag)
{
    int n = count;
    for (int i = 0; i < n; i++) {
        Voice_1f3ec0 *v = voices[i];
        if (v->sound == 0 && v != reserved8c && v != reservedCC && v != reservedC0
            && v != reservedC4 && v != reservedC8) {
            voices[i]->flags = flags;
            voices[i]->FUN_001f32b0(a, flags != 0, c);
            if (voices[i]->sound != 0)
                FUN_00247890(voices[i]->sound, DAT_004c7df8 * 0.01f * volumeScale);
            voices[i]->tag = tag;
            return voices[i];
        }
        n = count;
    }

    if (n >= 32)
        return 0;
    voices[n]->flags = flags;
    if (a != 0)
        voices[count]->FUN_001f32b0(a, flags != 0, c);
    count = count + 1;
    if (voices[count - 1]->sound != 0)
        FUN_00247890(voices[count - 1]->sound, DAT_004c7df8 * 0.01f * volumeScale);
    return voices[count - 1];
}
