// STATUS: equivalent (tools/equiv.py level 3: 123 inputs, branch coverage 37/38, incomplete)
// FUN_003265f0 @ 0x003265f0
typedef unsigned long DWORD;
struct Texture;
struct Palette;
struct SurfaceDesc {
    DWORD Format, Type, Usage, Size, MultiSampleType, Width, Height;
};
namespace D3D8 {
Texture* __stdcall D3DDevice_CreateTexture2(DWORD width, DWORD height, DWORD depth, DWORD levels, DWORD usage, DWORD format, DWORD type);
Palette* __stdcall D3DDevice_CreatePalette2(DWORD size);
}
void __stdcall thunk_FUN_0038acb0(Texture* tex, DWORD level, SurfaceDesc* out);
void FUN_0031c230(long hr);
// equiv-conv: FUN_00325fb0 edx
int FUN_00325fb0(int mask);
void FUN_0031e1f0(Texture* tex, int size);
struct Layout {
    int f0, f4, f8, fc, f10;
    char pad14[0x44 - 0x14];
    int mask;
    char pad48[0x54 - 0x48];
};
void FUN_0031c600(SurfaceDesc* desc, int a, Layout* out, int b);
struct Ctx {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual int GetMaxTextureSize();
};
// equiv-conv: FUN_00325fd0 eax edx ecx stack
int FUN_00325fd0(int a4, int a5, int a7, Ctx* ctx);
struct TextureBuilder {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void SetFormat(int);
    char pad4[4];
    int error;
    Ctx* ctx;
    char pad10[0x18 - 0x10];
    Texture* tex;
    char pad1c[0x68 - 0x1c];
    Palette* palette;
    int format;
    Layout layout;
    int c4pad;
    int srcFormat;
    int usage;
    int field_d0;
    int width;
    int height;
    int field_dc;
    int field_e0;
    int levels;
    int totalSize;
    unsigned char hasAlpha;
    unsigned char isPaletted;
    char padee[2];
    int fieldf0;
    bool Create(int width, int height, int depth, int a4, int a5, int levels, int a7, int a8);
};
bool TextureBuilder::Create(int w, int h, int d, int a4, int a5, int lvls, int a7, int a8) {
    if ((w & (w - 1)) != 0 || (h & (h - 1)) != 0 || (d & (d - 1)) != 0) {
        error = 0xc8;
        return false;
    }
    if (w > ctx->GetMaxTextureSize() || h > ctx->GetMaxTextureSize() || d > ctx->GetMaxTextureSize()) {
        error = 0xc9;
        return false;
    }
    int fmt = FUN_00325fd0(a4, a5, a7, ctx);
    format = fmt;
    if (fmt == -1) {
        error = 0xca;
        return false;
    }
    srcFormat = a7;
    usage = a8;
    field_d0 = 0;
    this->levels = lvls;
    width = w;
    height = h;
    hasAlpha = (a7 == 4 || a7 == 5 || a7 == 6 || a7 == 7 || a7 == 8);
    isPaletted = (a7 == 0xb);
    tex = D3D8::D3DDevice_CreateTexture2(w, h, d, lvls + 1, a8, fmt, 4);
    FUN_0031c230(tex ? 0 : 0x8007000e);
    if (format == 0xb)
        palette = D3D8::D3DDevice_CreatePalette2(0);
    SurfaceDesc desc;
    thunk_FUN_0038acb0(tex, 0, &desc);
    FUN_0031c230(0);
    SetFormat(fieldf0);
    FUN_0031c600(&desc, 0, &layout, 1);
    int stride = layout.f8;
    field_d0 = layout.f10;
    field_dc = stride;
    field_e0 = FUN_00325fb0(layout.mask);
    totalSize = 0;
    float scale;
    if (hasAlpha)
        scale = 0.5f;
    else
        scale = (float)(stride / 8);
    int cw = width;
    int ch = height;
    int cd = d;
    for (int i = 0; i < this->levels + 1; i++) {
        unsigned int size = cd * ch * cw;
        totalSize += (int)((float)size * scale);
        cw = (unsigned int)cw >> 1;
        ch = (unsigned int)ch >> 1;
        cd = (unsigned int)cd >> 1;
    }
    FUN_0031e1f0(tex, totalSize);
    return true;
}
