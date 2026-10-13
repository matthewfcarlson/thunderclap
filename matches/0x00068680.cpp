class C {
  public:
    char Get(int a);
};

char C::Get(int a) {
    *(int*)((char*)this + 0x64) = a;
    return 1;
}
