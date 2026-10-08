// Same code shape as 0x000fc1e0 (propagated; names are from that function)
struct Inner { void run(unsigned int, unsigned int); };
struct Obj { int pad; Inner* field; };
extern Obj* g_obj;
extern unsigned char g_flag;
void FUN_000fc1e0(unsigned int a, unsigned int b) {
    g_obj->field->run(a, b);
    g_flag = 1;
}