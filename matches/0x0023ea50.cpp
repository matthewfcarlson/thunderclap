class O {
  public:
    char pad[32];
    void* Target();
};

void* O::Target() {
    return (char*)this + 32;
}
