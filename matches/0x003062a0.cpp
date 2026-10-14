class List_3062a0 {
  public:
    char** begin;
    char** end;
};
class Obj_3062a0 {
  public:
    virtual int a();
    virtual int b();
    virtual int c();
    virtual int d();
    virtual int e();
    virtual int f();
    virtual int ready();
    char pad[16];
    List_3062a0* list;
    volatile unsigned char result;
    unsigned char run();
};
unsigned char Obj_3062a0::run() {
    if (ready() == 1 && list) {
        result = 0;
        unsigned int i = 0;
        while (i < (unsigned int)(list->end - list->begin)) {
            if (((Obj_3062a0*)list->begin[i])->run())
                result = 1;
            ++i;
        }
    }
    return result;
}