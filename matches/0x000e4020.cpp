class D {
  public:
    void Cleanup(int);
};
class ImageSelector_e4020 {
  public:
    virtual void V();
    char pad[0x2a4];
    int a;
    D* b;
    void Run();
};
void ImageSelector_e4020::Run() {
    if (b)
        b->Cleanup(a);
    V();
}