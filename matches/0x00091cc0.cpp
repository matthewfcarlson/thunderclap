extern "C" char DAT_0040449c[];
extern "C" char DAT_004044a4[];
class Helper_91cc0 {
  public:
    void Run();
};
extern void __cdecl thunk_FUN_00267090(int);
class CUnlockableBlonskyFile {
  public:
    void Destroy();
};
void CUnlockableBlonskyFile::Destroy() {
    *(int*)this = ((int)DAT_004044a4);
    ((Helper_91cc0*)((char*)this + 0x20))->Run();
    *(int*)this = ((int)DAT_0040449c);
    int p = *(int*)((char*)this + 0x18);
    if (p) {
        thunk_FUN_00267090(p);
        *(int*)((char*)this + 0x18) = 0;
    }
    ((Helper_91cc0*)((char*)this + 0x10))->Run();
}