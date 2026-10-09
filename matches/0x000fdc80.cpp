class C {
    char pad[8];
    int count;
    char pad2[0x40];
    int index;

  public:
    int Get();
};
int C::Get() {
    int i = index;
    if (i >= 0 && i < count)
        return *(int*)((char*)this + 0xc + i * 4);
    return 0;
}