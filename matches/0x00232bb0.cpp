class Obj {
  public:
    virtual void a();
    virtual void release();
};
struct Holder {
    Obj* obj;
    ~Holder() {
        if (obj) {
            obj->release();
            obj = 0;
        }
    }
};
extern Holder* gHolder;
void shutdown() {
    delete gHolder;
    gHolder = 0;
}