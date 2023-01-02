# Flyweight vs Singleton

## flyweight
- 변동성이 낮은 (intrinsic) 데이터를 담은 객체가 중복 생성되어 메모리 손실을 발생시키는 것을 줄이고자, 하나의 복사본을 생성해두어 여러 클라이언트가 접근할 수 있도록 하는 패턴

### 장점
- 동일한 데이터를 서로 다른 여러 객체에 분산시켜놓는 대신 한 곳에서 관리할 수 있음 
- 한 번 객체에 저장된 데이터는 불변하므로 (immutable) 데이터 영속성을 지킬 수 있음 

### 활용 방법
- 데이터를 저장하는 Flyweight 객체를 만들고, 이러한 Flyweight 객체를 검증하고 생성하는 FlyweightFactory 와 결합되어 사용되는 경우가 많다. 
- 코드 예시
```ts
class Flyweight {
    private sharedState: any;

    constructor(sharedState: any) {
        this.sharedState = sharedState;
    }

    public operation(uniqueState): void {
        const s = JSON.stringify(this.sharedState);
        const u = JSON.stringify(uniqueState);
        console.log(`Flyweight: Displaying shared (${s}) and unique (${u}) state.`);
    }
}

// 클라이언트가 요청하는 객체가 이미 존재하면 인스턴스를 반환하고, 존재하지 않으면 새로 생성한다.
class FlyweightFactory {
    private flyweights: {[key: string]: Flyweight} = <any>{};

    constructor(initialFlyweights: string[][]) {
        for (const state of initialFlyweights) {
            this.flyweights[this.getKey(state)] = new Flyweight(state);
        }
    }

    private getKey(state: string[]): string {
        return state.join('_');
    }

    public getFlyweight(sharedState: string[]): Flyweight {
        const key = this.getKey(sharedState);

        if (!(key in this.flyweights)) {
            console.log('FlyweightFactory: Can\'t find a flyweight, creating new one.');
            this.flyweights[key] = new Flyweight(sharedState);
        } else {
            console.log('FlyweightFactory: Reusing existing flyweight.');
        }

        return this.flyweights[key];
    }

    public listFlyweights(): void {
        const count = Object.keys(this.flyweights).length;
        console.log(`\nFlyweightFactory: I have ${count} flyweights:`);
        for (const key in this.flyweights) {
            console.log(key);
        }
    }
}

const factory = new FlyweightFactory([
    ['Chevrolet', 'Camaro2018', 'pink'],
    ['Mercedes Benz', 'C300', 'black'],
    ['Mercedes Benz', 'C500', 'red'],
    ['BMW', 'M5', 'red'],
    ['BMW', 'X6', 'white'],
    // ...
]);
factory.listFlyweights();
// ...

function addCarToPoliceDatabase(
    ff: FlyweightFactory, plates: string, owner: string,
    brand: string, model: string, color: string,
) {
    console.log('\nClient: Adding a car to database.');
    const flyweight = ff.getFlyweight([brand, model, color]);

    // brand, model, color 는 intrinsic data
    // plates, owner 는 extrinsic data 
    flyweight.operation([plates, owner]);
}

addCarToPoliceDatabase(factory, 'CL234IR', 'James Doe', 'BMW', 'M5', 'red');

addCarToPoliceDatabase(factory, 'CL234IR', 'James Doe', 'BMW', 'X1', 'red');

factory.listFlyweights();
````

## Singleton 과의 차이점
- Singleton 은 global 변수와 같이, 전역에서 접근할 수 있는 하나의 인스턴스. 데이터가 변할 수 있음 (mutable)
- Flyweight 는 각자 고유한 데이터를 가진, 불변하는 여러 개의 객체
- ex) 전역에서 사용하는 "나무" 객체 ==> Singleton
- ex) 여러 클래스에서 데이터에 접근하여 사용하는 "빨간 나무", "파랑 나무", "초록 나무" 등의 유일하고 고유한 객체 ==> Flyweight