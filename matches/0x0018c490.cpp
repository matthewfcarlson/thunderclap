extern "C" char DAT_004195cc[];
void* __cdecl FUN_0008d690(unsigned int);
class Track {
  public:
    void Init();
};
class Factory_18c490 {
  public:
    void* vfunc_5();
};
void* Factory_18c490::vfunc_5() {
    Track* p = (Track*)FUN_0008d690(0x14);
    if (p) {
        p->Init();
        *(int*)p = ((int)DAT_004195cc);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        *(int*)((char*)p + 8) = 1;
        return p;
    }
    return 0;
}