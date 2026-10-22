class CControllerManager_ae9d0 {
  public:
    char pad[12];
    char data[15];
    void Set(int index, char value);
};
void CControllerManager_ae9d0::Set(int index, char value) {
    if (index >= 0 && index < 15)
        data[index] = value;
}