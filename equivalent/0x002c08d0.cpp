// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// pure3d::Image8::vfunc_12 @ 0x002c08d0
namespace pure3d {
struct Image8 {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(Image8* source, int x, int y, int width, int height, int destX, int destY);
    char pad04[12]; int width; int height; char pad18[4]; unsigned char key; char pad1d[7]; unsigned char* pixels; unsigned char pad28; unsigned char transparent;
};
}
// equiv-conv: FUN_002c02b0 ecx eax stack stack stack stack stack stack
void __cdecl FUN_002c02b0(pure3d::Image8* source, int y, unsigned char* dest, int x, int width, int height, int stride, unsigned int key);
// equiv-conv: FUN_002c0240 ecx eax ebx stack stack stack stack
void __cdecl FUN_002c0240(pure3d::Image8* source, int y, int x, unsigned char* dest, int width, int height, int stride);
void pure3d::Image8::vfunc_12(Image8* source, int x, int y, int w, int h, int dx, int dy) {
    if (dx < 0) { x += dx; w -= dx; dx = 0; }
    if (dy < 0) { y += dy; h -= dy; dy = 0; }
    int stride = width;
    if (dx + w > stride) w = stride - dx;
    if (dy + h > height) h = height - dy;
    if (w < 1 || h < 1 || !source->pixels || !pixels) return;
    unsigned char* dest = pixels + stride * dy + dx;
    if (source->transparent) FUN_002c02b0(source, y, dest, x, w, h, stride, source->key);
    else FUN_002c0240(source, y, x, dest, w, h, stride);
}
