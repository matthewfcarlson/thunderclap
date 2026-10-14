class X_127d0 {
  public:
    char pad[0xc8];
    char* Get(void);
};
char* X_127d0::Get(void) {
    return (char*)((char*)this + 0xc8);
}
