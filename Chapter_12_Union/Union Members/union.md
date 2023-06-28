A union is a derived type (similar to a structure) with members that share the same storage space.

- Can be used to save space and for alternating data
- A union does not waste storage on variables that are not being used

Định nghĩa:

Struct: Là một tập hợp các biến có kiểu dữ liệu khác nhau, mỗi biến có một tên riêng. Struct cho phép lưu trữ và quản lý các thành phần dữ liệu riêng lẻ.

Union: Cũng là một tập hợp các biến có kiểu dữ liệu khác nhau, nhưng trong union, chỉ có một biến được sử dụng tại một thời điểm. Union cho phép lưu trữ dữ liệu dưới nhiều dạng nhưng không thể lưu trữ đồng thời các thành phần dữ liệu riêng lẻ.

Bộ nhớ:

Struct: Mỗi thành phần dữ liệu trong struct được lưu trữ tại một địa chỉ riêng biệt trong bộ nhớ. Kích thước của một biến struct là tổng kích thước của các thành phần dữ liệu.

Union: Tất cả các thành phần dữ liệu trong union chia sẻ cùng một địa chỉ bộ nhớ. Kích thước của một union là kích thước của thành phần lớn nhất trong union.

Truy cập:

Struct: Các thành phần dữ liệu trong struct có thể được truy cập độc lập và xử lý như các biến riêng lẻ.

Union: Chỉ có thể truy cập một thành phần của union tại một thời điểm. Khi một thành phần của union được gán giá trị mới, giá trị của các thành phần khác có thể thay đổi.

Sử dụng:

Struct: Thường được sử dụng khi cần lưu trữ các thông tin có liên quan trong một đối tượng hoặc cấu trúc dữ liệu phức tạp.

Union: Thường được sử dụng khi cần tiết kiệm bộ nhớ hoặc khi cần xử lý dữ liệu ở dạng khác nhau trong một cùng một vùng nhớ.

Lựa chọn giữa struct và union phụ thuộc vào yêu cầu của từng bài toán cụ thể. Struct phù hợp cho việc lưu trữ và quản lý các thành phần dữ liệu riêng biệt, trong khi union thích hợp để tiết kiệm bộ nhớ hoặc xử lý dữ liệu đa dạng trong cùng một vùng nhớ.





