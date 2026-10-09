extern "C" void* memcpy(void*, const void*, unsigned int);
class Thing {
  public:
    char pad[0x118];
    void Init(Thing*);
    void Copy(Thing*);
};
void Thing::Copy(Thing* other) {
    Init(other);
    memcpy((char*)this + 0x118, (char*)other + 0x118, 0x28);
    *(unsigned int*)((char*)this + 0x15c) = *(unsigned int*)((char*)other + 0x15c);
    *(unsigned int*)((char*)this + 0x160) = *(unsigned int*)((char*)other + 0x160);
    memcpy((char*)this + 0x164, (char*)other + 0x164, 0x800);
    *(unsigned int*)((char*)this + 0x964) = *(unsigned int*)((char*)other + 0x964);
    *(unsigned int*)((char*)this + 0x96c) = *(unsigned int*)((char*)other + 0x96c);
    *(unsigned int*)((char*)this + 0x970) = *(unsigned int*)((char*)other + 0x970);
    *(unsigned int*)((char*)this + 0x974) = *(unsigned int*)((char*)other + 0x974);
    *(unsigned int*)((char*)this + 0x97c) = *(unsigned int*)((char*)other + 0x97c);
}