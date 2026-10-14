class O_23ea50 {
  public:
    char pad[32];
    void* Target();
};

void* O_23ea50::Target() {
    return (char*)this + 32;
}
