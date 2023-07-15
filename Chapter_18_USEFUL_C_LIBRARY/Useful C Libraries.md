**Useful C Libraries**

- Thư viện assert trong ngôn ngữ lập trình C là một thư viện tiêu chuẩn (standard library) cung cấp các cơ chế kiểm tra điều kiện (assertion) trong quá trình phát triển và gỡ lỗi chương trình.
- void assert(int expression); 

Trong đó:

expression là một biểu thức điều kiện cần được kiểm tra. Nếu giá trị của biểu thức là 0 (false), assert sẽ in ra một thông điệp lỗi và chương trình sẽ kết thúc (được thực hiện thông qua abort()).

- **static\_assert** là một công cụ hữu ích để kiểm tra các điều kiện tại thời điểm biên dịch và đảm bảo tính đúng đắn của chương trình. Nó giúp phát hiện lỗi ngay từ quá trình biên dịch và hạn chế lỗi phát sinh trong quá trình thực thi.

static\_assert(expression, diagnostic\_message);

**STDLIB.H**

- **exit()** được sử dụng để kết thúc một chương trình. Hàm này nằm trong thư viện stdlib.h.

int exit(int status);

\+ EXIT\_SUCCESS thường được sử dụng để chỉ ra rằng chương trình đã kết thúc một cách thành công, không có lỗi xảy ra. Trên hầu hết các hệ thống, giá trị của macro này là 0.

\+ EXIT\_FAILURE được sử dụng để chỉ ra rằng một lỗi đã xảy ra khiến chương trình không thể hoàn thành một cách bình thường. Trên hầu hết các hệ thống, giá trị của macro này là 1.

- Hàm **atexit()** được dùng để đăng ký các hàm sẽ được thực thi khi chương trình kết thúc thông qua hàm **exit()**. Hàm **atexit()** cung cấp một cách để chương trình của bạn thực hiện một số hoạt động dọn dẹp, như giải phóng tài nguyên, đóng các tập tin đã mở, v.v... trước khi chương trình kết thúc.

int atexit(void (\*func) (void));

Example:

#include <stdio.h>

#include <stdlib.h>

void cleanup() {

`    `printf("Cleaning up before exiting the program\n");

}

int main() {

`    `atexit(cleanup);

`    `printf("Hello, World!\n");

`    `return 0;

}

Kết quả: 

Hello, World!

Cleaning up before exiting the program

- Hàm exit() và abort() đều là các hàm trong ngôn ngữ lập trình C dùng để kết thúc một chương trình, nhưng chúng có một số sự khác biệt quan trọng:

- Hàm exit():

Khi hàm exit() được gọi, nó sẽ thực hiện các hoạt động dọn dẹp trước khi chương trình kết thúc. Các hoạt động này bao gồm việc đóng tất cả các tập tin đã mở và thực thi các hàm đã đăng ký thông qua hàm atexit().

- Hàm exit() cho phép bạn truyền một mã trạng thái kết thúc (status code) cho hệ điều hành. Mã trạng thái này thường được sử dụng để chỉ ra liệu chương trình có kết thúc thành công hay có lỗi xảy ra.

Hàm abort():

Hàm abort() không thực hiện bất kỳ hoạt động dọn dẹp nào. Khi nó được gọi, chương trình sẽ kết thúc ngay lập tức mà không đóng các tập tin đã mở hay thực thi các hàm đã đăng ký thông qua hàm atexit().

Hàm abort() không cho phép bạn truyền mã trạng thái kết thúc cho hệ điều hành. Thay vào đó, nó tạo ra một tín hiệu SIGABRT để yêu cầu chương trình kết thúc. Nếu tín hiệu này không được xử lý hoặc bị bỏ qua, chương trình sẽ kết thúc và trạng thái kết thúc được trả về cho hệ điều hành sẽ cho thấy chương trình đã bị hủy bởi một tín hiệu.

Nhìn chung, bạn nên sử dụng exit() khi muốn kết thúc chương trình một cách bình thường, và abort() khi muốn kết thúc chương trình ngay lập tức do một lỗi nghiêm trọng hoặc không mong đợi.

- Trong ngôn ngữ lập trình C, hàm **qsort()** được sử dụng để sắp xếp các phần tử trong một mảng.
- Hàm **atoi** là một hàm tiện ích trong ngôn ngữ lập trình C và C++. Tên của hàm **atoi** viết tắt từ "ASCII to Integer", có nhiệm vụ chuyển đổi một chuỗi ký tự chứa số nguyên thành giá trị tương ứng của số đó.

Example:

#include <stdio.h>

#include <stdlib.h>

int main() {

`    `const char\* str = "12345";

`    `int number = atoi(str);

`    `printf("Giá trị số nguyên: %d\n", number);

`    `return 0;

}

- Hàm **strtod** là một hàm tiện ích trong ngôn ngữ lập trình C và C++. Tên của hàm **strtod** viết tắt từ "String to Double", có nhiệm vụ chuyển đổi một chuỗi ký tự chứa số thực thành giá trị tương ứng của số đó dưới dạng kiểu dữ liệu **double**.

double strtod(const char\* str, char\*\* endptr);

- **str** là một con trỏ đến chuỗi ký tự chứa số thực cần chuyển đổi.
- **endptr** là một con trỏ tới một con trỏ, được sử dụng để trả về con trỏ tới vị trí kết thúc của số trong chuỗi. Điều này cho phép bạn xác định các ký tự tiếp theo của chuỗi để xử lý.

- Tên của hàm **strtol** viết tắt từ "String to Long", có nhiệm vụ chuyển đổi một chuỗi ký tự chứa số nguyên thành giá trị tương ứng của số đó dưới dạng kiểu dữ liệu **long int**.

long int strtol(const char\* str, char\*\* endptr, int base);

Trong đó:

- **str** là một con trỏ đến chuỗi ký tự chứa số nguyên cần chuyển đổi.
- **endptr** là một con trỏ tới một con trỏ, được sử dụng để trả về con trỏ tới vị trí kết thúc của số trong chuỗi. Điều này cho phép bạn xác định các ký tự tiếp theo của chuỗi để xử lý.
- **base** là hệ cơ số (từ 2 đến 36) mà số được biểu diễn trong chuỗi. Nếu **base** là 0, hàm **strtol** sẽ tự động xác định cơ số dựa trên các tiền tố của chuỗi (**0x** cho cơ số 16, **0** cho cơ số 8, và 10 cho cơ số 10)
- Hàm rand()

Example:

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

int main() {

`    `// Khởi tạo seed dựa trên thời gian hiện tại

`    `srand(time(0));

`    `// Sinh ngẫu nhiên một số trong khoảng 0-99

`    `int randomNumber = rand() % 100+1;

`    `printf("Số ngẫu nhiên: %d\n", randomNumber);

`    `return 0;

}

- Hàm **system()** là một hàm trong ngôn ngữ lập trình C và C++ được sử dụng để thực thi một lệnh hệ thống từ chương trình. Khi gọi hàm **system(command)**, nó sẽ thực thi lệnh **command** bằng cách gọi tới shell của hệ điều hành.

int system(const char\* command);

- Nếu lệnh được thực thi thành công, hàm **system()** trả về giá trị khác 0, thường là 0 hoặc một giá trị khác biểu thị kết quả của lệnh (thường là 0).
- Nếu lệnh không thể thực thi hoặc xảy ra lỗi, hàm **system()** trả về -1 hoặc một giá trị âm khác.

Example: 

#include <stdio.h>

#include <stdlib.h>

int main() {

`    `int result = system("ls -l"); // Thực thi lệnh "ls -l"



`    `if (result == -1) {

`        `printf("Lỗi trong quá trình thực thi lệnh\n");

`    `} else {

`        `printf("Lệnh đã thực thi thành công\n");

`        `printf("Kết quả trả về: %d\n", result);

`    `}



`    `return 0;

}

- Hàm **strdup** và **strndup** là hai hàm trong ngôn ngữ lập trình C và C++ được sử dụng để sao chép một chuỗi ký tự đã cho vào một vùng nhớ mới. Hai hàm này cung cấp cách tiện lợi để tạo bản sao của một chuỗi ký tự mà không cần quản lý thủ công bộ nhớ.

Example: 

#include <stdio.h>

#include <string.h>

int main() {

`    `const char\* str = "Hello, world!";

`    `char\* duplicate = strndup(str, 5);

`    `printf("Chuỗi gốc: %s\n", str);

`    `printf("Chuỗi sao chép: %s\n", duplicate);

`    `free(duplicate); // Đừng quên giải phóng bộ nhớ đã cấp phát

`    `return 0;

}

**Data and time function**


