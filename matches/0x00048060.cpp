class Target_48060 {
  public:
    char pad[12];
    int field;
    bool SetCompare_00048060(int x);
};

bool Target_48060::SetCompare_00048060(int x) {
    field = x;
    return true;
}