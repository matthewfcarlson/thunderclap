class Target {
  public:
    bool Run(void* p);
    char pad[0xc];
    void* mValue;
};

bool Target::Run(void* p) {
    mValue = p;
    return true;
}
