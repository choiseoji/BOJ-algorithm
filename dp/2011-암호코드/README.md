[풀이]
- 일단 현재 수가 알파벳으로 변환 가능한 수라면 (즉, 0이 아니라면!)
    - 앞에 저장한 경우의 수를 그대로 따라오고
- 현재와 바로 앞 글자를 합쳐서 하나의 알파벳으로 변환 가능하다면 (즉, 앞글자가 1이면 변환 가능하고, 2라면 현재가 6이하여야 함)
    - dp[i - 2] 번째 경우의 수를 위에서 구해준 현재 경우의 수에 추가로 더해줘야 함
    

<계속 틀렸던 이유>

num은 인덱스가 0부터 시작하고,

dp배열은 1부터 시작하는데, dp[i - 2] 를 써야하는 경우 때문에 dp[0]에 dummy로 dp[1]의 값과 같은 1을 저장했었는데

dp배열도 인덱스 0부터 시작하는 것으로 착각해서 문제 푸는데 어려움이 많았다.


[반례]

121074110

정답 : 2


1012

정답 : 2

19126

정답 : 6

111111111111111111111111111111

정답 : 346269