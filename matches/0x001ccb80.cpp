class C {
  public:
    char pad[0x1190];
    void Init();
};
void C::Init() {
    char* p = (char*)this + 0x214;
    int i = 0x10;
    do {
        *(int*)(p - 0x104) = (int)0xbf800000;
        *(char*)(p - 0x100) = 0;
        *(int*)p = -1;
        p += 0x108;
        --i;
    } while (i != 0);
    *(int*)((char*)this + 0x1190) = 0;
}