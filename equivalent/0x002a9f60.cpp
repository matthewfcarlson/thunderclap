// STATUS: equivalent (tools/equiv.py level 3: 59 inputs, branch coverage 10/10)
// pure3d::ExpressionAnimationController::vfunc_7 @ 0x002a9f60
// pure3d::ExpressionAnimationController::vfunc_7: reset the channel values, then refill them from the "FLT1" chunks
struct Channel {
    void FUN_0028a1c0(int a, float *out);
};

struct Chunk {
    Channel *FUN_00288960(int tagA, int tagB);
};

struct Chunks {
    char pad00[0x28];
    int count;
    Chunk *FUN_00288a10(int index);
};

struct Index {
    int FUN_002afe80(void *name);
};

struct Output {
    char pad00[0x10];
    Index *index;
    float *values;
    void FUN_002b0cd0(int arg);
};

class ExpressionAnimationController {
public:
    char pad00[0x34];
    int f34;
    char pad38[4];
    Chunks *chunks;
    Output *output;
    int f44;
    int count;
    int *zeros;

    void FUN_002a9f60();
};

void ExpressionAnimationController::FUN_002a9f60()
{
    for (int i = 0; i < count; i++)
        zeros[i] = 0;
    int n = chunks->count;
    for (int i = 0; i < n; i++) {
        Chunk *c = chunks->FUN_00288a10(i);
        Channel *ch = c->FUN_00288960(0x455453, 0x31544c46);
        if (ch != 0) {
            float v;
            ch->FUN_0028a1c0(f34, &v);
            float saved = v;
            int slot = output->index->FUN_002afe80((char *)c + 8);
            output->values[slot] = saved;
        }
    }
    output->FUN_002b0cd0(f44);
}
