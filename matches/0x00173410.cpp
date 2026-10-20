namespace hulkfight {
namespace motion {
struct Ref {
    virtual void FUN_00000000();
    virtual void FUN_00000001();
};
struct Base {
    Base();
    virtual void FUN_00000002();
};
struct Fields {
    int value;
    Ref* ref;
    int other;
    Fields() : value(0), ref(0), other(0) {}
};
struct JointTrackerAction : Base {
    char pad[0x18];
    Fields fields;
    char pad2[0x4c];
    int last;
    JointTrackerAction(int v, Ref* r);
};
JointTrackerAction::JointTrackerAction(int v, Ref* r) : Base(), fields(), last(0) {
    fields.value = v;
    if (r)
        r->FUN_00000000();
    if (fields.ref)
        fields.ref->FUN_00000001();
    fields.ref = r;
}
} // namespace motion
} // namespace hulkfight