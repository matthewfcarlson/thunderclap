// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000b90c0 @ 0x000b90c0
class Renderer_b90c0 {
  public:
    void FUN_001b8820(int* a, int* b, int* c);
    void FUN_001b8840(int* a, int* b, int* c);
    void FUN_001b8860(float* a, float* b, float* c, float* d, float* e, float* f);
    char FUN_001b8810();
    void FUN_001b87d0(int a, int b, int c);
    void FUN_001b87f0(int a, int b, int c);
    void FUN_001b98e0(float a, float b, float c, float d, float e, float f);
    void FUN_001b8780(int flag);
};
class Menu_b90c0 {
  public:
    char pad0[0x54];
    Renderer_b90c0* renderer;
    char pad1[0x1d00 - 0x58];
    unsigned char savedFlag;
    char pad2[3];
    int saved0[3];
    int saved1[3];
    float saved2[6];
    void FUN_000b90c0(bool save);
};

void Menu_b90c0::FUN_000b90c0(bool save) {
    if (save) {
        renderer->FUN_001b8820(&saved0[0], &saved0[1], &saved0[2]);
        renderer->FUN_001b8840(&saved1[0], &saved1[1], &saved1[2]);
        renderer->FUN_001b8860(&saved2[0], &saved2[1], &saved2[2], &saved2[3], &saved2[4], &saved2[5]);
        savedFlag = renderer->FUN_001b8810();
        renderer->FUN_001b87d0(255, 255, 255);
        renderer->FUN_001b87f0(255, 255, 255);
        renderer->FUN_001b98e0(1.0f, 0.1f, 12.0f, -24.0f, 0.0f, 0.0f);
        renderer->FUN_001b8780(1);
    } else {
        renderer->FUN_001b87d0(saved0[0], saved0[1], saved0[2]);
        renderer->FUN_001b87f0(saved1[0], saved1[1], saved1[2]);
        renderer->FUN_001b98e0(saved2[0], saved2[1], saved2[2], saved2[3], saved2[4], saved2[5]);
        renderer->FUN_001b8780(savedFlag);
    }
}
