# parkingtowersystem_project

## 주차 타워의 입차, 출차를 제어하는 시스템 디바이스

### Text LCD

![1](https://user-images.githubusercontent.com/29852523/29558696-dfff0bc4-8767-11e7-9390-7eea5f6345c8.png)

 Text를 출력하는 Device이다. 
 Parking Tower System에서는 입차 및 출차 시 차량정보 출력,
 경고 메세지 출력 그리고 사용자 입력정보 를 확인을 하는데 사용된다. 

### Variable Register

![2](https://user-images.githubusercontent.com/29852523/29558695-dffc7364-8767-11e7-9605-1bad5469e901.png)

 회로에서 저항 값을 제어 하는 device이다. 
 저항의 값에 따라서 출력되는 전압 량이 달라지므로,
 전압 량을 이용해서 차량의 크기 정보를 선택하도록 사용하였다.


### LED

![3](https://user-images.githubusercontent.com/29852523/29558697-e0011392-8767-11e7-80b1-c90bcc188c45.png)

8개의 LED를 통해서 입력된 정보를 출력하는 device이다. 
Parking Tower System에서는 명령 진행상태를 나타낸다.


### 7-SEGMENT

![4](https://user-images.githubusercontent.com/29852523/29558698-e005ed68-8767-11e7-9ca8-bac15dafa248.png)

7-segment는 숫자를 출력하는 Device이다. 
Parking Tower System에서는 차량번호를 입력하는 경우에 
차량정보를 출력하는 용도로 사용한다. 

### Piezo & Vibrator

![5](https://user-images.githubusercontent.com/29852523/29558699-e02ee6b4-8767-11e7-8639-59f5ef3824a2.png)

 각 Divice 특성에 따라, 소리와 진동발생 작동을 한다. 
 Parking Tower System에서는 경고 상황에서의 알림, 입/출차 완료알림, 
 System on/off등을 알리는 기능으로 사용한다.


### CDS

![6](https://user-images.githubusercontent.com/29852523/29558700-e03550a8-8767-11e7-82e0-dbc19aa157a2.png)

Cadmium sulfide 셀이다. 빛을 받으면 저항이 줄어드는 기능을 한다.
Parking Tower System에서는 출차 진행과정에서 일정 밝기 이하가 되는 경우에, 
경고 상태를 인지하는 기능을 한다. 



### 개발일정


