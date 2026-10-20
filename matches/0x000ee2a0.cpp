// ImageSelector::vfunc_3 @ 0x000ee2a0
// ImageSelector::vfunc_3 @ 0x000ee2a0: recompute cell size and origin from the owner's reported extent
struct Vec3_ee2a0 {
    float x, y, z;
};

class FEControl_ee2a0;

class Owner_ee2a0 {
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
    virtual void GetExtent(Vec3_ee2a0 *out, FEControl_ee2a0 *who);
};

class FEControl_ee2a0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad04[0x14 - 4];
    Owner_ee2a0 *owner;
};

class ImageSelector : public FEControl_ee2a0 {
public:
    virtual void vfunc_3();
    char pad18[0x78 - 0x18];
    float originX;
    float originY;
    char pad80[0x294 - 0x80];
    int rows;
    int columns;
    float cellW;
    float cellH;
};

void ImageSelector::vfunc_3()
{
    Vec3_ee2a0 s;
    FEControl_ee2a0::vfunc_3();
    owner->GetExtent(&s, this);
    cellW = s.x / columns;
    owner->GetExtent(&s, this);
    cellH = s.y / rows;
    owner->GetExtent(&s, this);
    originX = cellW * 0.5f - s.x * 0.5f;
    owner->GetExtent(&s, this);
    originY = s.y * 0.5f - cellH * 0.5f;
}
