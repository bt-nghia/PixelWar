1. Cài đặt và sử dụng:
- Sử dụng lệnh git clone để clone game về máy
  <git clone https://github.com/bt-nghia/laptrinhnangcao.git>

- game ở thư mục pixelwar

- Ở terminal 
 Nhập lệnh: <cd pixelwar> để dẫn đến thư mục chứa file game
 Nhập lệnh: <mingw32-make> để dịch lại toàn bộ game
 Nhập lệnh: <.\main> để bắt đầu trò chơi

2. Mô tả:
- Ở phần menu:
  Ấn phím <p> để chơi ấn phím <q> để thoát khỏi trò chơi

- Trong trò chơi:
  chúng ta điều khiển một hiệp sĩ đi tiêu diệt quái vật thu thập các chìa khóa để mở rương, quái vật sẽ cach bảo vệ các hòm.

  Điều khiển di chuyển lên xuông trái phải bằng các phím mũi tên trên bàn phím
  Tấn công quái vật bằng phím <SPACE>

- Khi có chìa khóa chúng ta có thể ra cửa và dành chiến thắng (hoặc qua một map/level tiếp theo)
  Mở các hòm kho báu để thu thập sinh mệnh 
  Mỗi khi chúng ta chạm vào quái vật sẽ mất đi một điểm sinh mệnh 
  nếu điểm sinh mệnh là 0 chúng ta sẽ thua nếu full sinh mệnh
  thì ta được +100 điểm, tiêu diệt 1 quái vật +100 điểm

3. Minh họa:
- chức năng di chuyển nhân vật bằng phím mũi tên
  tấn công bằng phím space tấn công giết chết 1 quái vật sẽ được thêm 100 điểm
  nhân vật chạm tường thì không thể di chuyển
  nhân vật chạm quái vật mà nếu đang trong lúc không tấn công thì sẽ -1 sinh mệnh thanh sinh mệnh mất 1 máu chạm vào chìa khóa chìa khóa thêm 1
  nếu có chìa khóa có thể mở rương (sinh mệnh mà chư full thì được +1 điểm sinh mệnh) hoặc cộng 100 điểm 
  có chìa khóa chúng ta có thể đi đên cửa và chiến thắng

  ( link youtube : https://www.youtube.com/watch?v=3NUqOZNr5Po&ab_channel=nghiabui )

4. KĨ thuật lập trình:
- sử dụng thư viện SDL.h, render ảnh theo lớp, nhân vật bằng thư viện SDL_image

- làm cho nhân vật chuyển động với các hoạt ảnh khác nhau một hoạt ảnh dài
  ta có thể sử dụng các tọa độ của ảnh để render từng phần 1 để cho nhan vật 
  sinh động

- chia chương trình thành nhiều file con nhỏ để mỗi file có một chức năng riêng thuận tiện cho việc lập trình và sửa lỗi

- sử dụng các template, lớp cấu trúc, các biến static, con trỏ, xử lí khi 2 vật thể va chạm bằng tọa độ

- sử dụng cấu trúc vector nạp chồng toán tử để dễ hình dung thuận tiện cho việc lập trình, sử dụng con trỏ, quản lý các thực thể bằng 1 vector con trỏ

- làm quen với dữ liệu private, friend fuction, variadic function(1 hàm cho phép truyền nhiều kiểu tham số vào hàm), cách lấy dữ liệu từ private bằng cách viết 1 hàm
lấy dữ liệu từ public để sử dụng ngoài class

5. Kết luận và hướng phát triển:
- đây mới chỉ là một trò chơi chưa hoàn chỉnh:
  dự định sẽ phát triển thêm map mới, quái vật có thể di chuyển tấn công người chơi khó đoán hơn, hiển thị điểm số lên màn hình, tối ưu bộ nhớ, quản lý lại các thực
  thể vì thi thoảng chạy chương trình vẫn có lỗi phát sinh, làm thêm high score lưu vào file txt

- Rút ra:
 Sử dụng các class tự định nghĩa được một kiểu dữ liệu cách chia chương trình thành nhiều file nhỏ cách tối ưu bộ nhớ tốc độ bằng con trỏ sử dụng tọa độ để xử lý các
  va chạm, sử dụng git để lưu trữ src code.
 Cách tra mạng tham khảo tài liệu và sử dụng những gì mình cần để áp dụng vào chương trình của mình 
 ( NGUỒN THAM KHẢO CỦA https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&ab_channel=Let%27sMakeGames, một vài cách gỡ lỗi tìm được 
  trên stack over flow etc..)
