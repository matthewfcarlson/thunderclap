int __cdecl FUN_0024c3e0(int a, int b);
int __cdecl FUN_0024c3b0(void* header, int bytes);

class Source {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int GetUnit();
    virtual void vfunc_3();
    virtual int NextBlock();
};

namespace audio {
class HalStream {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual int vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    Source* source;
};

class HalRadicalAdpcmDecodeStream : public HalStream {
public:
    char header[0x20];
    virtual int vfunc_4();
};

int HalRadicalAdpcmDecodeStream::vfunc_4()
{
    int block = source->NextBlock();
    if (block == -1)
        return -1;
    return FUN_0024c3b0(header, FUN_0024c3e0(source->GetUnit(), block) << 5);
}
}
