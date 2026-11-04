class A_61f80 {
  public:
    char pad[0x14];
    int value;
    bool SetAttachmentIndex_00061f80(int x);
};
bool A_61f80::SetAttachmentIndex_00061f80(int x) {
    value = x;
    return true;
}
