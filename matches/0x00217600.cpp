extern "C" int __cdecl Fetch(void* p, float* out);
struct Input { int type; int data; };
struct Output { int type; float value; };
Output* __cdecl Target(Input* p, Output* q) {
    if (p->type == 3) return (Output*)p;
    if (p->type == 4) {
        float value;
        if (Fetch((char*)p->data + 0x10, &value)) {
            q->value = value;
            q->type = 3;
            return q;
        }
    }
    return 0;
}