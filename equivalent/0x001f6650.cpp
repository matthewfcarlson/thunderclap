// STATUS: equivalent (tools/equiv.py level 3: 109 inputs, branch coverage 30/30)
// FUN_001f6650 @ 0x001f6650
extern "C" unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern float DAT_004c7df0;
extern float DAT_004c7df4;
extern float DAT_004c7df8;

struct Voice {
    int pad0;
    void* handle;
};
void FUN_00247890(void* handle, float value);
void FUN_00240bb0();

class Channel {
public:
    void FUN_001f5860(float dt);
};
class Mixer {
public:
    char pad0[8];
    Voice* items[32];
    int count;
    Voice* ref8c;
    char pad90[0xc0 - 0x90];
    Voice* refc0;
    Voice* refc4;
    Voice* refc8;
    char padcc[0x32c - 0xcc];
    int countdown;
    int pad330;
    float gain;
    void FUN_001f46a0();
    void FUN_001f4140(int a);
    void FUN_001f6650();
};

void Mixer::FUN_001f6650()
{
    unsigned int cookie = DAT_004d9968;
    if (--countdown == 0) {
        FUN_001f46a0();
        countdown = 0;
        gain = 1.0f;
        for (int i = 0; i < count; i++) {
            Voice* v = items[i];
            float base;
            if (v == ref8c)
                base = DAT_004c7df4;
            else if (v == refc8 || v == refc4)
                base = DAT_004c7df8;
            else if (v == refc0)
                base = DAT_004c7df0;
            else
                base = DAT_004c7df8;
            if (v->handle != 0)
                FUN_00247890(v->handle, base * 0.01f * gain);
        }
        FUN_001f4140(0);
        for (int j = 0; j < count; j++)
            ((Channel*)items[j])->FUN_001f5860(0.016666668f);
        FUN_001f4140(0);
        for (int k = 0; k < count; k++)
            ((Channel*)items[k])->FUN_001f5860(0.016666668f);
        FUN_00240bb0();
    }
    __security_check_cookie(cookie);
}
