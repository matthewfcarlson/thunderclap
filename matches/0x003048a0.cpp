// cl-flags: /O2 /GR /GX

class Buffer_3048a0 {
  public:
    int mSize;
    int mCapacity;
    void* mData;
    char _pad;
    char mFlag;
    char _pad2[2];

    void Grow(int newCapacity);
};

extern "C" void* __cdecl AllocFunc(int size);
extern "C" void __cdecl FreeFunc(void* ptr);
extern "C" void* __cdecl memcpy(void* dst, const void* src, size_t size);

void Buffer_3048a0::Grow(int newCapacity) {
    if (newCapacity == 0)
        newCapacity = 2;
    if (mCapacity >= newCapacity)
        return;

    void* newData = AllocFunc(newCapacity);
    if (mSize > 0) {
        if (mFlag) {
            for (int i = 0; i < mSize; ++i) {
                ((char*)newData)[i] = ((char*)mData)[i];
            }
        } else {
            memcpy(newData, mData, mSize);
        }
    }

    FreeFunc(mData);
    mData = newData;
    mCapacity = newCapacity;
}