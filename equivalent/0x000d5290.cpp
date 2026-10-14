// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 23/24, incomplete)
// FUN_000d5290 @ 0x000d5290
struct MessageSink {
    void FUN_001ebd00(const char *kind, const char *name);
};

extern float DAT_004a06d4;
extern float DAT_004a06dc;

union FloatBits_d5290 {
    float f;
    unsigned int u;
};

class MessageBox {
public:
    char pad0[0x10];
    MessageSink *sink;
    char pad14[0x240 - 0x14];
    int f240;
    char pad244[4];
    unsigned char b248;
    char pad249[0x47c - 0x249];
    int f47c;
    char pad480[4];
    unsigned char b484;
    char pad485[0x7cc - 0x485];
    float slide;
    void Update(float dt);
};

void MessageBox::Update(float dt)
{
    bool open = false;
    if (f240 == 0 && b248)
        open = true;
    if (f47c == 0 && b484)
        open = true;

    FloatBits_d5290 a;

    if (open) {
        a.f = slide;
        a.u &= 0x7fffffff;
        if (a.f <= 1e-5f)
            sink->FUN_001ebd00("MessageBox", "HUD_new_message");

        a.f = slide - DAT_004a06d4;
        a.u &= 0x7fffffff;
        if (a.f <= 1e-5f) {
            slide = DAT_004a06d4;
            return;
        }
        slide = DAT_004a06dc * dt + slide;
        if (slide < DAT_004a06d4)
            return;
        slide = DAT_004a06d4;
    } else {
        a.f = slide - DAT_004a06d4;
        a.u &= 0x7fffffff;
        if (a.f <= 1e-5f)
            sink->FUN_001ebd00("MessageBox", "HUD_new_message");

        a.f = slide;
        a.u &= 0x7fffffff;
        if (a.f <= 1e-5f) {
            slide = 0.0f;
            return;
        }
        slide = slide - DAT_004a06dc * dt;
        if (0.0f < slide)
            return;
        slide = 0.0f;
    }
}
