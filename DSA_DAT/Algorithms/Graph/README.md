# Lý Thuyết Đồ Thị

## 1. Lý Thuyết

### Các Loại Đồ Thị

- **Đơn đồ thị**: Đồ thị không có cạnh bội và không có khuyên.
- **Đa đồ thị**: Đồ thị có thể có cạnh bội nhưng không có khuyên.
- **Giả đồ thị (có khuyên)**: Đồ thị có thể có cạnh bội và khuyên.

- **Đơn đồ thị có hướng**: Đồ thị có hướng không có cạnh bội và không có khuyên.
- **Đơn đồ thị vô hướng**: Đồ thị vô hướng không có cạnh bội và không có khuyên.
- **Đa đồ thị có hướng**: Đồ thị có hướng có thể có cạnh bội nhưng không có khuyên.
- **Đa đồ thị vô hướng**: Đồ thị vô hướng có thể có cạnh bội nhưng không có khuyên.

### Các Khái Niệm Cơ Bản

- **Đỉnh kề, cạnh liên thuộc**: Hai đỉnh được gọi là kề nhau nếu có cạnh nối giữa chúng. Cạnh được gọi là liên thuộc với đỉnh nếu nó nối đỉnh đó với một đỉnh khác.
- **Bậc của đỉnh trong đồ thị vô hướng**: Số cạnh liên thuộc với đỉnh đó.
- **Bậc của đỉnh trong đồ thị có hướng (bậc vào, bậc ra)**: 
  - Bậc vào: Số cung đi vào đỉnh.
  - Bậc ra: Số cung đi ra từ đỉnh.

- **Đường đi, chu trình**: 
  - Đường đi: Dãy các đỉnh liên tiếp kề nhau.
  - Chu trình: Đường đi có đỉnh đầu và đỉnh cuối trùng nhau.

- **Liên thông, thành phần liên thông (đồ thị vô hướng)**:
  - Liên thông: Đồ thị có đường đi giữa mọi cặp đỉnh.
  - Thành phần liên thông: Đồ thị con liên thông tối đại.

- **Liên thông mạnh, liên thông yếu (đồ thị có hướng)**:
  - Liên thông mạnh: Đồ thị có đường đi có hướng giữa mọi cặp đỉnh.
  - Liên thông yếu: Đồ thị trở nên liên thông khi bỏ qua hướng của các cung.

## 2. Cài Đặt và Biểu Diễn Đồ Thị

### Ma Trận Kề (Mật Độ Dày)

- **Đồ thị vô hướng**:
  - Ma trận đối xứng.
  - Các phần tử trên đường chéo chính = 0.
  - Các phần tử trên đường chéo phụ = 1 nếu có cạnh nối 2 đỉnh đó, = 0 nếu không có cạnh nối.
  - Tổng phần tử trên 1 hàng = bậc của đỉnh đó.
  - Tổng phần tử trên ma trận = 2 * số cạnh.

- **Đồ thị có hướng**:
  - Ma trận không đối xứng.
  - Các phần tử trên đường chéo chính = 0.
  - Tổng phần tử trên 1 hàng = bậc ra của đỉnh đó.
  - Tổng phần tử trên ma trận = số cạnh.
  - Tổng phần tử trên 1 cột = bậc vào của đỉnh đó.

- **Ma trận trọng số**:
  - Thay số 1 bằng trọng số của cạnh.
  - Số 0 thay bằng vô cùng.

- **Độ phức tạp**: O(V^2).
- **Ưu điểm**: Dễ cài đặt, truy xuất cạnh nhanh, kiểm tra cạnh nối 2 đỉnh trong O(1).
- **Nhược điểm**: Tốn nhiều bộ nhớ.

### Danh Sách Cạnh (Mật Độ Thưa)

- **Ưu điểm**: Tiết kiệm bộ nhớ, dễ cài đặt, truy xuất cạnh nhanh.
- **Nhược điểm**: Độ phức tạp O(E), không truy xuất đỉnh nhanh, không kiểm tra cạnh nối 2 đỉnh trong O(1).

### Danh Sách Kề (Mật Độ Thưa)

- **Ưu điểm**: Tiết kiệm bộ nhớ, dễ cài đặt, truy xuất đỉnh nhanh, kiểm tra cạnh nối 2 đỉnh trong O(1).
- **Nhược điểm**: Cài đặt khó hơn so với các phương pháp khác.

## Duyệt Đồ Thị

- **BFS (Breadth-First Search)**: Sử dụng hàng đợi (queue).
- **DFS (Depth-First Search)**: Sử dụng ngăn xếp (stack).

## Đường Đi Ngắn Nhất

- **Dijkstra**:
  - Sử dụng 2 mảng.
  - Độ phức tạp: O(V*E).
  - Chỉ tìm được đường đi ngắn nhất giữa 1 đỉnh và đỉnh còn lại.
  - Không dùng được cho đồ thị có chu trình âm.

- **Bellman-Ford**:
  - Sử dụng 1 mảng.
  - Độ phức tạp: O(V*E).
  - Tìm được đường đi ngắn nhất giữa 1 đỉnh và đỉnh còn lại.
  - Có thể dùng cho đồ thị có chu trình âm.

- **Floyd-Warshall**:
  - Sử dụng ma trận.
  - Độ phức tạp: O(V^3).
  - Tìm được đường đi ngắn nhất giữa 2 đỉnh bất kỳ.
  - Các bước thực hiện:
    1. Tạo ma trận kề.
    2. Tạo ma trận trọng số.
    3. Tạo ma trận truy vết.
    4. Tạo ma trận kết quả.

## Cây Khung Nhỏ Nhất (Không Có Nhiều Thành Phần Liên Thông)

- **Kruskal**: Dựa trên việc sắp xếp các cạnh theo trọng số.
- **Prim**: Dựa trên việc chọn đỉnh có trọng số nhỏ nhất.

## Quy Hoạch Động

- Tạo bảng và sử dụng các giá trị đã tính toán để giải quyết bài toán.
