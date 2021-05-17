#include<iostream>
#include<cstring>


struct String{
    char *cstr;
    unsigned len;
    unsigned real_len;
};


String new_string(char const *cstr){
    String *tmp = new String;
    tmp->len = strlen(cstr);
    tmp->cstr = new char[2*tmp->len+1];
    tmp->real_len = 2*tmp->len+1;
    strcpy(tmp->cstr, cstr);
    return *tmp;
}


String new_string(){
    String *tmp = new String;
    tmp->len =0 ;
    tmp->cstr= 0 ;
    tmp->real_len  =0;
    return *tmp;
}


String new_string(String const &src){
    auto tmp = new String;
    tmp->len = src.len;
    tmp->cstr = new char[2*tmp->len+1];
    tmp->real_len = 2*tmp->len+1;
    strcpy(tmp->cstr, src.cstr);
    return *tmp;
}


void delete_string(String &str){
    delete[] (str.cstr);
}


unsigned length(String const &str){
    return str.len;
}


String& copy(String &dst, String const &src){
    delete[] dst.cstr;
    dst.len=src.len;


    dst.cstr= new char[2*dst.len + 1];
    dst.real_len = 2*dst.len + 1;
    strcpy(dst.cstr, src.cstr);
    return dst;
}


char get_char_at(String const &str, unsigned pos){
    return str.cstr[pos];
}


String& set_char_at(String &str, unsigned pos, char c){
    str.cstr[pos]=c;
    return str;
}


String& append(String &dst, char const *cstr){
    unsigned tmp_len=dst.len;
    unsigned add_len=strlen(cstr);
    dst.len += add_len;
    if (dst.real_len <= dst.len) {
        char *tmp = dst.cstr;
        dst.cstr = new char[2*dst.len + 1];
        dst.real_len = 2*dst.len + 1;
        for (unsigned i = 0; i < tmp_len; i++) {
            dst.cstr[i] = tmp[i];
        }
        for (unsigned i = 0; i < add_len; ++i) {
            dst.cstr[i + tmp_len] = cstr[i];
        }
        dst.cstr[dst.len] = 0;
        delete tmp;
    }
    else{
        for (unsigned i = 0; i < add_len; ++i) {
            dst.cstr[i + tmp_len] = cstr[i];
        }
        dst.cstr[dst.len] = 0;
    }
    return dst;
}


String& append(String &dst, String const &src){
    unsigned tmp_len=dst.len;
    unsigned add_len=src.len;
    dst.len += add_len;

    if (dst.real_len <= dst.len) {
        char *tmp = dst.cstr;
        dst.cstr = new char[2*dst.len + 1];
        for (unsigned i = 0; i < tmp_len; i++) {
            dst.cstr[i] = tmp[i];
        }
        for (unsigned i = 0; i < add_len; ++i) {
            dst.cstr[i + tmp_len] = src.cstr[i];
        }
        dst.cstr[dst.len] = 0;
        delete tmp;
    }
    else{
        for (unsigned i = 0; i < add_len; ++i) {
            dst.cstr[i + tmp_len] = src.cstr[i];
        }
        dst.cstr[dst.len] = 0;
    }
    return dst;
}

String& append_simple(String &dst, char const *cstr){ // неамортизированный массив
    unsigned tmp_len=dst.len;
    unsigned add_len=strlen(cstr);
    dst.len += add_len;

        char *tmp = dst.cstr;
        dst.cstr = new char[dst.len + 1];
        for (unsigned i = 0; i < tmp_len; i++) {
            dst.cstr[i] = tmp[i];
        }
        for (unsigned i = 0; i < add_len; ++i) {
            dst.cstr[i + tmp_len] = cstr[i];
        }
        dst.cstr[dst.len] = 0;
        delete tmp;

    return dst;
}

void print(String const &str){
    std::cout << str.cstr;
}
