**Macro**

- Nó đại diện cho một tập hợp các chỉ thị tiền biên dịch (preprocessor directives) được định nghĩa bằng #define.
- #define MACRO macro\_body

Example:
```c
#define PRNT(a,b) \
	Printf(“value 1= &d\n”,a); \
  Printf(“value 2 = %d\n”,b);
```
**So sánh macro và inline**

- Giống nhau:

Tăng tốc độ thực thi: Cả macro và inline đều nhằm tối ưu hóa mã để tăng tốc độ thực thi chương trình. Bằng cách thực hiện việc nhúng mã hoặc thay thế văn bản, cả hai đều giúp tránh chi phí thời gian và bộ nhớ của việc gọi hàm.

Giảm overhead: Cả macro và inline giúp giảm overhead liên quan đến việc gọi hàm, bởi vì mã được nhúng hoặc thay thế trực tiếp vào điểm gọi, không cần tạo ra khung ngăn xếp và các hoạt động khởi tạo hàm.

Tăng cường hiệu suất: Cả macro và inline đều có tiềm năng tăng cường hiệu suất của chương trình bằng cách giảm thời gian và tài nguyên cần thiết cho việc gọi hàm.

Tích hợp mã nguồn: Cả macro và inline cho phép tích hợp mã nguồn mở rộng vào mã chính, giúp tạo ra mã nguồn mở rộng và dễ đọc hơn.

Kiểm soát trình biên dịch: Cả macro và inline đều liên quan đến việc kiểm soát trình biên dịch. Macro không có trình biên dịch riêng, nhưng sẽ tạo ra mã nguồn mở rộng, trong khi inline được kiểm soát và nhúng mã bởi trình biên dịch.

Tuy cả macro và inline có những sự giống nhau như trên, nhưng cũng có những sự khác nhau quan trọng. Vì vậy, việc chọn giữa macro và inline cần dựa trên yêu cầu cụ thể của dự án và hiểu rõ các hạn chế và ưu điểm của từng phương pháp.

- Khác nhau: 

Macro:

Macro được định nghĩa bằng #define và không phụ thuộc vào cú pháp ngôn ngữ.

Macro thực hiện thay thế văn bản trong quá trình tiền biên dịch, không có khả năng kiểm tra hoặc kiểm soát kiểu dữ liệu và phạm vi.

Macro không có hàm hoặc khối mã riêng biệt, nó chỉ đơn giản là một sự thay thế văn bản.

Macro không có trình biên dịch nhưng sẽ tạo ra mã nguồn mở rộng sau quá trình tiền biên dịch.

Macro có thể tạo ra mã nguồn mở rộng lớn và có thể dẫn đến các vấn đề liên quan đến mắc lỗi định nghĩa, độ ưu tiên và các vấn đề khác.

Inline:

Inline được sử dụng với từ khóa inline và có tính hợp pháp trong ngôn ngữ C++ (trong C, inline chỉ là gợi ý cho trình biên dịch).

Inline đề xuất trình biên dịch nhúng mã nguồn của hàm tại điểm gọi, giúp tránh chi phí overhead của việc gọi hàm.

Inline được kiểm soát bởi trình biên dịch và có kiểu dữ liệu và phạm vi như các hàm thông thường.

Inline có thể tạo ra mã nguồn mở rộng nhỏ và giúp tăng tốc độ thực thi.

Inline có tính khả thi phụ thuộc vào trình biên dịch, và trình biên dịch có thể bỏ qua yêu cầu inline trong một số trường hợp.

**Macro vs Function**

- macros are pre-processed which means that all the macros would be processed before your program compiles. Function are not preprocessed
- **Speed** 

\+ a macro is speed than function

\+ program control must shift to where the function is and the return to the calling program. Takes longer than inline code.

\+ a macro that is used once in a program probably will not have any noticeable improvement in running time. Should use a macro inside a loop

\+ when you call a function, it has to allocate some data( macros do not have this overhead, macro insert code directly into the program)

\+ if you use the same macro 20 times, you get 20 lines of code inserted into your program

\+ if you use a function 20 times, you have just one copy of the function satemetns in your program. 

\+ macros have an advantage in that they do not have to worry about variable types

\+ function give you type checking

\+ một số trình biên dịch giới hạn định nghĩa macro trong một dòng

\+ sử dụng macro khó debug hơn(bời vì nó chạy trước compiler)

**Preprocessor operator**

- Toán tử "#" trong macro được gọi là toán tử chuỗi hóa (stringizing operator). Nó được sử dụng để chuyển đổi một tham số thành một chuỗi ký tự trong macro. Khi tham số được đặt trong toán tử "#", nó sẽ được biến thành một chuỗi ký tự trong mã.

Example: 

```c
#include <stdio.h>
#define STR(x) #x

int main() {

    int num = 42;

    printf("%s\n", STR(num)); // Output: "num"

    return 0;

}
```
- Toán tử "##" trong macro được gọi là toán tử nối chuỗi (concatenation operator). Nó được sử dụng để nối các token lại với nhau trong macro. Toán tử này cho phép xây dựng các biểu thức phức tạp hơn bằng cách kết hợp các token thành một token duy nhất.

```c

#include <stdio.h>

#define CONCAT(a, b) a##b

int main() {

    int num1 = 4;

    int num2 = 2;

    int result = CONCAT(num, 1) + CONCAT(num, 2);

    printf("%d\n", result); // Output: 42

    return 0;

}
```
**Predefined macro**

Các macro chuẩn (Standard Macros):

\_\_LINE\_\_: Số dòng hiện tại trong mã nguồn.

\_\_FILE\_\_: Tên tệp tin hiện tại.

\_\_DATE\_\_: Ngày biên dịch mã (dạng chuỗi).

\_\_TIME\_\_: Thời gian biên dịch mã (dạng chuỗi).

\_\_STDC\_\_: Được định nghĩa trong các chương trình tuân theo chuẩn C.

Các macro liên quan đến phiên bản chuẩn C và C++:

\_\_STDC\_VERSION\_\_: Phiên bản chuẩn C mà trình biên dịch hỗ trợ.

\_\_cplusplus: Được định nghĩa trong các chương trình C++.

Các macro liên quan đến hệ điều hành và nền tảng:

\_WIN32: Xác định hệ điều hành Windows và phiên bản.

\_\_unix\_\_, \_\_linux\_\_: Xác định hệ điều hành Unix/Linux.

\_\_APPLE\_\_: Xác định hệ điều hành macOS và các thiết bị Apple khác.

\_\_ANDROID\_\_: Xác định hệ điều hành Android.

Các macro khác:

NULL: Được định nghĩa như một con trỏ không hợp lệ ((void\*)0).

EOF: Đại diện cho kết thúc tập tin (End-of-File).

\_\_func\_\_: Tên của hàm hiện tại (chỉ có trong C99 và C++11 trở lên).






