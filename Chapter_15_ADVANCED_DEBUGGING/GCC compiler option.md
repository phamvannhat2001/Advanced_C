**GCC compiler option**

**Debugging with the preprocessor**

Example:
```c
#ifdef DEBUG

Fprintf(stderr,”Hello : %d”,a);

#endif
```

Bật debug gcc -D DEBUG main.c

Hoặc
```c
#define DEBUG(fmt, …) fprintf(stderr, fmt, \_\_VA\_ARGS\_\_)

DEBUG(“process(%d, %d),I,j);
```

- "Core files" hay "core dumps" trong lập trình là những tệp tin chứa thông tin về trạng thái của một chương trình tại thời điểm nó gặp lỗi hoặc bị crash. Cụ thể, chúng chứa hình ảnh của bộ nhớ của chương trình, bao gồm cả stack, heap, registers, và thông tin khác. Core files cũng chứa các giá trị của biến và con trỏ tại thời điểm chương trình crash.
- Trong lập trình, "profiling" là quá trình thu thập dữ liệu về hoạt động của một chương trình khi nó đang chạy, với mục đích phân tích và tìm cách cải thiện hiệu suất. Dữ liệu thu thập thông qua profiling có thể bao gồm những thông tin như:

\+ Thời gian chạy của từng hàm hoặc đoạn mã.

\+ Số lần gọi mỗi hàm.

\+ Số lượng bộ nhớ được sử dụng.

