class Obj_15a950 {
  public:
    char Set(int v);
    char m[0x20];
};
char Obj_15a950::Set(int v) {
    *((int*)((char*)this + 0x20)) = v;
    return 1;
}