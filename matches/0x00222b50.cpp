class C { public: char pad[0x68]; unsigned count; struct Entry { int key; int value; unsigned char flag; char pad[0x1f]; } entries[1]; bool f(int key, unsigned char flag, int value); };
bool C::f(int key, unsigned char flag, int value) {
    for (unsigned i=0; i<count; ++i) {
        Entry* e=(Entry*)((char*)this + 0x6c + i*0x28);
        if (e->key==key) { e->flag=flag; e->value=value; return true; }
    }
    return false;
}