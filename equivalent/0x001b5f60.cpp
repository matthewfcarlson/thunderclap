// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 10/10)
// FUN_001b5f60 @ 0x001b5f60
// equiv-map: ?thunk_FUN_002ee510@Cache@@QAEXPAUVoice@@@Z = 0x002ee700

struct Voice_1b5f60 {
    virtual void v0();
    virtual void Release();     // slot 1
};

struct Cache {
    void thunk_FUN_002ee510(Voice_1b5f60 *v);
};

struct SoundData {
    char pad0[0x20];
    unsigned short size;        // 0x20
};

struct Sound_1b5f60 {
    virtual void v0();
    virtual void Release();     // slot 1
    char pad4[0x40];
    SoundData *data;            // 0x44
};

class SoundBank_1b5f60 {
public:
    char pad0[8];
    Cache *cache;               // 0x8
    char pad0c[0x4fc - 0xc];
    Voice_1b5f60 *voices[19];          // 0x4fc
    int voiceIds[19];           // 0x548
    Sound_1b5f60 **sounds;             // 0x594
    char pad598[0x5a4 - 0x598];
    unsigned int totalSize;     // 0x5a4

    bool FUN_001b5f60(int id);
};

bool SoundBank_1b5f60::FUN_001b5f60(int id)
{
    int i = 0;
    while (voiceIds[i] != id) {
        i++;
        if (i >= 19)
            return false;
    }

    cache->thunk_FUN_002ee510(voices[i]);
    voiceIds[i] = -1;
    if (voices[i] != 0) {
        voices[i]->Release();
        voices[i] = 0;
    }

    Sound_1b5f60 **slot = &sounds[id];
    if (*slot != 0)
        totalSize -= (*slot)->data->size;
    if (*slot != 0) {
        (*slot)->Release();
        *slot = 0;
    }
    return true;
}
