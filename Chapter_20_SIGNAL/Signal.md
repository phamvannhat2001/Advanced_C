- A process is a program in execution.
- A program is a file containing the information of process, it is loaded into Ram and starts executing.
- Each process its own address space and (usually) one thread of control.
- You can have multiple processes executing the same program.
- But each process has its own copy of the program within its own address space and excutes it independently of the other copies
- Processes are organized hierarchically

\+ each process has a parent process which explicitly(rõ rang) arranged to create it

- The processes created by a given parent are called its child processes

\+ a child inherits many of its attributes from the parent process.

**Signal**


  Trong lập trình, **signal** là một hàm có sẵn trong các ngôn ngữ như C và C++ để xử lý tín hiệu (signals).

Tín hiệu (signal) là một cơ chế trong hệ điều hành để thông báo cho một tiến trình về một sự kiện xảy ra trong môi trường chạy. Sự kiện này có thể là một tín hiệu từ bên ngoài như Ctrl+C từ bàn phím hoặc một tín hiệu tạo ra bởi một tiến trình khác.

Hàm **signal** cho phép bạn đăng ký một hàm xử lý tín hiệu (signal handler) để xử lý tín hiệu cụ thể nào đó khi nó được kích hoạt. Khi một tín hiệu xảy ra, hệ điều hành sẽ gọi hàm xử lý tín hiệu đã được đăng ký để thực hiện các hành động xử lý tương ứng.

Trên hệ điều hành Windows, có một số tín hiệu (signals) được hỗ trợ. Dưới đây là một số tín hiệu phổ biến trong Windows:

SIGINT: Tín hiệu tương đương với tín hiệu khi nhấn phím Ctrl+C trên bàn phím. Mặc định, tín hiệu này được sử dụng để yêu cầu một tiến trình dừng lại.

SIGILL: Tín hiệu được gửi khi một lệnh không hợp lệ được thực hiện bởi CPU, ví dụ như mã máy không hợp lệ hoặc lệnh không được hỗ trợ.

SIGABRT: Tín hiệu được gửi từ chức năng abort(), thường là do một lỗi nghiêm trọng xảy ra trong chương trình và yêu cầu kết thúc chương trình ngay lập tức.

SIGFPE: Tín hiệu được gửi khi một lỗi phép toán dấu phẩy động xảy ra, ví dụ như chia cho 0 hoặc một phép tính không hợp lệ.

SIGSEGV: Tín hiệu được gửi khi một tiến trình truy cập vào một vùng nhớ không hợp lệ, ví dụ như đọc hoặc ghi vào một con trỏ NULL hoặc truy cập qua giới hạn của mảng.

SIGTERM: Tín hiệu được gửi bởi lệnh kill hoặc các công cụ quản lý tiến trình khác để yêu cầu một tiến trình dừng lại một cách bình thường.

SIGSTOP là một tín hiệu (signal) được sử dụng để tạm dừng một tiến trình. Khi một tiến trình nhận được tín hiệu SIGSTOP, nó sẽ tạm dừng hoạt động và không thể tiếp tục thực hiện cho đến khi nhận được một tín hiệu khác để tiếp tục (thông qua SIGCONT).

SIGCONT là một tín hiệu (signal) được sử dụng để tiếp tục thực hiện một tiến trình đã bị tạm dừng. Khi một tiến trình nhận được tín hiệu SIGCONT, nó sẽ tiếp tục hoạt động từ trạng thái tạm dừng và tiếp tục thực hiện công việc của mình.

- SIGKILL: Tín hiệu được gửi bởi lệnh kill để yêu cầu một tiến trình dừng lại ngay lập tức và không thể bị xử lý hoặc bắt được.
- Example: 
```c
#include <stdio.h>

#include <signal.h>

void signalHandler(int signum) {

`    `printf("Tín hiệu %d đã được kích hoạt.\n", signum);

}

int main() {

`    `signal(SIGINT, signalHandler); // Đăng ký hàm xử lý tín hiệu SIGINT

`    `while (1) {

`        `// Các hành động khác trong chương trình

`    `}

`    `return 0;

}
```

- Trong lập trình C/C++, hàm raise() và kill() được sử dụng để gửi tín hiệu (signal) đến một tiến trình hoặc một nhóm tiến trình. Dưới đây là giải thích về mỗi hàm:

Hàm raise():

Prototype: int raise(int sig);

Hàm raise() được sử dụng để gửi một tín hiệu cho chính tiến trình gọi hàm đó (tức là tiến trình hiện tại).

Tham số sig là số hiệu của tín hiệu cần gửi, ví dụ SIGINT, SIGTERM, SIGUSR1, vv.

Giá trị trả về: 0 nếu thành công, -1 nếu có lỗi.

Hàm kill():

Prototype: int kill(pid\_t pid, int sig);

Hàm kill() được sử dụng để gửi một tín hiệu cho một tiến trình hoặc một nhóm tiến trình được xác định bởi pid.

Tham số pid là ID của tiến trình hoặc nhóm tiến trình cần gửi tín hiệu.

Tham số sig là số hiệu của tín hiệu cần gửi.

Giá trị trả về: 0 nếu thành công, -1 nếu có lỗi.

**Alarm()**

- Hàm alarm() trong ngôn ngữ C/C++ được sử dụng để đặt một bộ hẹn giờ (timer) để tạo ra một tín hiệu (signal) sau một khoảng thời gian xác định. Khi thời gian bộ hẹn giờ kết thúc, một tín hiệu SIGALRM sẽ được gửi đến tiến trình.
- Protype : unsigned int alarm(unsigned int seconds);

- Example: 
```c
#include <stdio.h>

#include <windows.h>

void alarmHandler(DWORD signum) {

`    `printf("Tín hiệu SIGALRM đã được kích hoạt.\n");

}

int main() {

`    `// Đăng ký hàm xử lý tín hiệu SIGALRM

`    `SetConsoleCtrlHandler((PHANDLER\_ROUTINE)alarmHandler, TRUE);

`    `// Đặt bộ hẹn giờ trong 3 giây

`    `unsigned int remainingTime = SleepEx(3000, TRUE);

`    `printf("Bộ hẹn giờ đã được đặt trong 3 giây.\n");

`    `// Dừng chương trình trong 5 giây

`    `Sleep(5000);

`    `// Hủy bộ hẹn giờ

`    `remainingTime = SleepEx(0, TRUE);

`    `printf("Bộ hẹn giờ đã bị hủy. Còn lại %u giây.\n", remainingTime / 1000);

`    `return 0;

}
```

- Trong lập trình, việc handling và catching một tín hiệu (signal) đều liên quan đến việc xử lý các sự kiện hoặc tình huống đặc biệt xảy ra trong quá trình chạy của một chương trình.

Handling Signal: Handling signal (xử lý tín hiệu) là quá trình đăng ký và xác định một hàm xử lý (signal handler) để được thực thi khi một tín hiệu cụ thể được kích hoạt. Khi một tín hiệu xảy ra, hàm xử lý tương ứng được gọi để thực hiện các tác vụ xử lý tín hiệu.

Catching Signal: Catching signal (bắt tín hiệu) là quá trình đăng ký một hàm xử lý (signal handler) để bắt tín hiệu và thực hiện các tác vụ xử lý tương ứng. Bắt tín hiệu đề cập đến việc sử dụng một hàm xử lý tín hiệu cụ thể để xử lý tín hiệu khi nó xảy ra.

