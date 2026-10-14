struct Renderer_1b86f0 {
    void Setup(int* out, const char* name);
    unsigned char GetBool(const char* name, int a, int b);
    void Finish();
};
struct Ctl_1b86f0 {
    void Apply(unsigned char v);
};
extern Renderer_1b86f0* gRenderer;
extern int gFlag_1b86f0;
extern unsigned char gCurrentVsync;
extern "C" void __stdcall Target(Ctl_1b86f0* ctl) {
    gRenderer->Setup(&gFlag_1b86f0, "Rendering");
    unsigned char value = gRenderer->GetBool("Lock to VSync", 0x60, 1);
    if (value != gCurrentVsync) {
        gCurrentVsync = value;
        ctl->Apply(value);
    }
    gRenderer->Finish();
}
