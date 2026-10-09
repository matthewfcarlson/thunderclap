struct FileStream {
    virtual void v0();
    int a, b, c;
};
struct Failure {
    void Fail();
};
struct Helper {
    int x, y, z;
    void Init();
    bool Try(FileStream*, int, Failure*, void*, int);
    void Close();
};
struct Obj {
    int pad;
    Failure* y;
    bool Target(int arg);
};
bool Obj::Target(int arg) {
    Helper h;
    FileStream fs;
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
