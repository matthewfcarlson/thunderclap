// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_000f7fe0 @ 0x000f7fe0
struct Inner {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual void GetValue(int* out);
};
struct Owner { char pad[0x24]; Inner* inner; };
struct Slot { float weight; int a; int b; int value; };
extern float DAT_004a1734;
struct Blender {
    Owner* owner; int current; Slot slots[8]; int index; float scale;
    Blender* FUN_000f7fe0(Owner* o);
};
Blender* Blender::FUN_000f7fe0(Owner* o) {
    int v;
    index = 0;
    owner = o;
    slots[index].weight = 1.0f;
    slots[index].a = 0;
    slots[index].b = 1;
    int i = index;
    if (owner->inner) owner->inner->GetValue(&v); else v = -1;
    slots[i].value = v;
    current = v;
    scale = DAT_004a1734;
    return this;
}
