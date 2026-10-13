class O {
  public:
    char pad[0x10];
    void* FUN_00146910();
};
void* O::FUN_00146910() {
    return (void*)((char*)this + 0x10);
}
