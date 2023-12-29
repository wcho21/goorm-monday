# 증명

0 이상의 숫자들이 있을 때, 짝을 지어 곱한 것의 합이 최대인 경우는 큰 수부터 짝을 지었을 때이다.

숫자 개수가 홀수인 경우, 숫자 0을 추가해 짝수로 만든 경우와 다르지 않다.
따라서 개수가 짝수인 경우만 증명해도 일반성을 잃지 않는다.
개수가 4개인 경우를 베이스 케이스로 증명하고, $k$개가 증명됐을 때 $k+2$개 또한 증명됨을 보일 것이다.



## 베이스 케이스: 4개의 경우

네 개의 숫자 $a_1, a_2, a_3, a_4$가 오름차순, 즉 $a_1 \leq a_2 \leq a_3 \leq a_4$ 이라고 하자.

이 경우, $a_1 a_2 + a_3 a_4$가 최대이다.

예를 들어, $a_1 a_3 + a_2 a_4$와 비교하기 위해 뺄셈을 해보자.
그러면 다음과 같이 0 이상이므로, $a_1 a_2 + a_3 a_4$가 더 크다.

$$
(a_1 a_2 + a_3 a_4) - (a_1 a_3 + a_2 a_4) = (a_4 - a_1)(a_3 - a_2) \geq 0
$$

나머지 경우, 즉 $a_1 a_4 + a_2 a_3$에 대해서도 마찬가지이다.



## 예: 6개의 경우

일반적인 상황을 재귀적으로 증명하기 전에, 구체적인 예를 볼 것이다.

일단 4개의 경우는 위에서 처럼 증명되었다고 하자.

이제 6개의 경우를 볼 것이다.
즉 오름차순으로 늘어놓은 숫자 $a_1 \leq a_2 \leq a_3 \leq a_4 \leq a_5 \leq a_6$ 가 있다고 하자.
그러면 $a_1 a_2 + a_3 a_4 + a_5 a_6$가 최대임을 보일 것이다.

### 다섯 경우에 대한 증명

어떤 숫자든 반드시 짝이 있어야 한다.
가장 낮은 숫자 $a_1$을 기준으로 보자.
그러면 나머지 다섯 숫자 중에 하나를 짝으로 가져야 한다.

그 짝이 $a_2$이라고 하자.
그러면 나머지 $a_3, a_4, a_5, a_6$ 이 남는다.
그런데 이 네 개의 숫자는 이미 $a_3 a_4 + a_5 a_6$가 최대임이 증명되었다.
따라서 이 경우는 $a_1 a_2 + a_3 a_4 + a_5 a_6$가 최대이다.

$a_1$의 짝이 $a_3$이라고 하자.
그러면 나머지 $a_2, a_4, a_5, a_6$ 이 남는다.
이 네 개의 숫자로 만들 수 있는 최대는 $a_2 a_4 + a_5 a_6$ 임이 증명되었다.
따라서 이 경우는 $a_1 a_3 + a_2 a_4 + a_5 a_6$가 최대이다.

한편, 앞 두 항 $a_1 a_3 + a_2 a_4$을 보자.
4개의 경우를 증명할 때 봤던 것 처럼, 이 네 개의 숫자로 만들 수 있는 합은 이것이 최대가 아니라 $a_1 a_2 + a_3 a_4$ 이다.
따라서 이 경우의 합은 최대 이하이다.

$a_1$의 짝이 $a_4$라고 하자.
짝이 $a_3$이었던 방금 전 경우와 똑같다.
즉 $a_1 a_4 + a_2 a_3 + a_5 a_6$이 최대인데, 앞 두 항이 최대 이하이다.

앞서 두 경우는, 맨 뒤 항인 $a_5 a_6$가 제대로 짝 지어졌고, 나머지 네 숫자에 베이스 케이스를 적용할 수 있었다.
한편 남은 두 케이스는 그렇지 않고 따로 증명한다.

$a_1$의 짝이 $a_5$라고 하자.
그러면 숫자 $a_2, a_3, a_4, a_6$ 가 남고, 이 숫자에 대해서는 $a_2 a_3 + a_4 a_6$ 이 최대이다.

이제 뺄셈을 통해, 이 합이 최대 이하, 즉 $a_1 a_2 + a_3 a_4 + a_5 a_6$ 이하임을 보이자.

$$
\begin{alignat}{1}
  & (a_1 a_2 + a_3 a_4 + a_5 a_6) - (a_1 a_5 + a_2 a_3 + a_4 a_6) \\
  = \space & a_1 (a_2 - a_5) + a_3 (a_4 - a_2) + a_6 (a_5 - a_4) \\
  \geq \space & a_1 (a_2 - a_5) + a_1 (a_4 - a_2) + a_6 (a_5 - a_4) \quad (\because a_1 \leq a_3 ) \\
  = \space & (a_6 - a_1) (a_5 - a_4) \\
  \geq \space & 0
\end{alignat}
$$

즉 이 경우 합은 최대 이하이다.

남은 경우, 즉 $a_1$의 짝이 $a_6$인 경우도 위와 비슷하다.
이 경우 만들 수 있는 합의 최대는 $a_1a_6 + a_2a_3 + a_4a_5$이다.
뺄셈을 통해 최대 이하임을 보이자.

$$
\begin{alignat}{1}
    & (a_1 a_2 + a_3 a_4 + a_5 a_6) - (a_1 a_6 + a_2 a_3 + a_4 a_5) \\
  = \space & a_1 (a_2 - a_6) + a_3 (a_4 - a_2) + a_5 (a_6 - a_4) \\
  \geq \space & a_1 (a_2 - a_6) + a_1 (a_4 - a_2) + a_5 (a_6 - a_4) \quad (\because a_1 \leq a_3 ) \\
  = \space & (a_5 - a_1) (a_6 - a_4) \\
  \geq \space & 0
\end{alignat}
$$

위 결과를 종합하면 $a_1 a_2 + a_3 a_4 + a_5 a_6$가 만들 수 있는 최대이다.



## 일반화: 네 개보다 큰 경우

방금의 예시와 같은 형태로 증명할 것이다.

$k-2$ 개의 경우가 증명됐다고 하자.
$k$ 개의 경우를 증명할 것이다.

$k$ 개의 숫자 $a_1 \leq a_2 \leq \dots \leq a_k$ 가 있다고 하자.
이제 $a_1 a_2 + a_3 a_4 + \dots + a_{k-1} a_k$ 가 만들 수 있는 최대의 합임을 보일 것이다.

숫자 $a_1$의 짝을 기준으로 케이스를 나눈다.

$a_1$의 짝이 $a_2$인 경우, 나머지 $k-2$개의 숫자로 만들 수 있는 합은 $a_3 a_4 + a_5 a_6 + \dots + a_{k-1} a_k$ 임이 이미 증명되었다.
즉 $a_1 a_2 + a_3 a_4 + \dots + a_{k-1} a_k$ 가 최대이다.

$a_1$의 짝이 $a_3, a_4, \dots, a_{k-2}$ 중에 하나라고 해보자.
남은 $k-2$ 개의 숫자로 만들 수 있는 최대 합은 무엇인지 증명되었다.
즉 큰 숫자부터 짝 지은 경우가 최대이다.
다시 말해, 어떤 경우든 만들 수 있는 최대 합은 $a_{k-1} a_k$를 포함한다.
그런데 $a_{k-1}, a_k$를 제외한 $k-2$개의 숫자로 만들 수 있는 최대 합은 $a_1 a_2 + a_3 a_4 + \dots + a_{k-3} a_{k-2}$이다.
즉 어떤 경우든 그 합은 $a_1 a_2 + a_3 a_4 + \dots + a_{k-1} a_k$ 이하이다.

$a_1$의 짝이 $a_{k-1}$이라고 하자.
남은 $k-2$ 개의 숫자로 만들 수 있는 합은 $a_2 a_3 + a_4 a_5 + \dots + a_{k-4} a_{k-3} + a_{k-2} a_k$ 가 최대임이 이미 증명되었다.
뺄셈을 통해 이 합이 최대 이하, 즉 $a_1 a_2 + a_3 a_4 + \dots + a_{k-1} a_k$ 이하 임을 보이자.

$$
\begin{alignat}{1}
  & (a_1 a_2 + a_3 a_4 + \dots + a_{k-3} a_{k-2} + a_{k-1} a_k) - (a_1 a_{k-1} + a_2 a_3 + \dots a_{k-4} a_{k-3} + a_{k-2} a_k) \\
  = \space & a_1 (a_2 - a_{k-1}) + a_3 (a_4 - a_2) + \dots + a_{k-3} (a_{k-2} - a_{k-4}) + a_k (a_{k-1} - a_{k-2}) \\
  \geq \space & a_1 (a_2 - a_{k-1}) + a_1 (a_4 - a_2) + \dots + a_1 (a_{k-2} - a_{k-4}) + a_k (a_{k-1} - a_{k-2}) \\
  = \space & a_1 (a_{k-2} - a_{k-1}) + a_k (a_{k-1} - a_{k-2}) \\
  = \space & (a_k - a_1) (a_{k-1} - a_{k-2}) \\
  \geq \space & 0
\end{alignat}
$$

마지막으로 $a_1$의 짝이 $a_k$이라고 하자.
남은 $k-2$ 개의 숫자로 만들 수 있는 합은 $a_2 a_3 + a_4 a_5 + \dots + a_{k-4} a_{k-3} + a_{k-2} a_{k-1}$ 가 최대임이 이미 증명되었다.
아까의 경우처럼, 뺄셈을 통해 이 합이 최대 이하임을 보이자.

$$
\begin{alignat}{1}
  & (a_1 a_2 + a_3 a_4 + \dots + a_{k-3} a_{k-2} + a_{k-1} a_k) - (a_1 a_k + a_2 a_3 + \dots a_{k-4} a_{k-3} + a_{k-2} a_{k-1}) \\
  = \space & a_1 (a_2 - a_k) + a_3 (a_4 - a_2) + \dots + a_{k-3} (a_{k-2} - a_{k-4}) + a_{k-1} (a_k - a_{k-2}) \\
  \geq \space & a_1 (a_2 - a_k) + a_1 (a_4 - a_2) + \dots + a_1 (a_{k-2} - a_{k-4}) + a_{k-1} (a_k - a_{k-2}) \\
  = \space & a_1 (a_{k-2} - a_k) + a_{k-1} (a_k - a_{k-2}) \\
  = \space & (a_{k-1} - a_1) (a_k - a_{k-2}) \\
  \geq \space & 0
\end{alignat}
$$

이렇게 큰 것부터 짝지었을 때가 최대 합이 됨을 보였다.