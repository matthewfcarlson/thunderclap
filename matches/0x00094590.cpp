class Obj_94590 {
  public:
    void Do(int, int);
    void Target();
};
void Obj_94590::Target() {
    int i = 0;
    do {
        if (i != 0x1b && i >= 0 && i < 0x2fe)
            Do(i, 0);
        ++i;
    } while (i < 0x2fe);
}