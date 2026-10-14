class Source_23a550 {
  public:
    void helper(char*, int, int, int);
};
class StreamStringReader {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual bool vfunc_4();
    virtual void f();
    virtual bool next();
    char pad[12];
    bool value;
    bool done;
};
bool StreamStringReader::vfunc_4() {
    if (done)
        return value;
    value = false;
    if (next()) {
        done = false;
        return value;
    }
    ((Source_23a550*)*(void**)((char*)this + 12))->helper((char*)this + 16, 1, 1, 1);
    done = true;
    return value;
}
