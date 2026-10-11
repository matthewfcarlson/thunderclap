// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 28/28)
// FUN_00324e00 @ 0x00324e00
// FUN_00324e00 @ 0x00324e00
struct HeapObj {
    static void* operator new(unsigned size) throw();
};
struct Matrix {
    float m[16];
    void FUN_0022b980();
};
class d3dContext;
class AssetSource {
  public:
    virtual void AddRef();
    char pad4[0x10 - 4];
    int handle;
};
class Allocator {
  public:
    virtual void AddRef();
};
class StateCache : public HeapObj {
  public:
    StateCache(d3dContext* ctx, int handle) throw();
    char pad[0x124];
};
class LightPool : public HeapObj {
  public:
    LightPool(d3dContext* ctx) throw();
    char pad[0x3cf8];
};
class FrameBufferEffects : public HeapObj {
  public:
    FrameBufferEffects(d3dContext* ctx) throw();
    char pad[0x190];
};
class ShaderCache : public HeapObj {
  public:
    ShaderCache(d3dContext* ctx) throw();
    virtual void f0();
    char pad[0x94 - 4];
};
class d3dExtGammaControl : public HeapObj {
  public:
    virtual void f0();
    AssetSource* src;
    d3dExtGammaControl(AssetSource* s) throw() { src = s; }
};
class d3dExtAntialiasControl : public HeapObj {
  public:
    virtual void f0();
    d3dContext* ctx;
    d3dExtAntialiasControl(d3dContext* c) throw() { ctx = c; }
};
class d3dExtReadPixels : public HeapObj {
  public:
    virtual void f0();
    d3dContext* ctx;
    d3dExtReadPixels(d3dContext* c) throw() { ctx = c; }
};
class d3dExtGlobalProjectedTexture : public HeapObj {
  public:
    virtual void f0();
    int zero[16];
    char pad[0x444 - 0x44];
    d3dExtGlobalProjectedTexture() throw() {
        for (int i = 0; i < 16; i++)
            zero[i] = 0;
    }
};
class d3dExtHardwareSkinning : public HeapObj {
  public:
    virtual void f0();
    d3dContext* ctx;
    d3dExtHardwareSkinning(d3dContext* c) throw() { ctx = c; }
};
class d3dExtVisibilityTest : public HeapObj {
  public:
    virtual void f0();
    d3dContext* ctx;
    d3dExtVisibilityTest(d3dContext* c) throw() { ctx = c; }
};
class d3dExtVertexProgram : public HeapObj {
  public:
    virtual void f0();
    d3dContext* ctx;
    d3dExtVertexProgram(d3dContext* c) throw() { ctx = c; }
};
class d3dExtFrameBufferTexture : public HeapObj {
  public:
    virtual void f0();
    d3dContext* ctx;
    int a, b, c;
    d3dExtFrameBufferTexture(d3dContext* x) throw() {
        ctx = x;
        a = 0;
        b = 0;
        c = 0;
    }
};
void FUN_00328690(d3dContext*);
struct LargeInt { unsigned int lo; int hi; };
void __stdcall FUN_00354ce2(LargeInt*);
class pddiBaseContext {
  public:
    pddiBaseContext(AssetSource* a, Allocator* b) throw();
    virtual void f0();
    char pad[0x14c - 4];
};
class d3dContext : public pddiBaseContext {
  public:
    int counter;
    StateCache* stateCache;
    AssetSource* src;
    Allocator* alloc;
    char pad15c[4];
    ShaderCache* shaders;
    int handle;
    int f168;
    int f16c;
    int f170;
    int width;
    int height;
    int f17c;
    float f180;
    char pad184[0x204 - 0x184];
    int f204;
    LightPool* lightPool;
    Matrix lightMatrices[8];
    unsigned char lightDirty[8];
    unsigned char anyLightDirty;
    char pad415[3];
    int f418;
    int f41c;
    float msPerTick;
    d3dExtGammaControl* gamma;
    d3dExtAntialiasControl* antialias;
    d3dExtGlobalProjectedTexture* projTex;
    d3dExtReadPixels* readPixels;
    d3dExtHardwareSkinning* hwSkinning;
    d3dExtVisibilityTest* visTest;
    d3dExtVertexProgram* vertexProgram;
    FrameBufferEffects* fbEffects;
    d3dExtFrameBufferTexture* fbTexture;
    int f448;
    unsigned char f44c;
    virtual void f1();
    d3dContext(AssetSource* a, Allocator* b) throw();
};
d3dContext::d3dContext(AssetSource* a, Allocator* b) throw() : pddiBaseContext(a, b) {
    counter = 0;
    f168 = 0;
    f204 = 0;
    f418 = 0;
    f41c = 0;
    f448 = 0;
    f44c = 0;
    FUN_00328690(this);
    src = a;
    a->AddRef();
    alloc = b;
    b->AddRef();
    handle = src->handle;
    stateCache = new StateCache(this, handle);
    f16c = 0;
    f170 = 0;
    width = 0x280;
    height = 0x1e0;
    f17c = 0;
    f180 = 1.0f;
    LargeInt freq;
    FUN_00354ce2(&freq);
    msPerTick = 1000.0f / (float)freq.lo;
    lightPool = new LightPool(this);
    for (int i = 0; i < 8; i++) {
        lightMatrices[i].FUN_0022b980();
        lightDirty[i] = 0;
    }
    anyLightDirty = 0;
    gamma = new d3dExtGammaControl(src);
    antialias = new d3dExtAntialiasControl(this);
    readPixels = new d3dExtReadPixels(this);
    projTex = new d3dExtGlobalProjectedTexture();
    hwSkinning = new d3dExtHardwareSkinning(this);
    visTest = new d3dExtVisibilityTest(this);
    vertexProgram = new d3dExtVertexProgram(this);
    fbEffects = new FrameBufferEffects(this);
    fbTexture = new d3dExtFrameBufferTexture(this);
    shaders = new ShaderCache(this);
    shaders->f0();
}
