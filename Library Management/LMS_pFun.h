#ifdef LMS_pFun_h
#define LMS_pFun_h
//define any structs in my header file 
    struct Book
    {
        char title[100];
        char author[100];
        int isbn;
        int year;
        int available;
    };
    

//function prototype declaration file
    void printBook(struct Book book); 

#endif