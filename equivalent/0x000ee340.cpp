// STATUS: equivalent (tools/equiv.py level 3: 466 inputs, branch coverage 28/28)
// ImageSelector::vfunc_5 @ 0x000ee340
// ImageSelector::vfunc_5: draw the image grid, selection highlight and captions.
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "gen/global.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"

void* thunk_FUN_0008d690(unsigned int size);

struct Vec3_ee340 {
    float x;
    float y;
    float z;
};
struct OffsetFrame_ee340 {
    Vec3_ee340 translation;
    unsigned row;
};
struct Dev1 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void v15(unsigned a);
    virtual void v16(unsigned a);
};
struct Ctx_ee340 {
    Dev1* dev;
    void FUN_00293d00(unsigned a);
    void FUN_00293da0(unsigned a, unsigned b, unsigned c);
};
struct Gfx {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual unsigned v30(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e);
    virtual void v31(unsigned a);
};
struct Obj14_ee340 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void v14(unsigned out, unsigned who);
    virtual void v15(unsigned out, unsigned who);
    virtual float v16(unsigned who);
    virtual float v17(unsigned who);
    virtual void s18();
    virtual void s19();
    virtual unsigned v20();
};
struct Objr {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual unsigned v51();
};
struct Objs_ee340 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual unsigned v44();
};
struct Obj50_ee340 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void v8(unsigned a, unsigned b);
};
struct Obj10_ee340 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void v5(unsigned a, unsigned b);
    virtual void v6(unsigned a, unsigned b);
};
struct NewObj_ee340 {
    virtual void v0();
    virtual void v1();
    char padding[12];
    Obj10_ee340* content;
};
struct Fmt {
    Fmt* FUN_0028edb0();
};
struct Z {
    char padding[8];
    Vec3_ee340* position;
    char padding2[4];
    unsigned* color;
    float* uv;
    void FUN_0008ef00();
};
struct Fmt7 {
    void FUN_000f7fe0(unsigned a);
};
struct Fmt8 {
    void FUN_000f80e0(unsigned a, unsigned b, unsigned c);
};
struct Fmt9 {
    void FUN_000f78e0();
};

struct CaptionEntry_ee340 {
    float scale;
    unsigned enabled;
    unsigned kind;
    unsigned reserved;
};
struct Caption_ee340 {
    char header[8];
    CaptionEntry_ee340 entries[8];
    unsigned selectedEntry;
    char tail[4];
};
struct SelectorView_ee340 {
    char beforeOwner[0x14];
    Obj14_ee340* owner;
    char beforeFlags[0x28];
    unsigned char drawFirst;
    char beforeSecond[7];
    unsigned char drawSecond;
    char afterSecond[3];
    unsigned secondImage;
    Obj50_ee340* overlay;
    unsigned transformA;
    unsigned transformB;
    unsigned transformC;
    char beforeVisibility[0x14];
    unsigned char visible;
    char beforePosition[3];
    Vec3_ee340 position;
    char beforeFirstImage[0xc4];
    unsigned firstImage;
    char beforeCells[4];
    unsigned cells[64];
    unsigned char captions[64];
    char beforeDimensions[4];
    int rows;
    int columns;
    float cellWidth;
    float cellHeight;
    char beforeSelection[4];
    unsigned selectedCell;
};

extern int DAT_00584554;
void FUN_000e11a0(float x, float y, float z, unsigned image, int mode);
void FUN_000e0cc0(float x, float y, float z, unsigned image, int mode);
// equiv-conv: FUN_000e0a90 edx stack stack stack stack stack
void FUN_000e0a90(unsigned a_edx, float x, float y, float z, float w, unsigned color);

void ImageSelector::vfunc_5() {
    SelectorView_ee340* selector = (SelectorView_ee340*)this;
    OffsetFrame_ee340 frame;
    Vec3_ee340 imagePosition;
    Vec3_ee340 step;
    Caption_ee340 caption;

    if (!selector->visible)
        return;

    if (selector->drawFirst == 1) {
        (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v15(0);
        selector->owner->v14((unsigned)&frame.translation, (unsigned)this);
        (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((unsigned)&frame.translation);
        selector->owner->v15((unsigned)&imagePosition, (unsigned)this);
        unsigned image = selector->firstImage;
        FUN_000e11a0(imagePosition.x, imagePosition.y, imagePosition.z, image, 2);
        (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v16(0);
    }

    if (selector->drawSecond == 1) {
        (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v15(0);
        selector->owner->v14((unsigned)&frame.translation, (unsigned)this);
        (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((unsigned)&frame.translation);
        selector->owner->v15((unsigned)&imagePosition, (unsigned)this);
        unsigned image = selector->secondImage;
        FUN_000e0cc0(imagePosition.x, imagePosition.y, imagePosition.z, image, 0);
        (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v16(0);
    }

    if (selector->overlay) {
        (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v15(0);
        selector->owner->v14((unsigned)&frame.translation, (unsigned)this);
        (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((unsigned)&frame.translation);
        (*(Ctx_ee340**)&DAT_0052c2ac)
            ->FUN_00293da0(selector->transformA, selector->transformB, selector->transformC);
        selector->overlay->v8(0, 0);
        (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v16(0);
    }

    (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v15(0);
    selector->owner->v14((unsigned)&frame.translation, (unsigned)this);
    (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((unsigned)&frame.translation);
    (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((unsigned)&selector->position);

    if (selector->rows > 0) {
        frame.row = 0;
        unsigned char* captionRow = selector->captions;
        unsigned* cellRow = selector->cells;
        do {
            (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v15(0);
            unsigned column = 0;
            unsigned* cell = cellRow;
            if (selector->columns > 0) {
                do {
                    if (*cell) {
                        void* memory = thunk_FUN_0008d690(0x20);
                        NewObj_ee340* formatted = memory ? (NewObj_ee340*)((Fmt*)memory)->FUN_0028edb0() : 0;
                        formatted->v0();
                        formatted->content->v6(0x444d4c42, 1);
                        unsigned currentCell = *cell;
                        unsigned label = currentCell ? *(unsigned*)(currentCell + 0x10) : 0;
                        formatted->content->v5((unsigned)&DAT_00584554, label);

                        unsigned texture = (unsigned)formatted->content;
                        volatile float width = selector->cellWidth * 0.8f;
                        volatile float height = selector->cellHeight * 0.8f;
                        volatile float left = width * -0.5f;
                        volatile float right = width * 0.5f;
                        volatile float top = height * 0.5f;
                        volatile float bottom = height * -0.5f;
                        unsigned vertexData = DAT_0052c2a8->v30(texture, 0, 0x2021, 6, 0);
                        if (vertexData) {
                            Z* vertices = (Z*)vertexData;
                            for (int vertex = 0; vertex < 6; ++vertex) {
                                int corner = vertex == 0 || vertex == 3 ? 0
                                             : vertex == 1              ? 1
                                             : vertex == 5              ? 3
                                                                        : 2;
                                float x = corner == 0 || corner == 1 ? left : right;
                                float y = corner == 0 || corner == 3 ? bottom : top;
                                float u = corner == 0 || corner == 1 ? 0.0f : 1.0f;
                                float v = corner == 0 || corner == 3 ? 0.0f : 1.0f;
                                Vec3_ee340* position = vertices->position;
                                position->x = x;
                                position->y = y;
                                position->z = 0.0f;
                                *vertices->color = 0xffffffff;
                                float* uv = vertices->uv;
                                uv[0] = u;
                                uv[1] = v;
                                vertices->FUN_0008ef00();
                            }
                        }
                        DAT_0052c2a8->v31(vertexData);
                        formatted->v1();

                        if (selector->selectedCell == selector->columns * frame.row + column) {
                            FUN_000e0a90(1, selector->cellWidth * 0.8f, selector->cellHeight * 0.8f, 1.0f,
                                         0.02f, 0xff51c4ff);
                        }
                        if (captionRow[column]) {
                            unsigned text = selector->owner->v20();
                            text = ((Objr*)text)->v51();
                            text = ((Objs_ee340*)text)->v44();
                            ((Fmt7*)&caption)->FUN_000f7fe0(text);
                            volatile float verticalScale = selector->owner->v17((unsigned)this);
                            float horizontalScale = selector->owner->v16((unsigned)this);
                            caption.entries[caption.selectedEntry].scale = horizontalScale * verticalScale;
                            caption.entries[caption.selectedEntry].enabled = 1;
                            caption.entries[caption.selectedEntry].kind = 2;
                            ((Fmt8*)&caption)->FUN_000f80e0((unsigned)&DAT_0040b0a0, 0, 0);
                            ((Fmt9*)&caption)->FUN_000f78e0();
                        }
                    }
                    step.x = selector->cellWidth;
                    step.y = 0.0f;
                    step.z = 0.0f;
                    (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((unsigned)&step);
                    ++column;
                    ++cell;
                } while ((int)column < selector->columns);
            }
            (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v16(0);
            frame.translation.x = 0.0f;
            frame.translation.y = -selector->cellHeight;
            frame.translation.z = 0.0f;
            (*(Ctx_ee340**)&DAT_0052c2ac)->FUN_00293d00((unsigned)&frame.translation);
            ++frame.row;
            cellRow += 8;
            captionRow += 8;
        } while ((int)frame.row < selector->rows);
    }
    (*(Ctx_ee340**)&DAT_0052c2ac)->dev->v16(0);
}
