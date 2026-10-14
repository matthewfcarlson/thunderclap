extern "C" char DAT_003faf60[];
struct Helper_62220 {
    void Run();
};
struct CSmartPropAttachTrack {
    void* vf;
    char pad[0x58 - 4];
    void Construct();
};
struct Finalizer {
    void Run();
};
void CSmartPropAttachTrack::Construct() {
    vf = (void*)((int)DAT_003faf60);
    ((Helper_62220*)((char*)this + 0x58))->Run();
    ((Helper_62220*)((char*)this + 0x20))->Run();
    ((Helper_62220*)((char*)this + 0x18))->Run();
    ((Finalizer*)this)->Run();
}