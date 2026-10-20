// Same code shape as 0x000f27a0 (propagated; names are from that function)
#include "gen/global.h"
extern void* Alloc(unsigned int);
struct FEBillboardAnimation_nv_f2920 {
    int Create(int, int);
};
class Holder_f2920 {
  public:
    int field;
    int data;
    int slots[32];
    int Run(int arg);
};
int Holder_f2920::Run(int arg) {
    if (data == 0)
        return 0;
    FEBillboardAnimation* obj = (FEBillboardAnimation*)Alloc(100);
    int result;
    if (obj != 0)
        result = ((FEBillboardAnimation_nv_f2920*)(obj))->Create(data, arg);
    else
        result = 0;
    int i;
    for (i = 0; i < 32; ++i) {
        if (slots[i] == 0) {
            if (result != 0)
                slots[i] = result;
            return result;
        }
    }
    return result;
}
