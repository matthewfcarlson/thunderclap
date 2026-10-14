class Target_14ceb0 {
  public:
    bool Run(void* p);
    char pad[0xc];
    void* mValue;
};

bool Target_14ceb0::Run(void* p) {
    mValue = p;
    return true;
}
