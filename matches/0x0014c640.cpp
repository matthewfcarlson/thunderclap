class Obj_14c640 {
  public:
    char pad[0x0c];
    bool SetCompare_0014c640(unsigned int v);
};

bool Obj_14c640::SetCompare_0014c640(unsigned int v) {
    *(unsigned int*)((char*)this + 0x0c) = v;
    return true;
}
