class IRefCount {
  public:
    virtual void f0();
    virtual void Release() throw();
};
class ChannelLoader {
  public:
    int vf;
    int pad;
    int count;
    IRefCount* items[1];
    void cleanup() throw();
};
void ChannelLoader::cleanup() throw() {
    vf = 0x42c95c;
    for (int i = 0; i < count; ++i) {
        if (items[i]) {
            items[i]->Release();
            items[i] = 0;
        }
    }
    vf = 0x3f6098;
}
