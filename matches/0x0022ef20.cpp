#include "gen/owners.h"
struct Sub_22ef20 {
    void Update(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};
char owners::Obj_22ef20::FUN_0022ef20(int index, float value) {
    int i = (int)value;
    if (i == (int)mCache[index])
        return 0;
    unsigned int q = mDiv, b = mBase;
    unsigned int a = ((i + 3) % q) * 16 + b, c = ((i + 2) % q) * 16 + b, d = ((i + 1) % q) * 16 + b,
                 e = (i % q) * 16 + b;
    Sub_22ef20* sub = (Sub_22ef20*)((char*)this + 8 + index * 128);
    sub->Update(mSize, e, d, c, a);
    mCache[index] = i;
    return 1;
}