class ControllerXBox {
  public:
    char pad[0x428];
    void* vfunc_16(unsigned int index);
};

void* ControllerXBox::vfunc_16(unsigned int index) {
    if (index < 2)
        return (char*)this + index * 16 + 0x428;
    return 0;
}