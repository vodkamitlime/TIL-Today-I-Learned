# MongoDB Aggregation

## MongoDB 에서의 Aggregation 이란?
- Aggregate 의 사전적 의미는 집합, 합계, 집계 등을 포괄한다. 
- MongoDB 쿼리 중 Aggregation query 역시, 여러 개의 작업을 하나의 pipeline 으로 연결하여 수행한다. 
- Aggregation 을 통해 여러 개의 document 내의 데이터를 그룹화 하여 하나의 결과로 반환할 수 있다. 

## Aggregation 을 잘 쓰는 법
- 기고글 데이터 중, 특정 status code 를 갖는 것들만 추출한 뒤 나온 결과에 대해 join 을 수행하고 싶다고 가정하자. Aggregation 을 사용하지 않는다면 contributions collection 에서 find 쿼리를 먼저 수행한 뒤, join 을 수행하고자 하는 다른 collection 들에도 연속적인 쿼리를 날려야 할 것이다. 
- Aggregation 을 활용한다면, 이 모든 작업을 한 번에 수행할 수 있게 된다. 

```js
Contribution.aggregate([ 
        {
            $match: {
                status: {
                    $in: [ 110, 111 ]
                }
            }
        }, 
        {
            $lookup: {
                from: "users",
                localField: "user_email",
                foreignField: "user_email",
                as: "user_info"
            }
        },
        {
            $project: {
                contribution_id: 1,
                contribution_keyword: 1,
                contribution_title: 1,
                contribution_url: 1,
                contribution_content:1,
                contribution_date: 1,
                status: 1,
                hit: 1,
                user_name: { $arrayElemAt: [ "$user_info.user_name", 0 ] },
                _id: 0
            }
        },
        {
            $sort: {
                contribution_date: -1
            }
        },
    ])
```
- Aggregation pipeline 의 핵심은, 데이터를 여러 단계로 구성된 하나의 통로를 통과하게 함으로써 각 단계별 조건에 맞추어 필터링을 한다는 것이다. 그리고 그 결과로 '하나의 통합된 결과'를 반환한다.

### 참고자료
- [MongoDB](https://docs.mongodb.com/manual/aggregation/)