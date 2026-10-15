struct Rec {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void done();
    char pad[20];
    char data[4];
};
extern Rec* findrec(const char*);
class Handler {
  public:
    void write(void*, float, float, float, float, float, float, float);
    void run(float a, float b, float c, float d, float e, float f, float g);
};
void Handler::run(float a, float b, float c, float d, float e, float f, float g) {
    Rec* p = findrec("side_mission_fail_record");
    if (p && &p->data) {
        write(&p->data, a, b, c, d, e, f, g);
        p->done();
    }
}