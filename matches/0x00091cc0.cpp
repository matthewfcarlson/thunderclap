extern "C" char DAT_0040449c[];
extern "C" char DAT_004044a4[];
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
    *(int*)this = ((int)DAT_004044a4);
    ((Helper*)((char*)this + 0x20))->Run();
    *(int*)this = ((int)DAT_0040449c);
    int p = *(int*)((char*)this + 0x18);
    if (p) {
        thunk_FUN_00267090(p);
        *(int*)((char*)this + 0x18) = 0;
    }
    ((Helper*)((char*)this + 0x10))->Run();
}