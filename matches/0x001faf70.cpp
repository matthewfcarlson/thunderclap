struct FileStream_1faf70 {
    virtual void v0();
    int a, b, c;
};
struct Failure {
    void Fail();
};
struct Helper_1faf70 {
    int x, y, z;
    void Init();
    bool Try(FileStream_1faf70*, int, Failure*, void*, int);
    void Close();
};
struct Obj_1faf70 {
    int pad;
    Failure* y;
    bool Target(int arg);
};
bool Obj_1faf70::Target(int arg) {
    Helper_1faf70 h;
    FileStream_1faf70 fs;
    fs.a = 0;
    fs.b = 0;
    fs.c = 0;
    h.Init();
    if (h.Try(&fs, arg, y, this, 0)) {
        h.Close();
        return true;
    }
    y->Fail();
    h.Close();
    return false;
}
