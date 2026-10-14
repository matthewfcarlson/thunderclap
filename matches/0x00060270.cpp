class Obj_60270 {
  public:
    char pad[0x40];
    char* Get() throw();
};
char* Obj_60270::Get() throw() {
    return pad + 0x40;
}