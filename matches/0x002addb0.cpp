class Transform {
  public:
    char pad[0x18];
    unsigned int s0, s3, s2, s1, r1, r2, r0, r3;
    unsigned int Run(unsigned int);
};
unsigned int Transform::Run(unsigned int x) {
    return (((x & 0xff) >> r0) << s2) | (((x & 0xff0000) >> r1) << s0) | (((x & 0xff000000) >> r3) << s1) |
           (((x & 0xff00) >> r2) << s3);
}