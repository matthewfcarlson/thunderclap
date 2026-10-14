struct Inner_fc1e0 {
    void run(unsigned int, unsigned int);
};
struct Obj_fc1e0 {
    int pad;
    Inner_fc1e0* field;
};
extern Obj_fc1e0* g_obj_fc1e0;
extern unsigned char g_flag_fc1e0;
void FUN_000fc1e0(unsigned int a, unsigned int b) {
    g_obj_fc1e0->field->run(a, b);
    g_flag_fc1e0 = 1;
}