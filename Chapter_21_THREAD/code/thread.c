#include <stdio.h>
#include <windows.h>

// Hàm chạy trong luồng
DWORD WINAPI MyThreadFunction(LPVOID lpParam) {
    int threadNumber = *(int*)lpParam;
    printf("Thread %d is running\n", threadNumber);
    Sleep(2000); // Tạm dừng thực thi luồng trong 2 giây
    printf("Thread %d is done\n", threadNumber);
    return 0;
}

int main() {
    // Khởi tạo và tạo luồng
    HANDLE threads[3];
    DWORD threadIds[3];
    int threadParams[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++) {
        threads[i] = CreateThread(NULL, 0, MyThreadFunction, &threadParams[i], 0, &threadIds[i]);
        if (threads[i] == NULL) {
            printf("Error creating thread\n");
            return 1;
        }
    }

    // Chờ đợi cho tất cả các luồng kết thúc
    WaitForMultipleObjects(3, threads, TRUE, INFINITE);

    // Đóng các handle của luồng
    for (int i = 0; i < 3; i++) {
        CloseHandle(threads[i]);
    }

    printf("All threads have finished\n");

    // Tạo một event
    HANDLE event = CreateEvent(NULL, FALSE, FALSE, NULL);
    if (event == NULL) {
        printf("Error creating event\n");
        return 1;
    }

    // Đặt trạng thái event thành sáng
    SetEvent(event);

    // Chờ đợi cho event trở thành sáng
    WaitForSingleObject(event, INFINITE);

    printf("Event is signaled\n");

    // Đặt trạng thái event thành tối
    ResetEvent(event);

    // Ghi giá trị vào một biến semaphore
    HANDLE semaphore = CreateSemaphore(NULL, 0, 5, NULL);
    if (semaphore == NULL) {
        printf("Error creating semaphore\n");
        return 1;
    }

    // Tăng giá trị semaphore
    ReleaseSemaphore(semaphore, 1, NULL);

    // Chờ đợi cho semaphore giảm giá trị
    WaitForSingleObject(semaphore, INFINITE);

    printf("Semaphore value is decreased\n");

    // Đóng handle của event và semaphore
    CloseHandle(event);
    CloseHandle(semaphore);

    return 0;
}
