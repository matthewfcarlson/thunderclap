#include "gen/pure3d.h"

typedef unsigned int uint;
struct Item_2a2a30 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual uint v7();
};
struct Entry_2a2a30 {
    uint unused;
    Item_2a2a30** item;
    uint a, b;
};
void __cdecl FUN_002a27c0(uint pass, uint count, uint* input, uint* output);
namespace pure3d {

} // namespace pure3d
void pure3d::OpaqueTraversal::vfunc_3() {
    uint keys[1024];
    uint temp[1024];
    if ((*(unsigned char *)&this->f_1c)) {
        for (uint i = 0; i < (*(uint *)&this->f_18); ++i) {
            uint h = (*(*(Entry_2a2a30 * *)&this->f_20)[i].item)->v7();
            keys[i] = ((h + (h >> 16)) & 0xffff) | (i << 22);
        }
        uint n = (*(uint *)&this->f_18);
        FUN_002a27c0(0, n, keys, temp);
        FUN_002a27c0(1, n, temp, keys);
        for (uint j = 0; j < (*(uint *)&this->f_18); ++j)
            (*(Entry_2a2a30 ** *)&this->f_2c)[j] = (*(Entry_2a2a30 * *)&this->f_20) + (keys[j] >> 22);
    }
}
