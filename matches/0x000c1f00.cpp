struct Sub_c1f00 {
    void Fn(int);
};
struct Obj_c1f00 {
    char pad[4];
    Sub_c1f00* mSub;
    int Run(int flag, int* p);
};
int Obj_c1f00::Run(int flag, int* p) {
    if (!mSub)
        return -1;
    if (flag != 1)
        return -1;
    mSub->Fn(*p);
    return 0;
}
