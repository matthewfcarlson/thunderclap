// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 10/10)
// pure3d::ImageConverter::vfunc_7 @ 0x002deca0
extern void __cdecl FUN_0028fcc0(const char* format, ...);

struct SourceImage {
    int width;            // 0x00
    int height;           // 0x04
    char pad08[8];
    int format;           // 0x10
};

struct Texture {
    char pad00[0x10];
    int width;            // 0x10
    int height;           // 0x14
    const char* FUN_0027b000();
};

void __stdcall FUN_002de5a0(Texture* dest, SourceImage* src);
void __stdcall FUN_002de990(Texture* dest, SourceImage* src);
void __stdcall FUN_002de9c0(Texture* dest, SourceImage* src);

namespace pure3d {

class ImageConverter {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7(Texture* dest, SourceImage* src);
};

void ImageConverter::vfunc_7(Texture* dest, SourceImage* src)
{
    if (dest->width != src->width || dest->height != src->height) {
        FUN_0028fcc0("Pure3D : ImageConverter::UpdateTexture() src size != dest size, image : %s\n",
                     dest->FUN_0027b000());
        return;
    }
    switch (src->format) {
    case 1:
    case 2:
    case 3:
    case 4:
        FUN_002de990(dest, src);
        return;
    case 6:
        FUN_002de9c0(dest, src);
        return;
    case 7:
        FUN_002de5a0(dest, src);
        return;
    }
}

}
