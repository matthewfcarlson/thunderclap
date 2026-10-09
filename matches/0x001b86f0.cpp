struct Renderer {
    void Setup(int* out, const char* name);
    unsigned char GetBool(const char* name, int a, int b);
    void Finish();
};
struct Ctl {
    void Apply(unsigned char v);
};
extern Renderer* gRenderer;
extern int gFlag;
extern unsigned char gCurrentVsync;
extern "C" void __stdcall Target(Ctl* ctl) {
    gRenderer->Setup(&gFlag, "Rendering");
    unsigned char value = gRenderer->GetBool("Lock to VSync", 0x60, 1);
    if (value != gCurrentVsync) {
        gCurrentVsync = value;
        ctl->Apply(value);
    }
    gRenderer->Finish();
}
