Lệnh **strchr(buf, '\n')** trong ngôn ngữ C được sử dụng để tìm vị trí xuất hiện đầu tiên của ký tự newline (**'\n'**) trong chuỗi ký tự **buf**. Dưới đây là một số thông tin liên quan đến lệnh này:

- Lệnh **strchr** được định nghĩa trong thư viện chuỗi **string.h** trong ngôn ngữ C.
- Cú pháp của lệnh **strchr** là:

cCopy code

<pre>
```
char *strchr(const char *str, int c);
```
</pre>

- **str** là con trỏ tới chuỗi ký tự cần tìm trong.
- **c** là giá trị của ký tự cần tìm (ở đây là **'\n'**).
- Lệnh **strchr** trả về con trỏ tới vị trí đầu tiên mà ký tự **c** xuất hiện trong chuỗi **str**. Nếu không tìm thấy ký tự **c**, nó trả về con trỏ NULL.
- Khi sử dụng lệnh **strchr(buf, '\n')** để tìm ký tự newline **'\n'** trong chuỗi **buf**, nếu kết quả trả về là con trỏ NULL, có nghĩa là ký tự newline không xuất hiện trong chuỗi. Ngược lại, nếu kết quả trả về không phải là con trỏ NULL, nó sẽ trỏ đến vị trí đầu tiên mà ký tự newline xuất hiện trong chuỗi.

Thông thường, khi sử dụng **strchr(buf, '\n')**, ta kiểm tra kết quả trả về để xác định xem chuỗi có chứa ký tự newline hay không. Nếu kết quả trả về là con trỏ NULL, có thể xử lý theo ý muốn (ví dụ: không có newline trong chuỗi). Nếu kết quả trả về không phải là con trỏ NULL, ta có thể thực hiện các xử lý tiếp theo dựa trên vị trí của ký tự newline trong chuỗi.

|||||
| :- | :- | :- | :- |
|||||
|||||

