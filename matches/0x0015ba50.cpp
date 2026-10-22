struct T_15ba50 {
    char d[8];
    ~T_15ba50() throw();
};
struct Track_15ba50 {
    virtual ~Track_15ba50() throw();
    char p[0x34];
};
struct ClimbLocomotion4Track_15ba50 : Track_15ba50 {
    T_15ba50 m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10;
    ~ClimbLocomotion4Track_15ba50() throw();
};
ClimbLocomotion4Track_15ba50::~ClimbLocomotion4Track_15ba50() throw() {}
