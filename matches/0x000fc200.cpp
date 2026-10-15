// Same code shape as 0x000fc1e0 (propagated; names are from that function)
struct Inner_fc200 {
    void run(unsigned int, unsigned int);
};
struct Obj_fc200 {
    int pad;
    Inner_fc200* field;
};
extern Obj_fc200* g_obj_fc200;
extern unsigned char g_flag_fc200;
void FUN_000fc200(unsigned int a, unsigned int b) {
    g_obj_fc200->field->run(a, b);
    g_flag_fc200 = 1;
}