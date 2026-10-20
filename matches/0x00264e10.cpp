#include "compat/ptr.h"
struct Pair_264e10 {
    unsigned a;
    unsigned b;
};
class Queue_264e10 {
  public:
    unsigned mBegin;
    Pair_264e10* mNext;
    Pair_264e10* mEndQueue;
    Pair_264e10* mLimit;
    bool Push(Pair_264e10* value);
};
bool Queue_264e10::Push(Pair_264e10* value) {
    Pair_264e10* p = mNext;
    if (p < mLimit) {
        if (p != 0) {
            p->a = value->a;
            p->b = value->b;
        }
        mNext = (Pair_264e10*)((char*)mNext + 8);
        if (mNext == mLimit)
            mNext = mEndQueue;
        if (mBegin == (hulk_uintptr)mNext)
            mNext = (Pair_264e10*)((char*)mNext + (((char*)mLimit - (char*)mEndQueue) >> 3) * 8);
        return true;
    }
    return false;
}