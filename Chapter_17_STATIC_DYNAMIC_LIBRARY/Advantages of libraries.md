**Advantages of libraries**

- Libraries are useful because they allow for fast compilation times
- Linking is the processes of collecting and combining multiple object files in order to create a single executable file.
- One of the main tasks for linker is to make the code of library functions available program

Static linking (liên kết tĩnh) và dynamic linking (liên kết động) là hai phương pháp khác nhau để thực hiện quá trình linking trong lập trình.

Static Linking:

Trong static linking, toàn bộ mã máy từ các file đối tượng và thư viện được liên kết trực tiếp vào chương trình thực thi. Quá trình này xảy ra trong giai đoạn biên dịch và tạo ra một file thực thi độc lập mà không cần phụ thuộc vào bất kỳ thư viện ngoài nào.

Ưu điểm của static linking là:

Đơn giản và dễ triển khai: Chỉ cần gửi file thực thi đã liên kết tĩnh, người dùng có thể chạy chương trình mà không cần cài đặt các thư viện bổ sung.

Độc lập và tin cậy: Vì tất cả các phụ thuộc đã được liên kết vào chương trình, nên không có rủi ro liên quan đến việc thiếu thư viện hoặc xung đột phiên bản thư viện.

Static libraries have the advantage of speed

Nhược điểm của static linking là:

Tăng kích thước chương trình: Mỗi lần liên kết tĩnh, mã máy của các thư viện được nhúng vào chương trình, làm tăng kích thước của file thực thi.

Không linh hoạt: Nếu có bất kỳ cập nhật nào đối với thư viện, bạn cần phải biên dịch và liên kết lại toàn bộ chương trình để cập nhật.

Dynamic Linking:

Trong dynamic linking, các thư viện được liên kết vào chương trình thực thi tại thời điểm chạy, không phải trong quá trình biên dịch. Chương trình thực thi sẽ chứa tham chiếu tới các thư viện bên ngoài và nạp chúng vào bộ nhớ khi chạy.

Ưu điểm của dynamic linking là:

Tiết kiệm không gian lưu trữ: Chương trình thực thi chỉ chứa tham chiếu tới các thư viện, không nhúng mã máy của chúng. Do đó, kích thước file thực thi nhỏ hơn.

Dễ dàng cập nhật và chia sẻ: Nếu có bất kỳ cập nhật nào đối với thư viện, chỉ cần thay thế file thư viện mới mà không cần biên dịch lại toàn bộ chương trình.

Nhược điểm của dynamic linking là:

Phụ thuộc vào thư viện bên ngoài: Để chạy chương trình, người dùng cần có các thư viện tương ứng. Nếu thư viện bị mất hoặc phiên bản không tương thích, chương trình sẽ không chạy được.

Chậm hơn: Do quá trình nạp thư viện vào bộ nhớ tại thời điểm chạy, dynamic linking thường chậm hơn so với static linking.

Tùy thuộc vào yêu cầu và điều kiện cụ thể, lập trình viên có thể chọn sử dụng static linking hoặc dynamic linking trong việc phát triển chương trình.


**Dynamic loading**

- Dynamic loading is a mechanism by which a computer can, at run time, load a library ( or other binary) into memory.

\+ can retrieve(lấy) the addresses of functions and variables contained in the library

\+ can execute those functions or access those variable

\+ can unload the library from memory

- The main difference of dynamic linking to a shared objecet is that the libraries are not automatically loaded at program start-up
- Trong C, dynamic loading có thể được thực hiện bằng cách sử dụng các hàm và thư viện hỗ trợ như dlopen(), dlsym(), và dlclose().
- Tiết kiệm tài nguyên: Dynamic loading giúp tiết kiệm tài nguyên hệ thống bằng cách chỉ nạp các module cần thiết vào bộ nhớ khi cần sử dụng. Điều này giúp giảm thời gian khởi động chương trình và tiết kiệm bộ nhớ.
- **Hàm dlopen()** trong ngôn ngữ C là một hàm được sử dụng để mở (load) một thư viện chia sẻ (shared library) vào bộ nhớ tại thời điểm chạy của chương trình. Hàm này thuộc vào thư viện <dlfcn.h> và có cú pháp như sau:

\+ void\* dlopen(const char\* filename, int flag);

Trong đó:

filename là một chuỗi ký tự đại diện cho tên file thư viện chia sẻ cần mở. Đối với hệ điều hành Unix/Linux, tên file thường có đuôi .so (ví dụ: "mylibrary.so"), và đối với Windows, tên file thường có đuôi .dll (ví dụ: "mylibrary.dll").

flag là một cờ chỉ định các tùy chọn cho quá trình mở thư viện. Các cờ thông dụng bao gồm:

**RTLD\_LAZY**: Thực hiện việc nạp (load) thư viện theo cách lười biếng (lazy-loading). Các symbol trong thư viện chỉ được giải quyết khi cần thiết.

**RTLD\_NOW**: Thực hiện việc nạp thư viện ngay lập tức (immediate-loading). Tất cả các symbol trong thư viện được giải quyết khi thư viện được mở.

**RTLD\_GLOBAL**: Các symbol được xuất hiện trong thư viện sẽ có phạm vi toàn cục (global scope), cho phép các thư viện khác cũng có thể truy cập đến các symbol này.

**RTLD\_LOCAL**: Các symbol chỉ có phạm vi cục bộ (local scope), không được truy cập từ các thư viện khác.

Hàm dlopen() trả về một con trỏ void (kiểu void\*) trỏ tới vùng nhớ được cấp phát cho thư viện chia sẻ đã được nạp. Nếu quá trình mở thư viện thất bại, hàm trả về NULL.

Sau khi thư viện chia sẻ đã được mở bằng dlopen(), chúng ta có thể sử dụng hàm dlsym() để lấy con trỏ tới các hàm hoặc biến trong thư viện, và dlclose() để đóng thư viện khi không cần thiết nữa.

- **Hàm dlerror()** là một hàm trong thư viện <dlfcn.h> trong ngôn ngữ lập trình C, được sử dụng để truy xuất thông tin về lỗi xảy ra trong quá trình tải và sử dụng thư viện chia sẻ (shared library) thông qua dynamic loading.

- Cú pháp của hàm dlerror() như sau: char\* dlerror(void);

- Hàm này trả về một con trỏ kiểu char\* trỏ tới một chuỗi ký tự chứa thông tin về lỗi gần nhất xảy ra trong quá trình sử dụng dynamic loading. Nếu không có lỗi xảy ra hoặc sau khi gọi dlerror() đã gọi một hàm khác, hàm dlerror() trả về NULL.
- Để sử dụng hàm dlerror(), bạn có thể thực hiện các bước sau:
- Gọi dlerror() để xóa bất kỳ lỗi nào trong bộ nhớ đệm của hàm.
- Thực hiện các thao tác dynamic loading (như sử dụng dlopen(), dlsym(), dlclose()).
- Sau mỗi lần gọi một hàm dynamic loading, kiểm tra giá trị trả về và nếu cần, gọi dlerror() để truy xuất thông tin lỗi.
- Hàm **dlsym()** là một hàm trong thư viện **<dlfcn.h>** trong ngôn ngữ lập trình C, được sử dụng để lấy con trỏ tới một hàm hoặc biến trong thư viện chia sẻ (shared library) đã được nạp vào bộ nhớ thông qua dynamic loading.
- void\* dlsym(void\* handle, const char\* symbol);
- Trong đó:
- handle là con trỏ kiểu void\* đại diện cho handle (còn được gọi là tham chiếu) của thư viện chia sẻ mà chứa hàm hoặc biến cần lấy. Tham số này thường là kết quả của hàm dlopen().
- symbol là một chuỗi ký tự đại diện cho tên của hàm hoặc biến cần lấy trong thư viện chia sẻ.
- Hàm dlsym() trả về một con trỏ void (kiểu void\*) trỏ tới hàm hoặc biến có tên symbol trong thư viện đã được nạp. Nếu không tìm thấy hàm hoặc biến, hàm trả về NULL.
- Sau khi lấy được con trỏ tới hàm hoặc biến bằng dlsym(), bạn có thể sử dụng con trỏ đó để gọi hàm hoặc truy cập biến tương ứng trong thư viện.

Example:

#include <stdio.h>

#include <dlfcn.h>

int main() {

`    `void\* library\_handle;

`    `void (\*function\_ptr)(void);



`    `// Mở thư viện

`    `library\_handle = dlopen("mylibrary.so", RTLD\_LAZY);

`    `if (library\_handle == NULL) {

`        `fprintf(stderr, "Khong the mo thu vien: %s\n", dlerror());

`        `return 1;

`    `}



`    `// Lấy con trỏ tới hàm trong thư viện

`    `function\_ptr = dlsym(library\_handle, "my\_function");

`    `if (function\_ptr == NULL) {

`        `fprintf(stderr, "Khong the tim thay ham: %s\n", dlerror());

`        `dlclose(library\_handle);

`        `return 1;

`    `}



`    `// Gọi hàm từ thư viện

`    `(\*function\_ptr)();



`    `// Đóng thư viện

`    `dlclose(library\_handle);



`    `return 0;

}
