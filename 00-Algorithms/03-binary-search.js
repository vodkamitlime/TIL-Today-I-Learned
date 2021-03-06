// 이진탐색 : 정렬되어 있는 리스트에서 탐색 범위를 절반씩 좁혀가며 데이터를 탐색하는 방법
// 이진 탐색은 매우 빠른 속도로 데이터를 찾을 수 있지만 반드시 데이터가 정렬되어있어야만 한다
// 시간복잡도:O(logN)

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