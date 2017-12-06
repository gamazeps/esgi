//class Stream {
//  public:
//    virtual Stream& operator << (string& s) = 0;
//    virtual Stream& operator >> (string& s) = 0;
//};
//

class Dumpable {
  public:
    virtual void dump_write() = 0;
};

class Serializable {
  public:
    virtual size_t serialize(void * dst) = 0;
};

class Dummy : public Dumpable, public Serializable {
    size_t serialize(void * dst) {
        return 0;
    }

    void dump_write() {}
};
