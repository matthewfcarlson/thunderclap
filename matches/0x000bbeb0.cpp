class Layout_bbeb0 {
  public:
    void* mVptr;
    struct Sub {
        int mField;
        void Select(const char* name);
    }* mMember;
    int Get(int a, int b);
};

int Layout_bbeb0::Get(int a, int b) {
    struct Sub* p = mMember;
    if (!p)
        return -1;
    p->Select("blonsky_file_selector");
    return 0;
}
