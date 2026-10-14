extern "C" char DAT_0040449c[];
extern "C" char DAT_004044cc[];
void ReleaseThing(void*);
class Sub_92270 {
  public:
    void Fin();
};
class CUnlockableGallery {
  public:
    void destroy();
    char pad[0x10];
    Sub_92270 sub10;
    char pad2[0x7];
    void* m18;
};
void CUnlockableGallery::destroy() {
    *(void**)this = (void*)((int)DAT_004044cc);
    ((Sub_92270*)((char*)this + 0xa8))->Fin();
    *(void**)this = (void*)((int)DAT_0040449c);
    if (m18) {
        ReleaseThing(m18);
        m18 = 0;
    }
    sub10.Fin();
}
