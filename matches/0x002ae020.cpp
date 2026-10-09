extern "C" void* memcpy(void*, const void*, unsigned int);

namespace pure3d {
class ImageHandler {
public:
    class Builder {
    public:
        virtual void vfunc_0();
        virtual void vfunc_1();
        virtual void vfunc_2();
        virtual void vfunc_3();
        virtual void vfunc_4();
        virtual void vfunc_5();
        virtual void vfunc_6();
        virtual void vfunc_7();
        virtual void vfunc_8();
        virtual void vfunc_9();
    };
};

class ImageBuilder : public ImageHandler::Builder {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(const void* src);
    virtual void vfunc_2();
    virtual void vfunc_10();
    char* mContext;
    char pad8[4];
    char* mData;
    unsigned int mCount;
    unsigned int mStride;
};

void ImageBuilder::vfunc_1(const void* src) {
    unsigned int n = *reinterpret_cast<unsigned int*>(mContext + 0x10);
    memcpy(mData, src, n << 2);
    mData += mStride;
    ++mCount;
}
}
