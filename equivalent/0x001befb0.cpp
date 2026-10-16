// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// CSubtitleOverlay::vfunc_4 @ 0x001befb0
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"

struct DrawEntry { float size; int a; int b; unsigned color; };
struct TextBuilder { char prefix[8]; DrawEntry entries[8]; int count; float scale; void FUN_000f7fe0(void*); void FUN_000f81b0(void*, int, void*); void FUN_000f78e0(); };
struct RenderDevice_1befb0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(int); virtual void s16(int); };
struct RenderContext { RenderDevice_1befb0* device; void FUN_00293d00(void*); };
 
struct Overlay { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); };
struct CSubtitleOverlay : Overlay { int unk4; void* text; int unkC; float visibility; unsigned alpha; int unk18; char textData[0x104]; char position[4]; void FUN_001be260(); virtual void vfunc_4(); };
void CSubtitleOverlay::vfunc_4() {
 union {float f; unsigned u;} v; v.f=visibility; v.u &= 0x7fffffff;
 if (v.f <= 1e-05f) return;
 if (!text) return;
 TextBuilder builder; builder.FUN_000f7fe0(text);
 builder.entries[builder.count].size=DAT_004c4c44*DAT_004c4c40;
 builder.entries[builder.count].b=2;
 builder.entries[builder.count].a=1;
 builder.scale=(*(float*)&DAT_004c4c18);
 builder.entries[builder.count].color=(alpha<<24)|0x1ed2dc;
 FUN_001be260();
 (*(RenderContext**)&DAT_0052c2ac)->device->s15(0);
 (*(RenderContext**)&DAT_0052c2ac)->FUN_00293d00(((char*)&DAT_004e2308));
 builder.FUN_000f81b0(textData,(*(int*)&DAT_004e22f0),position);
 (*(RenderContext**)&DAT_0052c2ac)->device->s16(0);
 builder.FUN_000f78e0();
}