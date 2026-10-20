extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
extern "C" void __cdecl FUN_002a7f60(void*, unsigned int, unsigned int);
class Buffer_2a8060 {
  public:
    void* mData;
    char* mEnd;
    bool Init(unsigned int size, unsigned int arg);
};
bool Buffer_2a8060::Init(unsigned int size, unsigned int arg) {
    if (mData != 0)
        return false;
    if (size > 0) {
        void* p = FUN_0008d6d0(size);
        mData = p;
        if (p != 0) {
            mEnd = (char*)p + size;
            FUN_002a7f60(p, size, arg);
            return true;
        }
    }
    mData = 0;
    mEnd = 0;
    return false;
}