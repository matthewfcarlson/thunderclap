class C_68680 {
  public:
    char Get(int a);
};

char C_68680::Get(int a) {
    *(int*)((char*)this + 0x64) = a;
    return 1;
}
