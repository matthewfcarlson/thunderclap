struct X_180400 {
    virtual void V();
    char pad[12];
    int m10;
    bool SetAttachmentIndex_00180400(int a);
};

bool X_180400::SetAttachmentIndex_00180400(int a) {
    m10 = a;
    return true;
}
