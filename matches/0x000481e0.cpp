class Obj {
  public:
    char pad[12];
    void* mP;
    int mFlag;
    char Set(void* p);
};
char Obj::Set(void* p) {
    mP = p;
    return 1;
}
