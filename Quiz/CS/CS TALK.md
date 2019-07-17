# CS TALK 퀴즈 준비



## 7/7

1. 아는 디자인 패턴 다 얘기해보고 설명해보시오

   - __MVC__ : Model, View, Controller의 약자. 사용자가 Controller를 조작하면 controller는 model을 통해서 데이터를 가져오고 그 정보를 바탕으로 시각적인 표현을 담당하는 View를 제어해서 사용자에게 전달한다.
     - Model : __애플리케이션의 정보, 데이터를 나타낸다. 데이터베이스, 처음에 정의하는 상수, 초기화값, 변수 등을 뜻함.__ 또한 이러한 데이터, 정보들의 가공을 책임지는 컴포넌트를 말한다.
       1. __사용자가 편집하기를 원하는 모든 데이터를 가지고 있어야 한다__ : 즉, 화면안의 네모박스에 글자가 표현된다면, 네모박스의 화면 위치 정보, 네모 박스의 크기 정보, 글자 내용, 글자의 위치, 글자의 포맷 정보등을 가지고 있어야 한다.
       2. __뷰나 컨트롤러에 대해서 어떤 정보도 알지 말아야 한다__ : 데이터 변경이 일어났을 때 모델에서 화면 UI를 직접 조정해서 수정할 수 있도록 뷰를 참조하는 내부 속성값을 가지면 안된다.
       3. __변경이 일어나면, 변경 통지에 대한 처리방법을 구현해야 한다__ : 모델의 속성 중 텍스트 정보가 변경되면, 이벤트를 발생시켜 누군가에게 전달해야 하며, 누군가 모델을 변경하도록 요청하는 이벤트를 보냈을 때 이를 수신할 수 있는 처리 방법을 구현해야 한다. 또한 모델은 재사용가능해야 하며 다른 인터페이스에서도 변하지 않아야 한다.
     - View : __input 텍스트, 체크박스 항목 등과 같은 사용자 인터페이스 요소를 나타낸다. 다시 말해 데이터 및 객체의 입력, 그리고 보여주는 출력을 담당한다. 데이터를 기반으로 사용자들이 볼 수 있는 화면이다.__
       1. __모델이 가지고 있는 정보를 따로 저장해서는 안된다__ : 화면에 글자를 표시하기 위해 모델이 가지고 있는 정보를 전달받게 될텐데, 그 정보를 유지하기 위해서 임의의 뷰 내부에 저장하면 안된다. 단순히 네모 박스를 그리라는 명령을 받으면, 화면에 표시하기만 하고 그 화면을 그릴 때 필요한 정보들은 저장하지 않아야 한다.
       2. __모델이나 컨트롤러와 같이 다른 구성요소들을 몰라야 된다__ : 모델과 같이 변경이 일어났을 때 이를 누군가에게 변경을 알려줘야 하는 방법을 구현해야 한다. 뷰에서는 화면에서 사용자가 화면에 표시된 내용을 변경하게 되면 이를 모델에게 전달해서 모델을 변경해야 할 것이다. 그 작업을 하기 위해서 변경 통지를 구현한다. 그리고 재사용 가능하게끔 설계를 해야하며 다른 정보들을 표현할 때 쉽게 설계를 해야한다.
       3. __변경이 일어나면 변경통지에 대한 처리방법을 구현해야만 한다__ : 모델과 같이 변경이 일어났을 때 이를 누군가에게 변경을 알려줘야 하는 방법을 구현해야 한다. 뷰에서는 화면에서 사용자가 화면에 표시된 내용을 변경하게 되면 이를 모델에게 전달해서 모델을 변경해야 할 것이다. 그 작업을 하기 위해서 변경 통지를 구현한다. 그리고 재사용 가능하게끔 설계를 해야하며 다른 정보들을 표현할 때 쉽게 설계를 해야한다.
     - Controller : 데이터와 사용자 인터페이스 요소들을 잇는 다리역할을 한다. 즉, 사용자가 데이터를 클릭하고, 수정 하는 것에 대한 '이벤트'들을 처리하는 부분
       1. __모델이나 뷰에 대해서 알고 있어야 한다__ : 모델이나 뷰는 서로의 존재를 모르고, 변경을 외부로 알리고, 수신하는 방법만 가지고 있는데 이를 컨트롤러가 중재하기 위해 모델과 그에 관련된 뷰에 대해서 알고 있어야 한다.
       2. __모델이나 뷰의 변경을 모니터링 해야 한다__ : 모델이나 뷰의 변경 통지를 받으면 이를 해석해서 각각의 구성 요소에게 통지를 해야 한다. 또한, 애플리케이션의 메인 로직은 컨트롤러가 담당하게 된다.
   - Singleton : 인스턴스(객체)를 하나만 쓰게 하기 위함
   - Strategy :
   - Factory :

2. 객체지향과 절차지향 언어의 특징

   - 객체지향
     - 추상화 : 구체적인 사물들의 공통적인 특징을 파악해서 이를 하나의 개념(집합)으로 다루는 것
     - 캡슐화 : 객체 외부에서 내부 데이터에 직접적으로 접근이 불가, 외부에서 접근할 수 있도록 정의된 메소드를 통해서만 가능. (정보은닉)
     - 상속 : 이미 작성된 클래스를 이어 받아 새로운 클래스를 생성. 코드의 재활용성
     - 다형성 : 같은 모양의 코드가 다른 동작을 한다(오버로딩, 오버라이딩)
     - __모듈들을 먼저 설계한 다음에 이들의 실행순서와 흐름을 짜는 방식__

   - 절차지향
     - 순서적인 처리가 중요
     - 프로그램 전체가 유기적으로 연결 -> 코드의 순서가 바뀌면 동일한 결과를 보장하기 어려움
     - 빠른 실행속도
     - 유지보수 어려움
     - __프로그램의 순서와 흐름을 먼저 세우고 필요한 자료구조와 함수들을 설계하는 방식__

3. Call by Reference와 Call by Value의 차이

   - Call by Value
     - 함수가 호출될 때, 메모리 공간 안에서는 함수를 위한 별도의 임시 공간이 생성된다.
     - 함수 호출시 인자로 전달되는 변수의 값을 복사하여 함수의 인자로 전달한다.
     - 복사된 인자는 함수 안에서 지역적으로 사용되는 local value의 특성을 가진다.
     - 따라서 함수 안에서 인자의 값이 변경되어도, 외부의 변수의 값은 변경되지 않는다.
   - Call by Reference
     - 함수가 호출 될 때, 메모리 공간 안에서는 함수를 위한 별도의 임시 공간이 생성된다.
     - 함수 호출시 인자로 전달되는 변수의 reference를 전달한다. (해당 변수 가르키고 있는)
     - 따라서 함수 안에서 인자의 값이 변경되면, 인자로 전달된 변수의 값도 함께 변경된다.

___



## 7월 14일

1. 다중 스레드 환경에서의 싱글톤 패턴의 문제점과 해결방법을 설명해보시오.

   - 두 개 이상의 스레드가 인스턴스를 획득하기 위해 getPrinter() 메서드에 진입하여 경합을 벌이는 과정에서 서로 다른 두 개의 인스턴스가 만들어지는 형태가 발생할 여지가 있다.

     - 해결방법1) 인스턴스를 필요할 때 생성하지 않고, 처음부터 인스턴스를 만들어 버린다. 단, 인스턴스를 미리 만들어 버리게 되면, 불필요한 시스템 리소스를 낭비할 가능성이 있다.

       ```java
       public class Singleton() {
           private static Singleton ourInstance = new Singleton();
           
           public static Singleton getInstance() {
               return ourInstance;
           }
           private Singleton() {}
       }
       ```

     - 해결방법2) getInstance() 메소드를 동기화 시킨다. 대신 메소드를 동기화 시키면 일반적으로 성능이 100배 정도는 저하된다.

       ```java
       class Singleton {
           private static Singleton ourInstance = null;
           
           public synchronized static Singleton getInstance() {
               if(ourInstance == null)
                   ourInstance = new Singleton();
               return ourInstance;
           }
       }
       ```

     - 해결방법3) LazyHolder 기법으로 synchronized도 필요 없고, 자바 버전도 상관없는 방법으로, Singleton 클래스의 getInstance() 메소드에서 LazyHolder.INSTANCE를 참조하는 순간 Class가 로딩되며 초기화가 진행된다. Class를 로딩하고 초기화하는 시점은 thread-safe를 보장하기 때문에 volatile이나 synchronized같은 키워드가 없어도 된다.

       ```java
       class Singleton() {
           private Singleton() {}
           
           public static Singleton getInstance() {
               return LazyHolder.INSTANCE;
           }
           
           private static class LazyHolder {
               private static final Singleton INSTANCE = new Singleton();
           }
       }
       ```

2. 프로세스 생성 과정에 대해서 설명해보세요

   - PCB가 생성되며 OS가 실행한 프로그램의 코드를 읽어들여 프로세스에 할당된 메모리의 Text segment에 저장한다.
   - 초기화된 전역 변수 및 static 변수를 data segment에 할당
   - 힙과 스택은 초기 메모리 주소만 초기화됨
   - PCB에 여러 정보가 기록되면 Ready Queue에서 CPU를 할당받기까지 대기한다.

3. 브라우저에서 주소창에 url 입력시 어떤 일이 일어나는가?
   - 브라우저의 주소창에 url 입력
   - 브라우저 캐시에서 DNS 레코드를 확인하여 IP주소를 찾음(없다면 DNS resolver를 통해 IP주소를 알아냄)
   - 브라우저가 서버와 TCP 연결을 시작함
   - 브라우저가 웹 서버에 HTTP 요청을 보냄
   - 서버가 요청을 처리하고 응답을 되돌려 보냄
   - 브라우저는 서버가 보낸 HTML 내용을 표시



___



## 7월 21일

1. TCP와 UDP 차이점

   - TCP와 UDP 프로토콜은 모두 전송계층(Transport Layer)에서 동작하는 프로토콜이다.

   - TCP

     - 신뢰성있는 데이터 전송을 지원하는 연결지향형 프로토콜이다.
     - 패킷을 성공적으로 전송하면 Acknowledgement(ACK)라는 신호를 날린다. 만일 ACK 신호가 제 시간에 도착하지 않으면 Timeout이 발생하여, 패킷 손실이 발생한 패킷에 대해 다시 전송해준다. => 신뢰성 데이터 전송 방법
     - __3-way handshaking__
     - 흐름제어와 혼잡제어를 지원하며 데이터의 순서를 보장.
     - UDP에 비해 속도가 느림
       => 웹 HTTP 통신, 이메일, 파일전송에 사용됨.

   - UDP

     - 비연결형 프로토콜
     - TCP와 달리 연결 설정 없음.
     - 혼잡 제어를 하지 않기 때문에 TCP보다 빠르다.
     - 데이터 전송에 대한 보장을 하지 않기 때문에 패킷 손실이 발생할 수 있음.
       => DNS, 멀티미디어에서 사용됨.
     - 헤더에 있는 Checksum 필드를 통해 최소한의 오류는 검출한다.

   - 비교 표

     |                             TCP                              | UDP                                                       |
     | :----------------------------------------------------------: | --------------------------------------------------------- |
     |     Connection-oriendted protocol (연결지향형 프로토콜)      | Connection-less protocol (비 연결지향형 프로토콜)         |
     |    Connection by byte stream (바이트 스트림을 통한 연결)     | Connection by message stream (메시지 스트림을 통한 연결)  |
     |    congestion control, flow control (혼잡제어, 흐름제어)     | X                                                         |
     |      ordered, lower speed (순서 보장, 상대적 속도 느림)      | not ordered, higher speed (순서 보장x, 상대적 속도 빠름)  |
     | reliable data transmission (신뢰성 있는 데이터 전송, 안정적) | unreliable data transmission (데이터 전송 보장 x)         |
     |      TCP packet : segment (데이터 전송 단위는 세그먼트)      | UDP packet : datagram (데이터 전송 단위는 데이터 그램)    |
     |                  HTTP, Email, File transfer                  | DNS, Boradcasting (도메인, 실시간 동영상 서비스에서 사용) |

2. Quick Sort 설명

   - 배열에 있는 수 중 사용자가 지정한 규칙대로 임의의 pivot을 잡고, 해당 pivot을 기준으로 작거나 같은 수를 왼쪽 파티션, 큰 수를 오른쪽 파티션으로 보내고 다시 왼쪽 파티션 구간에 한하여 pivot을 잡고 파티션을 나누고 오른쪽 파티션 구간에서도 pivot을 잡고 파티션을 나누는 과정을 반복하여 정렬시키는 정렬 알고리즘이다.

   - pivot을 해당 구간의 중앙값으로 잘 설정하면 merge sort와 같은 시간 복잡도인 O(nlogn)에 수행할 수 있지만, 만약 매 케이스마다 구간의 가장 큰 값이나 가장 작은 값으로 나눠버리면 O(n^2)의 수행시간을 갖게 된다.

   - 코드

     ~~~c++
     void quickSort(int *arr, int left, int right) {
         int pivot = arr[left];
         int left_temp = left;
         int right_temp = right;
         
         while(left < right) {
             while(arr[right] >= pivot && (left < right))
                 right--;
             
             if(left != right)
                 arr[left] = arr[right];
             
             while(arr[left] <= pivot && (left < right))
                 left++;
             
             if(left != right) {
                 arr[right] = arr[left];
                 right--;
             }
         }
         
         arr[left] = pivot;
         pivot = left;
         left = left_temp;
         right = right_temp;
         if(left < pivot) quickSort(arr, left, pivot-1);
         if (right > pivot) quickSort(arr, pivot+1, right);
     }
     ~~~