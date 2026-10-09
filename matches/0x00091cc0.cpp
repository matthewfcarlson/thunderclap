class Helper {
  public:
    void Run();
};
extern void __cdecl thunk_FUN_00267090(int);
class CUnlockableBlonskyFile {
  public:
    void Destroy();
};
void CUnlockableBlonskyFile::Destroy() {
    *(int*)this = 0x4044a4;
    ((Helper*)((char*)this + 0x20))->Run();
    *(int*)this = 0x40449c;
    int p = *(int*)((char*)this + 0x18);
    if (p) {
        thunk_FUN_00267090(p);
        *(int*)((char*)this + 0x18) = 0;
    }
    ((Helper*)((char*)this + 0x10))->Run();
}