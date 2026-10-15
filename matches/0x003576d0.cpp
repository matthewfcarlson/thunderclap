struct Obj {
    unsigned char b;
    Obj() { b = 1; }
    ~Obj();
    void Init();
};
Obj* getObj() {
    static Obj obj;
    obj.Init();
    return &obj;
}