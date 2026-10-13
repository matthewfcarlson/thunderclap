class Obj {
  public:
    char pad[0x40];
    char* Get() throw();
};
char* Obj::Get() throw() {
    return pad + 0x40;
}