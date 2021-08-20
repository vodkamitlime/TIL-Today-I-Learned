function binarySearch (target, dataArray) {
    let low = 0;
    let high = dataArray.length - 1;
    while (low <= high) {
        let mid = Math.floor((high + low) / 2);
        let guess = dataArray[mid];
        if (guess === target) {
            return guess;
        } else if (guess > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return undefined;
}

  // 출처: https://im-developer.tistory.com/126 [Code Playground]