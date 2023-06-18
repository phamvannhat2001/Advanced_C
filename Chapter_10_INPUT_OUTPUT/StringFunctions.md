## GETLINE

- The latest function for reading a string of text if getline(): having appeared around 2010 or so
- The getline function is the preferred method for reading lines of text from a stream (including standard input)
- The getline function reads an entire from a stream.
- Form: ssize\_t getline( char \*\*buffer, size\_t \*size, FILE \*stream);

\+ The first parameter is a pointer to a block allocated with malloc or calloc (type char \*\*)

- The address of the first character position where the input string will be stored
- Will automatically enlarge ( phong to) the block of memory as needed (realloc)
- Will contain the line read by getline when it returns

\+ The second parameter is a pointer to a variable of type size\_t

- Specifies the size in bytes of the block of memory pointed to by the first parameter
- The address of the variable that holds the size of the input buffer, another pointer

\+ The third parameter is the stream from which to read the line 

- Giá trị trả về của hàm **getline** là số lượng ký tự đã đọc, bao gồm cả ký tự newline ('\n') nhưng không phải ký tự NULL cuối cùng. Nếu đọc thành công, giá trị trả về là số lượng ký tự đã đọc. Nếu không có dữ liệu nào được đọc hoặc có lỗi xảy ra, giá trị trả về là -1.

Example: 
```c
#define _CRT_SECURE_NO_WARNINGS

# include <stdio.h>

# include <string.h>

# include <stdlib.h>

int main()

{

char* buffer = NULL;

size_t bufsize = 32;

size\_t characters;

buffer = (char\*)malloc(bufsize \* sizeof(char));

if (buffer == NULL)

{

exit(1);

}

printf("Type something: ");

characters = getline(&buffer, &bufsize, stdin);

printf("%zu characters were read. \n", characters);

printf("You typed: '%s' \n", buffer);

return 0;

}
```

## PUTS 

- The puts() function is used to write a line to the output screen

\+ Same to printf, appends a newline

- Form : int puts(const char \* string)

Example :
```c
#define _CRT_SECURE_NO_WARNINGS

# include <stdio.h>

# include <string.h>

# include <stdlib.h>

int main()

{

char string[40];

strcpy(string, "Hello");

puts(string);

return 0;
}
```

## FPUTS

Hàm fputs trong ngôn ngữ lập trình C được sử dụng để ghi một chuỗi ký tự vào một luồng (stream) cụ thể.

Cú pháp của hàm fputs như sau:

int fputs(const char \*str, FILE \*stream);

Trong đó:

- str là con trỏ tới chuỗi ký tự mà bạn muốn ghi.
- stream là con trỏ tới luồng mà bạn muốn ghi vào, ví dụ như stdout cho ghi ra màn hình hoặc một tệp tin cho ghi vào file.

Hàm fputs sẽ ghi chuỗi ký tự str vào luồng stream cho đến khi gặp ký tự null ('\0'). Nếu ghi thành công, hàm sẽ trả về non-negative, nếu không, nó sẽ trả về EOF và đặt lỗi (errno) tương ứng.

Dưới đây là một ví dụ minh họa về cách sử dụng hàm fputs:
```c
#include <stdio.h>

int main() {

const char \*str = "Hello, World!";

FILE \*file = fopen("output.txt", "w");

if (file != NULL) {

if (fputs(str, file) != EOF) {

printf("Write to file successful.\n");

} else {

printf("Error writing to file.\n");

}

fclose(file);

} else {

printf("Error opening file.\n");

}
return 0;
}
```

Trong ví dụ này, chúng ta ghi chuỗi "Hello, World!" vào một tệp tin có tên "output.txt". Trước khi ghi, chúng ta kiểm tra xem liệu tệp tin có mở thành công không. Sau khi ghi xong, chúng ta đóng tệp tin bằng hàm fclose.

Lưu ý rằng hàm fputs không thêm ký tự newline ('\n') vào cuối chuỗi tự động. Nếu bạn muốn thêm ký tự newline, bạn cần tự thêm vào trước khi sử dụng hàm fputs.








