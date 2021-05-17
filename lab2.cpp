#include<iostream>
#include<cstring>


struct String{
    char *cstr; //указатель на C-style строку
    unsigned len;
    unsigned real_len;
};


String new_string(){ //пустой массив
    String *tmp = new String;
    tmp->len =0 ;
    tmp->cstr = 0 ;
    tmp->real_len = 0;
    return *tmp;
}


String new_string(char const *cstr){ //массив из c-style
    String *tmp = new String;
    tmp->len = strlen(cstr);
    tmp->cstr = new char[2*tmp->len+1];
    tmp->real_len = 2*tmp->len+1;
    strcpy(tmp->cstr, cstr);
    return *tmp;
}


String new_string(String const &src){ //массив из строки
    String *tmp = new String;
    tmp->len = src.len;
    tmp->cstr = new char[2*tmp->len+1];
    tmp->real_len = 2*tmp->len+1;
    strcpy(tmp->cstr, src.cstr);
    return *tmp;
}


void delete_string(String &str){
    str.len = 0;
    str.real_len = 0;
    delete[] (str.cstr);
}


unsigned length(String const &str){
    return str.len;
}


String& copy(String &dst, String const &src){ //копируем в строку
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


String& append(String &dst, char const *cstr){ //присоединяем c-style к массиву
    unsigned tmp_len = dst.len; 
    dst.len += strlen(cstr); // длина получаемой строки
    if (dst.real_len <= dst.len) { // если reallen old < len new + len(cstr)
        char *tmp = dst.cstr; // для ?? старые данные
        dst.cstr = new char[2*dst.len + 1]; // 2 новых длины +1
        dst.real_len = 2*dst.len + 1; // новый reallen
        for (unsigned i = 0; i < tmp_len; i++) { // копируем tmp (старая строка) в новую
            dst.cstr[i] = tmp[i];
        }
        for (unsigned i = 0; i < strlen(cstr); ++i) { // копируем c-style в новую
            dst.cstr[i + tmp_len] = cstr[i];
        }
        dst.cstr[dst.len] = 0;
        delete tmp;
    }
    else{
        for (unsigned i = 0; i < strlen(cstr); ++i) {
            dst.cstr[i + tmp_len] = cstr[i];
        }
        dst.cstr[dst.len] = 0;
    }
    


    return dst;
}


String& append(String &dst, String const &src){
    unsigned tmp_len=dst.len;
    dst.len += src.len;

    if (dst.real_len <= dst.len) {
        char *tmp = dst.cstr;
        dst.cstr = new char[2*dst.len + 1];
        for (unsigned i = 0; i < tmp_len; i++) {
            dst.cstr[i] = tmp[i];
        }
        for (unsigned i = 0; i < src.len; ++i) {
            dst.cstr[i + tmp_len] = src.cstr[i];
        }
        dst.cstr[dst.len] = 0;
        delete tmp;
    }
    else{
        for (unsigned i = 0; i < src.len; ++i) {
            dst.cstr[i + tmp_len] = src.cstr[i];
        }
        dst.cstr[dst.len] = 0;
    }
    return dst;
}

String& append_simple(String &dst, char const *cstr){ // неамортизированный массив
    unsigned tmp_len=dst.len;
    dst.len += strlen(cstr);

    char *tmp = dst.cstr;
    dst.cstr = new char[dst.len + 1];
    for (unsigned i = 0; i < tmp_len; i++) {
        dst.cstr[i] = tmp[i];
    }
    for (unsigned i = 0; i < strlen(cstr); ++i) {
        dst.cstr[i + tmp_len] = cstr[i];
    }
    dst.cstr[dst.len] = 0;
    delete tmp;

    return dst;
}

void print(String const &str){
    std::cout << str.cstr;
}
