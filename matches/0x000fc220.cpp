// Same code shape as 0x000fc1e0 (propagated; names are from that function)
struct Inner_fc220 {
    void run(unsigned int, unsigned int);
};
struct Obj_fc220 {
    int pad;
    Inner_fc220* field;
};
extern Obj_fc220* g_obj_fc220;
extern unsigned char g_flag_fc220;
void FUN_000fc220(unsigned int a, unsigned int b) {
    g_obj_fc220->field->run(a, b);
    g_flag_fc220 = 1;
}