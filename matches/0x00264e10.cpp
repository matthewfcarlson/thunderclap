struct Pair { unsigned a; unsigned b; };
class Queue { public: unsigned mBegin; Pair *mNext; Pair *mEndQueue; Pair *mLimit; bool Push(Pair *value); };
bool Queue::Push(Pair *value)
{
    Pair *p = mNext;
    if (p < mLimit) {
        if (p != 0) { p->a = value->a; p->b = value->b; }
        mNext = (Pair *)((char *)mNext + 8);
        if (mNext == mLimit) mNext = mEndQueue;
        if (mBegin == (unsigned)mNext)
            mNext = (Pair *)((char *)mNext + (((char *)mLimit - (char *)mEndQueue) >> 3) * 8);
        return true;
    }
    return false;
}