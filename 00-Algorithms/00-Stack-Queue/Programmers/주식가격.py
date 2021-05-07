def solution(prices):

    answer = []
    for i in range(len(prices)):
        for n in range(i+1, len(prices)+1):
            if n == len(prices):
                answer.append(n-i-1)
            elif prices[n] < prices[i]:
                answer.append(n-i)
                break

    return answer