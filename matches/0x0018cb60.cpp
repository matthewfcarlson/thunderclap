class Obj_18cb60 {
    char pad[0x18];

  public:
    char SetCompare_0018cb60(int v);
};
char Obj_18cb60::SetCompare_0018cb60(int v) {
    *(int*)((char*)this + 0x18) = v;
    return 1;
}
