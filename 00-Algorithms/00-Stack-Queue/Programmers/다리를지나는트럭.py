from collections import deque

def solution(bridge_length, weight, truck_weights):
    on_bridge = deque([0 for n in range(bridge_length)])
    truck_weights = deque(truck_weights)
    time = 0
    while True:
        if truck_weights:  # 만약 truck_weights 에 트럭이 남아있다면
            on_bridge.popleft()
            if sum(on_bridge) + truck_weights[0] <= weight:  # 다리 위 트럭에 더 올릴 수 있으면 하나 추
                on_bridge.append(truck_weights.popleft())
            else:
                on_bridge.append(0)
        else:  # 만약 truck_weights 에 트럭이 남아있지 않다면
            time += len(on_bridge)
            break
        time += 1
    return time