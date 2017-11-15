class File {
  public:
    File(string fname) {
        this->fcontent = malloc(this->fsize);
        *fcontent = magic_magic(fname);
    }

    ~File() {
        free(this->fcontent);
    }

    File& operator = (const File& r) {
        this->fcontent = malloc(r.fsize);
        *this->fcontent = r->fcontent;
    }

  private:
    string fname;
    void* fcontent;
    usize_t fsize;
}

{
    File file = File("~/.zshrc");
    File copy = file;
}
