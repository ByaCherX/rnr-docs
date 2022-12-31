<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../source.css">

<h1 style="text-align:center">TypeORM - Caching queries</h1>

You can cache results selected by these QueryBuilder methods: ``getMany``, ``getOne``, ``getRawMany``, ``getRawOne`` and ``getCount``.

You can also cache results selected by find* and count* methods of the Repository and EntityManager.

To enable caching you need to explicitly enable it in data source options:
```ts
{
    type: "mysql",
    host: "localhost",
    username: "test",
    ...
    cache: true
}
```

Then in QueryBuilder you can enable query cache for any query:
```ts
const users = await dataSource
    .createQueryBuilder(User, "user")
    .where("user.isAdmin = :isAdmin", { isAdmin: true })
    .cache(true)
    .getMany()
```

Equivalent Repository query:
```ts
const users = await dataSource.getRepository(User).find({
    where: { isAdmin: true },
    cache: true,
})
```

You can change cache time manually via ``QueryBuilder``:
```ts
const users = await dataSource
    ...
    .cache(60000) // 1 minute
```

Or via Repository:
```ts
const users = await dataSource.getRepository(User).find({
    ...
    cache: 60000,
})
```




















