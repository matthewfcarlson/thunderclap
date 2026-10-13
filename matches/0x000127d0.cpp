class X {
  public:
    char pad[0xc8];
    char* Get(void);
};
char* X::Get(void) {
    return (char*)((char*)this + 0xc8);
}
