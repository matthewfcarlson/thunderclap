// STATUS: equivalent (tools/equiv.py level 3: 60 inputs, branch coverage 73/74, incomplete)
// FUN_00320540 @ 0x00320540
extern "C" char * __cdecl _strncpy(char *, const char *, unsigned int);
extern char DAT_00432da0[];
extern "C" int __stdcall FUN_003a8753(int, const char *, int, int, int, void **, int, int, int, int, int);
extern "C" void * __stdcall FUN_003a04fc(void *);
namespace D3D8 { extern "C" int __stdcall D3DDevice_CreatePixelShader(void *, unsigned int *); }
extern "C" void __stdcall FUN_003a41dc(void *);

struct ShaderCollection {
    char padding[36];
    unsigned int shaders[17];
    unsigned char FUN_00320540();
};

struct Frame_320540 {
    void *compiled;
    ShaderCollection *self;
    unsigned int *slot;
    float levels[8];
};

unsigned char ShaderCollection::FUN_00320540() {
    Frame_320540 f;
    f.self = this;
    f.levels[0] = 1.0f; f.levels[1] = 2.0f; f.levels[2] = 4.0f; f.levels[3] = 8.0f;
    f.levels[4] = 16.0f; f.levels[5] = 32.0f; f.levels[6] = 64.0f; f.levels[7] = 255.0f;
    const char *const add = "add     r0.xyz, r0.xyz, r1.w \n";
    const char *const doubleAlpha = "+mov_x2 r1.w,   r1.w \n";
    unsigned char succeeded = 1;

    for (int level = 0; level < 8; ++level) {
        for (int pass = 0; pass < (level == 7 ? 1 : 2); ++pass) {
            char source[1024] = {0};
            if (level == 7) {
                f.slot = &f.self->shaders[16];
                _strncpy(source, DAT_00432da0, 1023);
            } else {
                f.slot = &f.self->shaders[level * 2 + pass];
                const char *parts[24];
                int partCount = 0;
                parts[partCount++] = "xps.1.1 \n";
                parts[partCount++] = "def     c1, 0.5, 0.5, 0.5, 0.5 \n";
                parts[partCount++] = "tex     t0 \n";
                parts[partCount++] = "dp3     r0,     t0, c0 \n";
                parts[partCount++] = "add     r0.xyz, t0, -r0 \n";
                parts[partCount++] = "+mad    r1.w,   r0.w, c5, c3_bx2 \n";
                parts[partCount++] = "mul_x2  r0.xyz, r0, c7 \n";
                if (f.levels[level] >= 32.0f)
                    parts[partCount++] = "+mov_x4 r1.w,   r1.w \n";
                else if (f.levels[level] >= 16.0f)
                    parts[partCount++] = doubleAlpha;
                parts[partCount++] = "mad     r0.xyz, c6_bx2, r0.w, r0 \n";
                if (f.levels[level] == 64.0f)
                    parts[partCount++] = doubleAlpha;
                parts[partCount++] = add;

                if (pass == 0) {
                    if (f.levels[level] > 1.0f) {
                        parts[partCount++] = add;
                        if (f.levels[level] > 2.0f) {
                            parts[partCount++] = doubleAlpha;
                            parts[partCount++] = add;
                            if (f.levels[level] > 4.0f) {
                                parts[partCount++] = doubleAlpha;
                                parts[partCount++] = add;
                            }
                        }
                    }
                } else {
                    parts[partCount++] = add;
                    if (f.levels[level] > 1.0f) {
                        parts[partCount++] = doubleAlpha;
                        parts[partCount++] = add;
                        if (f.levels[level] > 2.0f) {
                            parts[partCount++] = doubleAlpha;
                            parts[partCount++] = add;
                        }
                    }
                }

                char *end = source;
                for (int part = 0; part < partCount; ++part) {
                    const char *text = parts[part];
                    while (*text)
                        *end++ = *text++;
                }
            }

            int length = 0;
            while (source[length])
                ++length;
            f.compiled = 0;
            int result = FUN_003a8753(0, source, length, 0, 0, &f.compiled, 0, 0, 0, 0, 0);
            succeeded &= result == 0;
            if (f.compiled) {
                void *shader = FUN_003a04fc(f.compiled);
                D3D8::D3DDevice_CreatePixelShader(shader, f.slot);
                FUN_003a41dc(f.compiled);
            }
        }
    }
    return succeeded;
}