class Chunk {
  public:
    int Type();
};
class Handler_2ac5b0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual int vfunc_4(Chunk*, int);
    int A(Chunk*, int);
    int B(Chunk*, int);
    int C(Chunk*, int);
};
int Handler_2ac5b0::vfunc_4(Chunk* chunk, int arg) {
    int result = 0;
    switch (chunk->Type()) {
    case 0x15b00:
        result = A(chunk, arg);
        break;
    case 0x15b01:
        result = B(chunk, arg);
        break;
    case 0x15b02:
        result = C(chunk, arg);
        break;
    }
    return result;
}