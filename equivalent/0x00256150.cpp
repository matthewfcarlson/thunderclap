// STATUS: equivalent (tools/equiv.py level 3: 292 inputs, branch coverage 16/16)
// FUN_00256150 @ 0x00256150
struct Pair {
    float value;
    int index;
};

struct Entry {
    float f[4];
    int index;
};

struct Frame {
    Pair pairs[16];
    Entry entries[14];
    char tail[0x28];
};

int __cdecl FUN_00258b70(int handle);
int __cdecl FUN_0025d060(int v);
int __cdecl FUN_0024c2d0(int v);
void __cdecl FUN_00258bf0(int handle, Pair *pairs, int count);
void __cdecl FUN_00258ba0(int handle, Entry *entries, int count);
void __cdecl FUN_00258b80(int handle, float v);

struct Info {
    char pad0[0x14];
    float scale;
    float *factor;
    char pad1c[0x3c - 0x1c];
    float *weights;
    float *vectors;
};

struct Extra {
    char pad0[0x10];
    float amount;
};

struct Arg {
    float base;
    Info *info;
    char pad08[0x3c - 8];
    Extra *extra;
};

class Blender {
public:
    char pad0[0x14];
    int handle;
    void FUN_00256150(Arg *arg);
};

void Blender::FUN_00256150(Arg *arg)
{
    Frame f;
    int count = FUN_0024c2d0(FUN_0025d060(FUN_00258b70(handle)));
    float *weights = arg->info->weights;
    if (weights != 0) {
        for (unsigned int i = 0; i < (unsigned int)count; i++) {
            f.pairs[i].index = i;
            f.pairs[i].value = weights[i] * f.pairs[i].value;
        }
        FUN_00258bf0(handle, f.pairs, count);
    }
    float *vectors = arg->info->vectors;
    if (vectors != 0) {
        for (unsigned int j = 0; j < (unsigned int)count; j++) {
            f.entries[j].index = j;
            f.entries[j].f[0] = vectors[j * 4 + 0];
            f.entries[j].f[1] = vectors[j * 4 + 1];
            f.entries[j].f[2] = vectors[j * 4 + 2];
            f.entries[j].f[3] = vectors[j * 4 + 3];
        }
        FUN_00258ba0(handle, f.entries, count);
    }
    FUN_00258b80(handle, arg->extra->amount * arg->base * *arg->info->factor * arg->info->scale);
}
