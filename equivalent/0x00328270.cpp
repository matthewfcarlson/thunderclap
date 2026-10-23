// STATUS: equivalent (tools/equiv.py level 3: 4328 inputs, branch coverage 30/30)
// FUN_00328270 @ 0x00328270
#include "decls/data/platform/xbox/pure3d.h"
#include "compat/ptr.h"

struct Vertex_328270 {
    float x;
    float y;
    int color;
};
struct Batch_328270 {
    char pad_00[8];
    Vertex_328270* vertex;
    char pad_0c[4];
    int* extra;
    void FUN_0008ef00();
};
struct GlyphInfo {
    short offset;
    unsigned char numPoints;
    unsigned char numVerts;
};
class Renderer_328270 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual Batch_328270* v30(int a, int b, int c, int count, int d);
    virtual void v31(Batch_328270* batch);
};
class TextDrawer {
  public:
    Renderer_328270* renderer;
    void FUN_00328270(const char* text, int x, int y, int color, int extra);
};

void TextDrawer::FUN_00328270(const char* text, int px, int py, int color, int extra) {
    float t0 = DAT_004d4cd4 * 10.0f;
    float lineAdvance = DAT_004d4cd4 * 5.0f + t0;
    float halfX = DAT_004d4cd0 * 0.5f;
    float halfY = DAT_004d4cd4 * 0.5f;
    hulk_freg x = (float)px; // the tab path keeps the exact integer in the register, the glyph path stores a float
    float xStart = x;
    float y = (float)py * DAT_004d4cd4 + t0;
    int count = 0;
    for (const char* s = text; *s != 0; ++s) {
        unsigned char c = (unsigned char)*s;
        if (c >= 0x20 && c <= 0x7f)
            count += ((GlyphInfo*)&DAT_004d4ad0)[c].numVerts;
    }
    Batch_328270* batch = 0;
    if (count != 0)
        batch = renderer->v30(0, 2, 0x2020, count, 0);
    for (const char* p = text; *p != 0; ++p) {
        unsigned char c = (unsigned char)*p;
        if (c == '\n') {
            x = xStart;
            y = y + lineAdvance;
        } else if (c == '\t') {
            x = ((int)(__int64)x / 40 + 1) * 40; // _ftol: low word of the 64-bit conversion; not rounded to float
        } else if (c >= 0x20 && c <= 0x7f) {
            const GlyphInfo& info = ((GlyphInfo*)&DAT_004d4ad0)[c];
            signed char* g = &((signed char*)&DAT_004d4120)[info.offset * 2];
            int width = g[0];
            if (width < 0)
                width = -width;
            // baseX adds the unrounded sum; the stored (rounded) advance is read back later
            hulk_freg advanceReg = (float)width * halfX + 0.5f;
            float advance = (float)advanceReg;
            float baseX = x + advanceReg;
            for (int i = 1; i < (int)info.numPoints - 1; ++i) {
                if ((unsigned char)g[i * 2 + 2] == 0xce) {
                    ++i;
                } else {
                    for (int k = 0; k < 2; ++k) {
                        Vertex_328270* v = batch->vertex;
                        v->color = color;
                        v->x = (float)g[(i + k) * 2] * halfX + baseX;
                        v->y = (float)g[(i + k) * 2 + 1] * halfY + y;
                        *batch->extra = extra;
                        batch->FUN_0008ef00();
                    }
                }
            }
            x = baseX + advance; // stays unrounded in the x87 register until the next glyph's baseX store
        }
    }
    if (count != 0)
        renderer->v31(batch);
}
