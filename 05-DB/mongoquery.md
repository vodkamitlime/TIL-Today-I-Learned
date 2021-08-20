몽고DB 쿼리

aggregation 잘 쓰는 법

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