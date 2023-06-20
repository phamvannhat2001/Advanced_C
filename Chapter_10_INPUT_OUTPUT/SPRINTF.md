## SPRINTF

- The sprint() function is used to write formatted output to a string
- When using sprintf, you can combine several data variable into a character array
- Form: int sprint(char \*string, const char \*format,..)
- Sprint(string, “%d %c %f, value,c,flt);

\+ The first parameter is a char poiter that specifies where to send output (buffer to put the data in) : terminates the string with a null character

\+ the function returns the numbers of characters stored in the string, ***not including the terminating null***

- Make sure the size of buffer to be written to is large enough to avoid buffer overruns
- Sprint is unsafe because it doesn’t check the lengh of destination buffer
- Overflows can cause unexpected results

Example:
```c
#include <stdio.h>

int main()

{

`    `char string[100];

`    `sprintf(string,"Hello viet nam %d",100);

`    `puts(string);

`    `return 0;

}
```

## FPRINTF

- Fprintf is provided to perform the same operation as printf, but on a file
- Form : int fprintf(FILE \* stream, const char\*format,…)
- Example: fprintf(outFile, “my number is: %d\n),555)
- The reason stderr exists is so that error messages can be logged to a device or file other than where the normal output is written

Example:

If(inFile= fopen (“data”,”r”))=NULL)

{

`	`Fprintf(stderr, “Can’t open data for reading.\n);

## FSCANF

- Fscanf is provided to perform the same operations as the scanf function, but on a file

\+ used to read formatted input (set of charracters) form a file

Form: int fscanf( FILE\*fp, const char \*format [,argument,..]);

- Returns the number of arguments that are successfully read and assigned
- Returns the value EOF, if the end of the file is reached before any of the conversion specifications have been processed
- Fscanf(myFile, “%i”,&i);
  ```c
#include <stdio.h>

int main() {

`    `FILE\* fp;

`    `int num1, num2;

`    `float num3;

`    `fp = fopen("input.txt", "r");  // Mở tệp để đọc

`    `if (fp == NULL) {

`        `printf("Không thể mở tệp.\n");

`        `return 1;

`    `}

`    `fscanf(fp, "%d %d %f", &num1, &num2, &num3);  // Đọc các giá trị từ tệp

`    `printf("Số nguyên 1: %d\n", num1);

`    `printf("Số nguyên 2: %d\n", num2);

`    `printf("Số thực: %f\n", num3);

`    `fclose(fp);  // Đóng tệp

`    `return 0;

}
```

## SCANF

- Hàm sscanf trong ngôn ngữ lập trình C được sử dụng để đọc dữ liệu từ một chuỗi và lưu trữ các giá trị được đọc vào các biến đã cho. Đây là một hàm định dạng, tương tự như scanf, nhưng thay vì đọc từ luồng nhập chuẩn (stdin), sscanf đọc từ một chuỗi đã cho.
- Form: int sscanf(const char\* str, const char\* format, ...); 
- Kết quả trả về của hàm sscanf là số lượng các giá trị đã được đọc và lưu trữ thành công và -1 nếu lỗi
- Example: 
```c
const char\* str = "John Doe 25";

char name[50];

int age;

sscanf(str, "%s %s %d", name, age);

printf("Name: %s\n", name);

printf("Age: %d\n", age);
```

Kết quả: 

Name: John

Age: 25

USING FSCANF VS FGETS/SSCANF

- If you use fgets + sscanf, you must enter both values on the same line
```c
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define MAX\_LINE\_LENGTH 100

int main() {

`    `char input[MAX\_LINE\_LENGTH];

`    `int num1, num2;

`    `printf("Enter two integers: ");

`    `fgets(input, sizeof(input), stdin);

`    `if (sscanf(input, "%d %d", &num1, &num2) == 2) {

`        `printf("First number: %d\n", num1);

`        `printf("Second number: %d\n", num2);

`    `} else {

`        `printf("Invalid input!\n");

`    `}

`    `return 0;

}
```

## FFLUSH

- Hàm fflush được sử dụng để đẩy (flush) dữ liệu từ bộ đệm (buffer) của một luồng dữ liệu ra thiết bị hoặc tập tin tương ứng.
- Form: int fflush(FILE \*stream);
- Hàm fflush chấp nhận một tham số là con trỏ tới luồng dữ liệu stream mà chúng ta muốn đẩy dữ liệu từ bộ đệm của nó.

- Công dụng của fflush là đảm bảo rằng mọi dữ liệu trong bộ đệm của luồng dữ liệu đã được ghi ra thiết bị hoặc tập tin. Điều này đặc biệt hữu ích khi chúng ta làm việc với đầu ra định hướng (oriented output), ví dụ như khi chúng ta muốn đảm bảo rằng các dữ liệu đã được ghi vào tập tin trước khi chương trình tiếp tục thực hiện các tác vụ khác.

- Một số điểm lưu ý về hàm fflush:

- Nếu tham số stream là con trỏ NULL, thì fflush sẽ đẩy (flush) tất cả các bộ đệm của tất cả các luồng dữ liệu.
- Khi sử dụng fflush trên một luồng đầu vào (input stream), kết quả không được xác định theo tiêu chuẩn C.
- fflush trả về 0 nếu thành công và trả về một giá trị khác 0 nếu có lỗi xảy ra.
- Chú ý rằng trong nhiều trường hợp, việc sử dụng fflush không cần thiết, vì các hoạt động ghi và đọc trên các luồng dữ liệu sẽ tự động đẩy (flush) dữ liệu khi cần thiết. Tuy nhiên, fflush vẫn hữu ích trong một số tình huống đặc biệt khi chúng ta muốn đảm bảo rằng dữ liệu đã được ghi hoặc đọc hoàn toàn.
