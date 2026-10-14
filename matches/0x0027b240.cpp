struct Obj_27b240 {
    int DoThing(Obj_27b240*, int);
};
extern Obj_27b240* __cdecl GetThing(int);
int __fastcall target(Obj_27b240* self, void*) {
    Obj_27b240* p = GetThing(0x2c);
    if (p)
        return p->DoThing(self, 0);
    return 0;
}