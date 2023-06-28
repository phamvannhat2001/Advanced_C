**The goto stament**

- A goto stament causes program control to jump to a particular of code in your program

Example: 
```c 
#include <stdio.h>

int main() {

      int i = 0;

loop:

      printf("i = %d\n", i);

     i++;

     if (i < 5) {

          goto loop;  // Nhảy tới nhãn 'loop'

     }

     return 0;
}
```

- Làm gián đoạn dòng chảy chương trình làm cho khó theo dõi

**Setjmp() and longjmp()**

- Setjmp and longjmp là luồng điều khiển phức tạp ở C
- Setjmp saves a copy of the program counter and the current pointer to the top of the stack
- Int setjmp(jmp\_buf j)

Use the variable j to remember where you are now

- **void longjmp(jmp\_buf env, int val);**
- jmp\_buf env là một kiểu dữ liệu đặc biệt, thường được định nghĩa là một mảng của các kiểu dữ liệu cần thiết để lưu trữ thông tin về trạng thái của chương trình.
- int val là giá trị trả về của lệnh longjmp.
- **Example** 
```c
#include <stdio.h>

#include <setjmp.h>

jmp\_buf env;

void foo() {

      printf("Entering foo()\n");

      longjmp(env, 1);  // Nhảy đến điểm đã được định nghĩa bởi setjmp, với giá trị trả về 1

      printf("This line will not be executed\n");

}

int main() {

      if (setjmp(env) == 0) {

        printf("Calling foo()\n");
        foo();

    } else {

`printf("Returning from longjmp\n");
    }
    return 0;
}
```

- A goto can’t jump out of the current function in C; longjmp can jump a long way away, even to a function in a different file
