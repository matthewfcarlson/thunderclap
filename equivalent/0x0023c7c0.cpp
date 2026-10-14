// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 12/12)
// fight::Bank::vfunc_9 @ 0x0023c7c0
typedef unsigned __int64 Key;
extern unsigned long DAT_004e5b30, DAT_004e5b34, DAT_004e5b20, DAT_004e5b24;
struct Object {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
    virtual bool slot13(); virtual Key slot14(); virtual void slot15(); virtual void slot16(unsigned long low, unsigned long high); virtual void slot17();
};
struct Context { char pad[0x28]; unsigned long value; };
struct Links { void FUN_00236ec0(); void FUN_00237160(unsigned long low, unsigned long high, unsigned long value, Object *obj); };
namespace fight {
struct Bank {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual bool vfunc_9(Context *, Object *, unsigned long);
    char pad[0x14]; Links links;
    void FUN_00233c50(Context *, Object *, unsigned long);
    void FUN_002337c0(Context *, Object *, int);
};
bool Bank::vfunc_9(Context *context, Object *object, unsigned long arg)
{
    if (!object->slot13()) return false;
    Key key = object->slot14();
    if ((unsigned long)key != DAT_004e5b30 || (unsigned long)(key >> 32) != DAT_004e5b34) return false;
    object->slot16(DAT_004e5b30, DAT_004e5b34);
    FUN_00233c50(context, object, arg);
    links.FUN_00236ec0();
    if (object->slot13()) {
        key = object->slot14();
        if ((unsigned long)key == DAT_004e5b20 && (unsigned long)(key >> 32) == DAT_004e5b24)
            links.FUN_00237160(DAT_004e5b20, DAT_004e5b24, context->value, object);
    }
    FUN_002337c0(context, object, -1);
    object->slot17();
    return true;
}
}
