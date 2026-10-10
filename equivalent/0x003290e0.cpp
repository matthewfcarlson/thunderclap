// STATUS: equivalent (tools/equiv.py level 3: 42 inputs, branch coverage 43/44, incomplete)
// FUN_003290e0 @ 0x003290e0
namespace D3D8 {
int __stdcall D3DDevice_CreateVertexShader(const unsigned int* decl, const void* program, unsigned int* handle, int usage);
}
extern unsigned int __cdecl FUN_00329060(const char* name);
extern void __cdecl FUN_0031c230(int hr);
struct ShaderEntry {
    int unk0;
    unsigned int a;
    unsigned int flags;
    int c;
    int size;
    unsigned int handle;
};
struct ShaderGroup {
    unsigned int hash;
    const void* program;
    unsigned int count;
    ShaderEntry entries[32];
};
struct DeclFrame {
    char pad0[0x13];
    unsigned char b;
    unsigned int handle;
    unsigned int decl[63];
};
class ShaderCache {
  public:
    int pad0;
    unsigned int count;
    ShaderGroup groups[1];
    ShaderEntry* Get(const char* name, unsigned int a, unsigned int flags, int c);
};
ShaderEntry* ShaderCache::Get(const char* name, unsigned int a, unsigned int flags, int c) {
    DeclFrame F;
    unsigned int hash = FUN_00329060(name);
    F.b = (unsigned char)(c & 1);
    ShaderGroup* g = &groups[0];
    for (unsigned int i = 0; i < count; i++) {
        if (groups[i].hash == hash) {
            g = &groups[i];
            break;
        }
    }
    for (unsigned int k = 0; k < g->count; k++) {
        ShaderEntry* e = &g->entries[k];
        if (e->a == a && e->flags == flags && e->c == c)
            return e;
    }
    ShaderEntry* e = &g->entries[g->count];
    g->count++;
    int n = 2;
    int size = 0xc;
    F.decl[0] = 0x20000000;
    F.decl[1] = 0x40320000;
    if (flags & 0x100) {
        n = 3;
        if (F.b) {
            F.decl[2] = 0x40160001;
            size = 0x10;
        } else {
            F.decl[2] = 0x40320001;
            size = 0x18;
        }
    }
    if (flags & 0x80) {
        F.decl[n++] = 0x4040000f;
        size += 4;
    }
    if (flags & 0x10) {
        if (F.b) {
            F.decl[n++] = 0x40160002;
            size += 4;
        } else {
            F.decl[n++] = 0x40320002;
            size += 0xc;
        }
    }
    if (flags & 0x20) {
        F.decl[n++] = 0x40400003;
        size += 4;
    }
    if (flags & 0x4000) {
        F.decl[n++] = 0x40400003;
        F.decl[n++] = 0x40400004;
        size += 8;
    }
    if (flags & 0x40) {
        F.decl[n++] = 0x40400004;
        size += 4;
    }
    unsigned int cnt = flags & 0xf;
    if (cnt) {
        size += cnt * 8;
        for (unsigned int i = 0; i < cnt; i++)
            F.decl[n++] = (i + 9) | 0x40220000;
    }
    if (flags & 0x200) {
        F.decl[n++] = 0x4012000e;
        size += 4;
    }
    if (flags & 0x400) {
        F.decl[n++] = 0x4012000d;
        size += 4;
    }
    if (flags & 0x800) {
        F.decl[n++] = 0x40320006;
        size += 0xc;
    }
    if (flags & 0x1000) {
        F.decl[n++] = 0x4032000f;
        size += 0xc;
    }
    F.decl[n] = 0xffffffff;
    F.handle = 0;
    int hr = D3D8::D3DDevice_CreateVertexShader(F.decl, g->program, &F.handle, 0);
    FUN_0031c230(hr);
    e->handle = F.handle;
    e->flags = flags;
    e->size = size;
    e->a = a;
    e->c = c;
    return e;
}
