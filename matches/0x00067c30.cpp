struct Data_67c30 {
    unsigned int v[5];
};
class Obj_67c30 {
  public:
    unsigned char bytes[0x108];
    bool Put(unsigned int key, const Data_67c30* src);
};
bool Obj_67c30::Put(unsigned int key, const Data_67c30* src) {
    int i;
    if (key == 0)
        return false;
    i = (int)(key & 255);
    if (*(unsigned int*)(bytes + 8 + i * 4) != key)
        return false;
    if (i < 0)
        return false;
    *(Data_67c30*)(bytes + 0x108 + i * 32) = *src;
    return true;
}