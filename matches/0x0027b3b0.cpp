extern "C" void* __cdecl Allocate(unsigned int);
class Buffer_27b3b0 {
  public:
    int *mStart, *mCurrent, *mEnd;
    bool Create(int count);
};
bool Buffer_27b3b0::Create(int count) {
    int* p;
    if (count != 0) {
        p = (int*)Allocate(count * 24);
        mStart = p;
        if (p != 0) {
            mCurrent = p;
            mEnd = (int*)((char*)p + count * 24);
            return true;
        }
    } else
        mStart = 0;
    mCurrent = 0;
    mEnd = 0;
    return false;
}