#include <iostream>

using namespace std;

class File {
  public:
    File(string fname) {
        this->fcontent = malloc(this->fsize);
        *this->fcontent = magic_magic(fname);
    }

    ~File() {
        free(this->fcontent);
    }

    File& operator = (const File& r) {
        this->fname = r.fname;
        this->fsize = r.fsize;
        
        this->fcontent = malloc(fsize);
        memcpy(r.fcontent, this->fcontent, this->fsize);
    }

  private:
    string fname;
    void* fcontent;
    usize_t fsize;
}

int main() {
    File file = File("~/.zshrc");
    File file_copy = file;
}
