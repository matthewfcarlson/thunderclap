class T_15a890 {
  public:
    char Set(void* p);
    char pad[0x10];
    void* m;
};

char T_15a890::Set(void* p) {
    m = p;
    return 1;
}
