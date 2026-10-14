// STATUS: equivalent (tools/equiv.py level 3: 2455 inputs, branch coverage 0/0)
// FUN_00255ed0 @ 0x00255ed0
struct Pair {
    unsigned int bits;
    int value;
};

struct Source {
    char pad0[0x28];
    int handle;
};

struct Context {
    char pad0[0x28];
    int *wordPtr;       // +0x28
    float result;       // +0x2c
    int param;          // +0x30
    char pad34[0];
};

struct Context2 {
    char pad0[0x28];
    int *wordPtr;       // +0x28
    float result;       // +0x2c
    int param;          // +0x30
    int *constPtr;      // +0x34
};

struct Binding {
    char pad0[4];
    Context2 *context;
};

int __cdecl FUN_0025d060(int handle);
void __cdecl FUN_0025be60(int key, Pair *out);
int __cdecl FUN_00258f00(int id);
int __cdecl FUN_0024c4d0(Pair *pair, int id);
float __cdecl FUN_00261bb0(int word, int param, int a, unsigned int bits, int constant);

class Sampler {
public:
    void FUN_00255ed0(Binding *binding);

    char pad0[0xc];
    int id;             // +0x0c
    Source *source;     // +0x10
    int sourceId;       // +0x14
};

void Sampler::FUN_00255ed0(Binding *binding) {
    Pair pair;
    FUN_0025be60(FUN_0025d060(source->handle), &pair);
    id = FUN_00258f00(sourceId);
    int a = FUN_0024c4d0(&pair, id);
    Context2 *ctx = binding->context;
    int constant = *ctx->constPtr;
    int word = *ctx->wordPtr;
    ctx->result = FUN_00261bb0(word, ctx->param, a, (pair.bits >> 9) & 0x1ffff, constant);
}
