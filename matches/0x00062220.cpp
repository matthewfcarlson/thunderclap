struct Helper { void Run(); };
struct CSmartPropAttachTrack {
    void* vf;
    char pad[0x58-4];
    void Construct();
};
struct Finalizer { void Run(); };
void CSmartPropAttachTrack::Construct() {
    vf=(void*)0x3faf60;
    ((Helper*)((char*)this+0x58))->Run();
    ((Helper*)((char*)this+0x20))->Run();
    ((Helper*)((char*)this+0x18))->Run();
    ((Finalizer*)this)->Run();
}