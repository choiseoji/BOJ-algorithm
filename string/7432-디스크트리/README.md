[풀이]
- 예전에 푼 '개미굴'이라는 문제와 비슷한 문제이다.
- 입력받는 부분만 다른데 split 함수를 구현해서 '\'기준으로 split해서 벡터에 담아주면 
- 개미굴과 똑같이 풀 수 있다.

</br>
</br>

[새롭게 알게된 것]

### istringstream

- 문자열을 파싱할 때 사용 (split을 구현하기 위해 사용했다)
- 기본으로는 공백 기준으로 split 해주는 기능을 제공한다
- 우리는 '\'을 기준으로 나눠야 하므로 getline을 통해서 구분자를 제공해주었다.

- 사용 예시

```cpp
#include <iostream>
#include <sstream>
using namespace std;

int main(void)
{
	istringstream s("string 123");
	string s1;
	int n1;

	s >> s1 >> n1;  // 공백 기준으로 split하고 변수 타입에 맞게 변환해 줌
	cout << s1 << "\n" << n1;
}

// 출력결과
// string
// 123
```