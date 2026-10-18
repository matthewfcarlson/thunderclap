int __cdecl FUN_0024c4d0(int a, int b);
int __cdecl FUN_0024c480(void* header, int bytes);

class Source {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int GetUnit();
};

namespace audio {
class HalStream {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual bool vfunc_8(int* out);
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    Source* source;
};

class HalRadicalAdpcmDecodeStream : public HalStream {
public:
    char header[0x10];
    int position;
    int state;
    virtual bool vfunc_8(int* out);
};

bool HalRadicalAdpcmDecodeStream::vfunc_8(int* out)
{
    if (state == 3)
        return false;
    *out = FUN_0024c480(header, FUN_0024c4d0(source->GetUnit(), position));
    state = 2;
    return true;
}
}
