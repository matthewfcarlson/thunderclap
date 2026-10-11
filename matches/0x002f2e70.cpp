extern "C" char DAT_004313cc[];
struct Part {
    void Init();
};
struct Base {
    void Finish();
};
struct Obj {
    void* vptr;
    char pad[0x60];
    void Target();
};
void Obj::Target() {
    vptr = (void*)((int)DAT_004313cc);
    ((Part*)((char*)this + 0x64))->Init();
    ((Part*)((char*)this + 0x38))->Init();
    ((Base*)this)->Finish();
}