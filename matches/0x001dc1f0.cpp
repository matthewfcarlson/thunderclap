struct This_FUN_001dc070 {
    int FUN_001dc070(void*);
};
class Obj_1dc1f0 {
  public:
    char pad[0x62a];
    short values[1];
    bool target(void* param);
};
bool Obj_1dc1f0::target(void* param) {
    if (param) {
        int i = ((This_FUN_001dc070*)this)->FUN_001dc070((char*)param + 8);
        if (i >= 0) {
            int x = values[i * 20];
            return ((unsigned char*)this)[(x + 0x104e) * 20] >> 1 & 1;
        }
    }
    return false;
}