// STATUS: equivalent (tools/equiv.py level 3: 764 inputs, branch coverage 22/22)
// TextTable::vfunc_3 @ 0x000ed990
struct Vec3_ed990 {
    float x, y, z;
};

union Word_ed990 {
    float f;
    int i;
    unsigned int u;
};

struct BCell_ed990 {
    Word_ed990 a, b, c, d;
};

struct Source_ed990;

struct Builder {
    unsigned int hdr[2];
    BCell_ed990 cells[8];
    int cursor;
    float scale;
    void FUN_000f7fe0(Source_ed990 *src);
    void FUN_000f78e0();
    void FUN_000f87f0(void *a, void *b);
    float FUN_000f8840(void *cell);
};

class Source_ed990 {
public:
    virtual void v0();
};

class Level2_ed990 {
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual Source_ed990* v44();
};

struct Level1_ed990 {
    char pad0[4];
    Level2_ed990 *level2;
};

class TextTable;

class Owner_ed990 {
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
    virtual char v13(TextTable *obj);
    virtual void v14(Vec3_ed990 *out, TextTable *obj);
    virtual void v15(Vec3_ed990 *out, TextTable *obj);
    virtual float v16(TextTable *obj);
    virtual float v17(TextTable *obj);
    char pad04[4];
    Level1_ed990 *p8;
};


struct Cell_ed990 {
    char pad00[0x24];
};

class FEControl_ed990 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void vfunc_3();
};

class TextTable : public FEControl_ed990 {
public:
    virtual void vfunc_3();
    char pad04[0x10];
    Owner_ed990 *owner;
    char pad18[0x7c - 0x18];
    float f7c;
    char pad80[0x15c - 0x80];
    Cell_ed990 cells[64][8];
    int rowCount;
    int colCount;
    int rowFirst;
    int rowLast;
    float spacing;
};

void TextTable::vfunc_3()
{
    FEControl_ed990::vfunc_3();

    Builder x;
    x.FUN_000f7fe0(owner->p8->level2->v44());
    float t = owner->v17(this);
    x.cells[x.cursor].a.f = owner->v16(this) * t;

    int lastRow = 0;
    if (rowCount > 0) {
        Cell_ed990 *row = &cells[0][0];
        float used = 0.0f;
        int i = 0;
        do {
            float widest = 0.0f;
            Cell_ed990 *c = row;
            for (int j = 0; j < colCount; j++) {
                float w = x.FUN_000f8840(c);
                if (w > widest)
                    widest = w;
                c++;
            }
            float next = widest + used + spacing;
            Vec3_ed990 size;
            owner->v15(&size, this);
            if (next >= size.y) {
                lastRow = i;
                break;
            }
            used = next;
            i++;
            row += 8;
        } while (i < rowCount);
    }

    rowFirst = 0;
    rowLast = rowCount;
    if (rowCount > lastRow)
        rowLast = lastRow - 1;

    if (rowCount > 0) {
        float widest = 0.0f;
        for (int j = 0; j < colCount; j++) {
            float w = x.FUN_000f8840(&cells[rowFirst][j]);
            if (w > widest)
                widest = w;
        }
        Vec3_ed990 size;
        owner->v15(&size, this);
        f7c = size.y * 0.5f - widest * 0.5f;
    }
    x.FUN_000f78e0();
}
