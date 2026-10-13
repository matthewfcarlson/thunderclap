class O {
  public:
    char pad[0x30];
    char* Get() throw();
};
char* O::Get() throw() {
    return (char*)((char*)this + 0x30);
}
