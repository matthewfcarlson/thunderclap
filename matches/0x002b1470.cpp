// Same code shape as 0x002a1130 (propagated; names are from that function)
namespace pure3d {

class Entity {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x100];
};

class LightGroup : public Entity {
public:
    LightGroup* Self();
    char pad2[0x40];
};

LightGroup* LightGroup::Self() { return this; }

} // namespace pure3d
