class Obj_481e0 {
  public:
    char pad[12];
    void* mP;
    int mFlag;
    char Set(void* p);
};
char Obj_481e0::Set(void* p) {
    mP = p;
    return 1;
}
