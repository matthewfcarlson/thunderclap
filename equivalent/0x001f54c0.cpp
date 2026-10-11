// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 26/26)
// FUN_001f54c0 @ 0x001f54c0
inline void* operator new(unsigned int, void* p) throw() { return p; }

void FUN_0008d330(void* p);
void FUN_002497e0(void* p);
void FUN_00249a90(void* handle, void* out);
void FUN_0024a800(void* handle, int arg);
bool FUN_00249b40(void* handle);
void FUN_0024af00(void* handle);
void FUN_00240bb0();
void FUN_002656a0();

struct Part {
    char data[8];
    void FUN_0027af50();
};

struct Buffer {
    Part first;
    Part second;
};

struct Emitter {
    void FUN_001e8ac0();
};

class CSoundSequenceVoice {
public:
    virtual void v0();
    void* handle;
    Emitter* emitter;
    int pad0c;
    int f10;
    char f14;
    char pad15[3];
    void* extra;
};

struct StopState {
    int a;
    int b;
};

class SoundMgr {
public:
    char pad00[8];
    CSoundSequenceVoice* voices[32];
    int voiceCount;
    char pad8c[0xd4 - 0x8c];
    Buffer* buffers[0x94];
    int f324;
    void FUN_001f54c0();
};

void SoundMgr::FUN_001f54c0()
{
    for (int i = 0; i < 0x94; i++) {
        Buffer* b = buffers[i];
        if (b) {
            b->second.FUN_0027af50();
            b->first.FUN_0027af50();
            FUN_0008d330(b);
        }
        buffers[i] = 0;
    }
    f324 = 0;
    if (voiceCount <= 0) {
        voiceCount = 0;
        return;
    }
    for (int i = 0; i < voiceCount; i++) {
        CSoundSequenceVoice* v = voices[i];
        if (v->handle) {
            StopState st;
            st.a = 0;
            st.b = 0;
            FUN_00249a90(v->handle, &st);
            FUN_0024a800(v->handle, 0x32);
            if (v->extra) {
                FUN_002497e0(v->extra);
                v->extra = 0;
            }
        }
        v = voices[i];
        while (v->handle) {
            if (FUN_00249b40(v->handle))
                break;
            FUN_0024a800(v->handle, 10);
            FUN_00240bb0();
            FUN_002656a0();
        }
        v = voices[i];
        if (v->emitter)
            v->emitter->FUN_001e8ac0();
        void* extra = v->extra;
        v->emitter = 0;
        v->f10 = 0;
        if (extra) {
            FUN_002497e0(extra);
            v->extra = 0;
        }
        if (v->handle) {
            FUN_00249a90(v->handle, 0);
            FUN_0024a800(v->handle, 0x32);
            FUN_0024af00(v->handle);
            v->handle = 0;
        }
        v->f14 = 0;
        v = voices[i];
        if (v) {
            void* handle = v->handle;
            new (v) CSoundSequenceVoice;
            if (handle) {
                FUN_0024af00(handle);
                v->handle = 0;
            }
            FUN_0008d330(v);
        }
        voices[i] = 0;
    }
    voiceCount = 0;
}
