struct Obj {
    char pad[0x7c];
    int m7c;
    bool Fn(int arg);
};

bool Obj::Fn(int arg) {
    m7c = arg;
    return true;
}