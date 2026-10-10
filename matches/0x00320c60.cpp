struct Matrix {
    float m[16];
};
namespace D3D8 {
void __stdcall D3DDevice_SetTransform(int, const Matrix*);
void __fastcall D3DDevice_SetRenderState_Simple(unsigned long, unsigned long);
void __stdcall D3DDevice_SetRenderState_TextureFactor(unsigned long);
} // namespace D3D8
extern void __fastcall FUN_0022b980(Matrix*);
extern unsigned int DAT_0039db08;
extern int DAT_0039de14;
extern int DAT_0039deb4;
extern int DAT_0039deb8;
extern int DAT_0039debc;
extern int DAT_0039dec0;
extern int DAT_0039dec4;
extern int DAT_0039dec8;
extern int DAT_0039decc;
extern int DAT_0039ded0;
extern int DAT_0039ded4;
void FUN_00320c60() {
    Matrix identity;
    FUN_0022b980(&identity);
    D3D8::D3DDevice_SetTransform(0, &identity);
    D3D8::D3DDevice_SetTransform(6, &identity);
    D3D8::D3DDevice_SetTransform(1, &identity);
    D3D8::D3DDevice_SetRenderState_Simple(0x40310, 1);
    DAT_0039de14 = 1;
    D3D8::D3DDevice_SetRenderState_TextureFactor(0xffffffff);
    unsigned int flags = DAT_0039db08 | 0x1000;
    DAT_0039decc = 0;
    DAT_0039dec8 = 0;
    DAT_0039ded0 = 0;
    DAT_0039ded4 = 0;
    DAT_0039debc = 0;
    DAT_0039deb8 = 0;
    DAT_0039dec0 = 0;
    DAT_0039dec4 = 0;
    DAT_0039deb4 = 1;
    DAT_0039db08 = flags;
}
