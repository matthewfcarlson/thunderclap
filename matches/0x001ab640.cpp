// Same code shape as 0x0012bc00 (propagated; names are from that function)
extern char threat_vftable_1ab640;
struct Obj_1ab640 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_1ab640*);
class Event_TriggerVolumeNameCondition_1ab640 {
  public:
    void* vftable;
    char pad[0x0c];
    Event_TriggerVolumeNameCondition_1ab640* vfunc_5(unsigned char);
};
Event_TriggerVolumeNameCondition_1ab640* Event_TriggerVolumeNameCondition_1ab640::vfunc_5(unsigned char param) {
    Event_TriggerVolumeNameCondition_1ab640* p = this;
    *(char**)p = &threat_vftable_1ab640;
    ((Obj_1ab640*)((char*)p + 0x10))->f1();
    ((Obj_1ab640*)p)->f2();
    if (param & 1)
        thunk_FUN_00267090((Obj_1ab640*)p);
    return p;
}