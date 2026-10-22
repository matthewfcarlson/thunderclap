// STATUS: equivalent (tools/equiv.py level 3: 15363 inputs, branch coverage 24/24)
// FUN_002be440 @ 0x002be440
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "decls/address.h"
#include "decls/data/engine/pure3d.h"
extern "C" double sqrt(double);
inline void *operator new(unsigned int, void *p) throw() { return p; }

struct Tile_2be440 {
    virtual void t0(); virtual void t1(); virtual void t2(); virtual void t3();
    virtual void t4();
    virtual int v5();
    virtual int v6();
};

class Mode_2be440 {
public:
    virtual void m0();
    virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5();
    virtual void m6(int tag, int flag);
};

struct Shader_2be440 {
    virtual void h0();
    char pad04[0xc];
    Mode_2be440 *mode;             // 0x10
    Shader_2be440 *FUN_0028edb0();
};

struct Gfx {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79(); virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual int v84();
};

struct Item_2be440 {
    char pad0[0x10];
    Tile_2be440 *tile;             // 0x10
};

extern void *thunk_FUN_0008d690(unsigned int size);
extern void *__cdecl FUN_0008d6d0(unsigned int size);

namespace pure3d {

struct Rect_2be440 {
    int x0, y0, x1, y1, extra;
};

class __declspec(novtable) SpriteBase_2be440 {
public:
    virtual void b0();
    char pad04[0x3c];
    void FUN_002a5060();
    SpriteBase_2be440() { FUN_002a5060(); }
};

class Sprite : public SpriteBase_2be440 {
public:
    Sprite(Item_2be440 **items, int w, int h, int count, Shader_2be440 *mgr, int margin, int a7, int a8, int a9);
    virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5();
    virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10();
    virtual void a11(); virtual void a12();
    int count;              // 0x40
    void *buf;              // 0x44
    Item_2be440 **items;           // 0x48
    Shader_2be440 *holder;         // 0x4c
    char pad50[4];
    int h;                  // 0x54
    int w;                  // 0x58
    int margin;             // 0x5c
    int f60, f64, f68, f6c;
    float f70, f74;
    int f78, f7c, f80;
    float f84, f88;
    int f8c;
    float f90, f94;
    int f98;
    float f9c;
    char fa0;
    void FUN_002bdaf0(int index, Rect_2be440 *r, int w, int h);
    void FUN_002bdd00(int v);
};

}

pure3d::Sprite::Sprite(Item_2be440 **items_, int w_, int h_, int count_, Shader_2be440 *mgr, int margin_, int a7, int a8, int a9)
{
    fa0 = 0;
    DAT_004d0898 = 0x20;
    int m = margin_;
    if (!(margin_ >= 0))
        m = margin;
    margin = m;
    int span = m * 2;
    int dispv = DAT_0052c2a8->v84();
    double r = 1.0f / (double)a7;
    f68 = dispv - span;
    f6c = DAT_004d0898 - span;
    f60 = a7;
    f64 = a8;
    f8c = 0;
    f80 = 0;
    f7c = 0;
    f78 = 0;
    f70 = (float)r;
    f74 = (float)r;
    double t = (double)w_ * r;
    volatile float tf = (float)t; // rounded frame copy (the original reuses it for f90 and f9c)
    f84 = tf;
    double u = r * h_;
    f88 = (float)u;
    f98 = 0;
    f94 = (float)(u * 0.5f);
    f90 = tf * 0.5f;
    f9c = (float)sqrt(*(volatile float *)&f84 * *(volatile float *)&f84 + *(volatile float *)&f88 * *(volatile float *)&f88);
    Shader_2be440 *mm;
    if (mgr == 0) {
        void *mem = thunk_FUN_0008d690(0x20);
        if (mem != 0)
            mm = ((Shader_2be440 *)mem)->FUN_0028edb0();
        else
            mm = 0;
    } else {
        mm = mgr;
    }
    holder = mm;
    mm->h0();
    if (mgr == 0) {
        holder->mode->m6(0x54494c, 0);
        holder->mode->m6(0x444d4c42, 1);
        holder->mode->m6(0x444d5655, 1);
    }
    h = h_;
    w = w_;
    items = items_;
    buf = FUN_0008d6d0(count_ * 0x60);
    count = count_;
    if (items[0]->tile->v6() == h_ && items[0]->tile->v5() == w_)
        margin = 0;
    int x = -margin;
    int hh = 0;
    int idx = 0;
    if (x < h_ - 1) {
        do {
            int pos = -margin;
            if (pos < w_ - 1) {
                do {
                    int ww = items[idx]->tile->v5();
                    hh = items[idx]->tile->v6();
                    int a = margin + x;
                    int b = margin + pos;
                    int p;
                    if (items[idx]->tile->v5() > w_)
                        p = w_;
                    else
                        p = ww - margin * 2;
                    int q;
                    if (items[idx]->tile->v6() > h_)
                        q = h_;
                    else
                        q = hh - margin * 2;
                    Rect_2be440 rc;
                    rc.x0 = a;
                    rc.y0 = b;
                    rc.x1 = q + a;
                    rc.y1 = p + b;
                    rc.extra = q;
                    FUN_002bdaf0(idx, &rc, ww, hh);
                    pos += ww - margin * 2;
                    idx++;
                } while (pos < w_ - 1);
            }
            x += hh - margin * 2;
        } while (x < h_ - 1);
    }
    FUN_002bdd00(-1);
}
