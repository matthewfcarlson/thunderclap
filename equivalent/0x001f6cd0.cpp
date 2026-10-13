// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001f6cd0 @ 0x001f6cd0
extern "C" unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int __cdecl _sprintf(char *buf, const char *fmt, ...);

extern const char *DAT_004c8070[];
extern const char *DAT_004c8098[];

struct Vec3 { int x, y, z; };

struct Source {
    char pad0[0x16];
    unsigned short bits;
};

struct HitInfo {
    int f0;
    char pad[0x2b8 - 4];
    void FUN_001d1630();
};

struct Library {
    int FUN_001d3b00(const char *name, HitInfo info);
};
Library *__cdecl FUN_001d4c90();

struct Frame {
    char name[0x80];
    HitInfo info;
    unsigned int cookie;
};

class Reaction {
public:
    char pad0[0x1c];
    Source *source;     // 0x1c
    int arg20;          // 0x20
    Vec3 v24;           // 0x24
    Vec3 v30;           // 0x30
    Vec3 v3c;           // 0x3c
    int arg48;          // 0x48
    char pad4c[0x58 - 0x4c];
    int arg58;
    int arg5c;
    void FUN_001f6cd0(Source *src, int a1, const Vec3 *a2, const Vec3 *a3, const Vec3 *a4,
                      int a5, int a6, int a7, const char **outName, int a9);
};

void Reaction::FUN_001f6cd0(Source *src, int a1, const Vec3 *a2, const Vec3 *a3, const Vec3 *a4,
                            int a5, int a6, int a7, const char **outName, int a9)
{
    Frame f;
    f.cookie = DAT_004d9968;
    unsigned short kind = (src->bits >> 5) & 0x1f;
    if (kind < 0x13) {
        if (outName)
            *outName = DAT_004c8098[kind];
        if (kind != 0x12) {
            f.info.FUN_001d1630();
            arg20 = a1;
            source = src;
            v24 = *a2;
            v30 = *a3;
            v3c = *a4;
            arg48 = a1;
            arg58 = a6;
            arg5c = a7;
            f.info.f0 = 0;
            _sprintf(f.name, "Damage_%s_%s", DAT_004c8070[a5], DAT_004c8098[kind]);
            if (!FUN_001d4c90()->FUN_001d3b00(f.name, f.info)) {
                _sprintf(f.name, "Damage_%s_Generic", DAT_004c8070[a5]);
                FUN_001d4c90()->FUN_001d3b00(f.name, f.info);
            }
        }
    }
    __security_check_cookie(f.cookie);
}
