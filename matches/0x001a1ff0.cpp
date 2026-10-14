class O_1a1ff0 {
  public:
    char pad[0x30];
    char* Get() throw();
};
char* O_1a1ff0::Get() throw() {
    return (char*)((char*)this + 0x30);
}
