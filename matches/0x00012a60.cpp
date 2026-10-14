class Obj_12a60 {
  public:
    char pad[0x40];
    char* Get() throw();
};

char* Obj_12a60::Get() throw() {
    return (char*)pad + 0x40;
}
