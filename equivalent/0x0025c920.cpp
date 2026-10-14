// STATUS: equivalent (tools/equiv.py level 3: 12 inputs, branch coverage 6/8, incomplete)
// FUN_0025c920 @ 0x0025c920
extern "C" int sprintf(char* dst, const char* fmt, ...);

class Str_25c920 {
public:
    char* data;
    short mode;
    short pad6;
    short length;
    short pad10;

    Str_25c920* FUN_0023fd20(int capacity);
    Str_25c920* FUN_0023fc40(const char* text, int flag);
    Str_25c920* FUN_0023fc90(const char* text, int len, int mode);
    Str_25c920* FUN_00240190(const Str_25c920* other);
    Str_25c920* FUN_0023ff50(const Str_25c920* other);
    Str_25c920* FUN_00240170(const Str_25c920* other);
    void FUN_00240060();
    const char* FUN_0023fb00();
};

extern int DAT_004cd264;
Str_25c920* __cdecl FUN_00262700(Str_25c920* path, const Str_25c920* part);

Str_25c920* __cdecl FUN_0025c920(Str_25c920* out, const Str_25c920* dir, const unsigned long long* id, const Str_25c920* extra)
{
    Str_25c920 path;
    Str_25c920 tmp;
    Str_25c920 hex;
    char name[0x20];
    char ch[2];

    path.FUN_0023fd20(0x48);
    path.FUN_00240190(tmp.FUN_0023fc40("", 0));
    tmp.FUN_00240060();

    sprintf(name, "%8.8x", (unsigned int)(*id >> 32));
    sprintf(name + 8, "%8.8x", (unsigned int)*id);
    hex.FUN_0023fc90(name, 0x10, 2);

    if (dir)
        FUN_00262700(&path, dir);
    if (extra)
        FUN_00262700(&path, extra);

    ch[1] = 0;
    const char* p = hex.FUN_0023fb00();
    const char* end = p + DAT_004cd264;
    while (p < end) {
        ch[0] = *p;
        p++;
        FUN_00262700(&path, tmp.FUN_0023fc40(ch, 1));
        tmp.FUN_00240060();
    }
    FUN_00262700(&path, &hex);

    path.FUN_0023ff50(tmp.FUN_0023fc40(".rsd", 0));
    tmp.FUN_00240060();

    out->FUN_00240170(&path);
    hex.FUN_00240060();
    path.FUN_00240060();
    return out;
}
