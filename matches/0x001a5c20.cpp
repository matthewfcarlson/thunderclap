// Same code shape as 0x0012bc00 (propagated; names are from that function)
extern char threat_vftable_1a5c20;
struct Obj_1a5c20 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_1a5c20*);
class Event_PropNameCondition_1a5c20 {
  public:
    void* vftable;
    char pad[0x0c];
    Event_PropNameCondition_1a5c20* vfunc_5(unsigned char);
};
Event_PropNameCondition_1a5c20* Event_PropNameCondition_1a5c20::vfunc_5(unsigned char param) {
    Event_PropNameCondition_1a5c20* p = this;
    *(char**)p = &threat_vftable_1a5c20;
    ((Obj_1a5c20*)((char*)p + 0x10))->f1();
    ((Obj_1a5c20*)p)->f2();
    if (param & 1)
        thunk_FUN_00267090((Obj_1a5c20*)p);
    return p;
}