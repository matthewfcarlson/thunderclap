// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000f1ab0 @ 0x000f1ab0
class Part_f1ab0 {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual float GetLength();
};

struct Anim_f1ab0 {
    char pad0[0x24];
    Part_f1ab0** begin;   // 0x24
    Part_f1ab0** end;     // 0x28
};

namespace pure3d {
class Entity {
public:
    virtual void AddRef();
};
class CompositeDrawable : public Entity {
public:
    char pad04[0x44];
    Anim_f1ab0* anim;               // 0x48
    void FUN_002998d0(int a);
};
}

class Source_f1ab0 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual pure3d::Entity* GetEntity();
};

class Player_f1ab0 {
public:
    char pad0[0x190];
    pure3d::CompositeDrawable* drawable;
    char pad194[0x1f4 - 0x194];
    float duration;
    void FUN_000e9e60();
    void FUN_000f1ab0(Source_f1ab0* src);
};

void Player_f1ab0::FUN_000f1ab0(Source_f1ab0* src) {
    // WRONG: a reference cast (isReference = 1, throws instead of returning 0) for the original's pointer cast
    drawable = &dynamic_cast<pure3d::CompositeDrawable&>(*src->GetEntity());
    if (!drawable)
        return;
    drawable->AddRef();
    drawable->FUN_002998d0(0);
    Anim_f1ab0* a = drawable->anim;
    if ((unsigned char)(a->end - a->begin) == 0)
        return;
    Part_f1ab0* first = a->begin[0];
    if (first)
        duration = first->GetLength() - 1.0f;
    FUN_000e9e60();
}
