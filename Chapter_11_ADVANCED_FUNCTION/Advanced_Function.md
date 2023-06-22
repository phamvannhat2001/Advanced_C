## ﻿Variadic

Variadic là thuộc tính của một hàm hoặc một macro trong ngôn ngữ lập trình, cho phép chúng có số lượng đối số không xác định hoặc có thể thay đổi trong quá trình gọi.

- A variadic function has two parts

\+ Mandatory (bắt buộc) arguments

\+ Optional arguments

- Phần cố định (Fixed part): Đây là phần định nghĩa trước đó của hàm, trong đó có các đối số cố định được khai báo một cách rõ ràng và có số lượng xác định. Phần này đại diện cho các đối số không thay đổi trong các lần gọi hàm.
- Phần biến đổi (Variadic part): Đây là phần của hàm cho phép nhận số lượng đối số không xác định hoặc có thể thay đổi trong các lần gọi hàm. Phần này thường được xử lý bằng cách sử dụng các cơ chế như **stdarg.h** trong C hoặc variadic templates trong C++. Qua phần này, hàm có khả năng nhận và xử lý một danh sách đối số không xác định có thể có độ dài khác nhau.
- Va\_list

\+ **va\_list** là một kiểu dữ liệu trong thư viện <stdarg.h> trong ngôn ngữ lập trình C. Nó được sử dụng để tạo danh sách các đối số trong varidic functions, tức là các hàm có số lượng đối số không xác định

\+ **va\_start** là một macro trong thư viện **<stdarg.h>** trong ngôn ngữ lập trình C. Nó được sử dụng để khởi tạo **va\_list** và xác định đối số cuối cùng trong danh sách các đối số của một varidic function.

\+ **va\_arg** là một macro trong thư viện **<stdarg.h>** trong ngôn ngữ lập trình C. Nó được sử dụng để truy cập các đối số trong danh sách các đối số của một varidic function.

\+ **va\_end** là một macro trong thư viện <stdarg.h> trong ngôn ngữ lập trình C. Nó được sử dụng để kết thúc việc truy cập danh sách đối số trong một varidic function.

\+ **va\_copy()** để sao chép một danh sách đối số từ một biến va\_list sang một biến khác.

**Va\_copy()**

- Va\_arg() does not provide a way to back up to previous arguments
- void va\_copy(va\_list dest, va\_list src);
- Trong đó, dest là biến va\_list đích mà bạn muốn sao chép danh sách đối số vào, và src là biến va\_list nguồn từ danh sách đối số sẽ được sao chép.
- Việc sử dụng va\_copy() hữu ích khi bạn muốn duy trì một bản sao của danh sách đối số ban đầu để sử dụng lại trong quá trình truy cập danh sách đối số.

## INLINE

- Normally, a function call has overhead when being invoked

\+ it takes execution time to set up the call, pass argument, jump to the function code, and return

- Usually the compiler will substitute the code of the function into its caller
- Inline functions can improve the runtime performance of a program
- If there are many lines in inline function or there are more function calls, the in-linung can cause wastage of space
- It increases file as the same function code is copy again and again in the program wherever ít is called
- For a long function, the time consumed in calling the function is short compared to the time spent executing the body of the function
- Should always use the inline function specifier along with the static storage-class specifier(using extern less portable)

Example: Inline static void foo()

\_NORETURN\_FUNCTION

- C11 added a second function specifier ( in addition to inline) named\_ Noreturn
- The purpose of this specifier is to inform the user and the compiler that a particular function will not return control to the calling program when it completes execution 
- Informing the user helps to prevent misuse of the function
- Informing the compiler may enable it to make some code optimizations
- Một hàm không bao giờ trả về là một hàm mà khi nó được gọi, nó không thoát ra khỏi hàm mà trở lại vị trí gọi hàm, mà thay vào đó gây ra một hành động như kết thúc chương trình hoặc khởi động lại hệ thống.
- Ví dụ, hàm exit() là một hàm không trả về, vì sau khi nó được gọi, chương trình kết thúc và không trở lại vị trí gọi hàm.
- Ví dụ : 

``` c

#include <stdio.h>

#include <stdlib.h>

\_Noreturn void end\_program() {

`    `printf("Ending the program.\n");

`    `exit(0);

}

int main() {

`    `printf("Starting the program.\n");

`    `end\_program();

`    `printf("This line will not be executed.\n");

`    `return 0;

}
``` 
