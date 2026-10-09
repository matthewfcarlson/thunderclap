void ReleaseThing(void*);
class Sub {
  public:
    void Fin();
};
class CUnlockableGallery {
  public:
    void destroy();
    char pad[0x10];
    Sub sub10;
    char pad2[0x7];
    void* m18;
};
void CUnlockableGallery::destroy() {
    *(void**)this = (void*)0x4044cc;
    ((Sub*)((char*)this + 0xa8))->Fin();
    *(void**)this = (void*)0x40449c;
    if (m18) {
        ReleaseThing(m18);
        m18 = 0;
    }
    sub10.Fin();
}
