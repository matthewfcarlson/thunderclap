struct Data {
    unsigned int v[5];
};
class Obj {
  public:
    unsigned char bytes[0x108];
    bool Put(unsigned int key, const Data* src);
};
bool Obj::Put(unsigned int key, const Data* src) {
    int i;
    if (key == 0)
        return false;
    i = (int)(key & 255);
    if (*(unsigned int*)(bytes + 8 + i * 4) != key)
        return false;
    if (i < 0)
        return false;
    *(Data*)(bytes + 0x108 + i * 32) = *src;
    return true;
}