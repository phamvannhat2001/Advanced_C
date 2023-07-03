- The process of creating a C program involves many different steps:
  `        `+ preprocessor  

`        `+ complitation

`        `+ assembler

`        `+linker

`        `+loader

- ` `A program called the preprocessor is invoked( đc gọi) before any code gets compiled in the C programming language.
- The C Preprocessor is essentially a text substitution tool
- The C preprocessor mainly performs three tasks on your code
1. Removes all the comments
1. Include all of the files from various libraries that the program needs to compile
1. Expansion of macro definitions
- #define and #include and other directives #undef, #pragma, and #error
- Every #if construct ends with an #endif
- Directives: #ifdef and #ifndef are provided as shorthand for

\+ #if defined(name)

\+ #if !defined(name)

**Include Guards and #undef**

- Ifndef kiểm tra xem một macro chưa đc định nghĩa.
- Ifdef kiểm tra xem một macro được định nghĩa.
- #ifndef prevents multiple definitions of the same variable/function/macro
- Example:
- #ifndef DEBUG

`    `#define DEBUG 0

- #endif
- #undef Nó được sử dụng để xóa định nghĩa của một macro đã được định nghĩa trước đó.

Ex: #undef name

**Other preprocessor directives** 

- #pragma Nó cung cấp các chỉ thị đặc biệt cho trình biên dịch, cung cấp các hướng dẫn và tùy chọn cho quá trình biên dịch và liên kết.
- **#pragma once**: Đảm bảo rằng mã chỉ được đưa vào một lần duy nhất trong quá trình biên dịch, ngăn chặn việc định nghĩa trùng lặp. Thường được sử dụng trong các tệp định nghĩa hằng số, biến, và các hàm.
- **#pragma message**: Hiển thị một thông báo tùy chỉnh trong quá trình biên dịch. Thường được sử dụng để cung cấp thông tin hỗ trợ hoặc gỡ lỗi.
- **#pragma warning**: Điều chỉnh cách xử lý các cảnh báo từ trình biên dịch. Cho phép tắt, bỏ qua hoặc tùy chỉnh cảnh báo cụ thể.
- **#pragma pack**: Điều chỉnh đóng gói (alignment) của cấu trúc dữ liệu để tối ưu hóa kích thước và tương thích giữa các phiên bản trình biên dịch.
- #pragma GCC dependency Nó được sử dụng để chỉ định phụ thuộc giữa các tệp mã nguồn trong quá trình biên dịch. #pragma GCC dependency("file"). nó sẽ kiểm tra xem tệp "file" có được biên dịch trước tệp hiện tại hay không. Nếu tệp "file" không tồn tại hoặc đã được thay đổi sau lần biên dịch gần nhất của tệp hiện tại, trình biên dịch sẽ phát hiện ra phụ thuộc và buộc biên dịch lại tệp hiện tại.
- #pragma GCC poison Nó được sử dụng để "đánh dấu" một từ khóa, biến hoặc macro để không được sử dụng trong mã nguồn. 

Example

#pragma GCC poison printf

int main() {

`    `printf("Hello, world!\n"); // Dòng này sẽ gây ra cảnh báo và không được biên dịch

`    `return 0;

}

- #pragma GCC system\_header. Nó được sử dụng để thông báo cho trình biên dịch rằng một tệp mã nguồn cụ thể là một tệp tiêu chuẩn của hệ thống và không nên hiển thị các cảnh báo tiền biên dịch trong tệp đó.

Example:

#pragma GCC system\_header

#include <stdio.h>

int main() {

`    `printf("Hello, world!\n");

`    `return 0;

}

- error\_message là thông điệp lỗi tùy chỉnh bạn muốn hiển thị khi điều kiện không được đáp ứng.
- warning\_message là thông điệp cảnh báo tùy chỉnh bạn muốn hiển thị trong quá trình biên dịch.
