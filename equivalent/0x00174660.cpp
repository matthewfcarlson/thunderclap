// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00174660 @ 0x00174660
struct Ref { virtual void retain(); virtual void release(); };
struct Action_174660 { virtual void slot0(); void FUN_00232660(); };
extern void *DAT_00417e30[];
struct JointRelativeAction : Action_174660 {
    char gap[0x18];
    unsigned int joint;
    Ref *reference;
    unsigned int field24;
    char gap28[0x38];
    unsigned int field60;
    JointRelativeAction * FUN_00174660(unsigned int value, Ref *ref);
};
JointRelativeAction * JointRelativeAction::FUN_00174660(unsigned int value, Ref *ref) {
    FUN_00232660();
    *(void ***)this = DAT_00417e30;
    joint = value;
    reference = 0;
    field24 = 0;
    field60 = 0;
    if (ref) ref->retain();
    if (reference) reference->release();
    reference = ref;
    return this;
}