struct Inner { unsigned char data[1]; };
struct Holder { char pad[0x1c]; Inner* inner; };
struct Service { int Check(); };
struct Obj { char pad0[0x10]; Service* field10; char pad1[0x10c]; Holder* holder; char pad2[0x1f54-0x124]; unsigned int index; bool target(unsigned int* out); };
bool Obj::target(unsigned int* out) {
    if (!field10->Check()) return false;
    unsigned int i = index;
    if (i == 0xffff) return false;
    unsigned int* src = (unsigned int*)(holder->inner->data + i * 0x40 + 0x30);
    out[0] = src[0]; out[1] = src[1]; out[2] = src[2];
    return true;
}