<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../source.css">

<h1 style="text-align:center">TypeORM - EntityManager API</h1>

<h3 class="h3color">dataSource</h3>
dataSource - The DataSource used by EntityManager.

```ts
const dataSource = manager.dataSource
```
0
<h3 class="h3color">queryRunner</h3>
The query runner used by EntityManager. Used only in transactional instances of EntityManager.

```ts
const queryRunner = manager.queryRunner
```

<h3 class="h3color">transaction</h3>
transaction - Provides a transaction where multiple database requests will be executed in a single database transaction. Learn more Transactions.

```ts
await manager.transaction(async (manager) => {
    // NOTE: you must perform all database operations using the given manager instance
    // it's a special instance of EntityManager working with this transaction
    // and don't forget to await things here
})
```

<h3 class="h3color">query</h3>
Executes a raw SQL query.

```ts
const rawData = await manager.query(`SELECT * FROM USERS`)
```

<h3 class="h3color">createQueryBuilder</h3>
Creates a query builder use to build SQL queries. Learn more about QueryBuilder.

```ts
const users = await manager
    .createQueryBuilder()
    .select()
    .from(User, "user")
    .where("user.name = :name", { name: "John" })
    .getMany()
```

<h3 class="h3color">hasId</h3>
Checks if given entity has its primary column property defined.

```ts
if (manager.hasId(user)) {
    // ... do something
}
```

<h3 class="h3color">getId</h3>
Gets given entity's primary column property value. If the entity has composite primary keys then the returned value will be an object with names and values of primary columns.

```ts
const userId = manager.getId(user) // userId === 1
```

<h3 class="h3color">create</h3>
Creates a new instance of User. Optionally accepts an object literal with user properties which will be written into newly created user object.

```ts
const user = manager.create(User) // same as const user = new User();
const user = manager.create(User, {
    id: 1,
    firstName: "Timber",
    lastName: "Saw",
}) // same as const user = new User(); user.firstName = "Timber"; user.lastName = "Saw";
```

<h3 class="h3color">merge</h3>
Merges multiple entities into a single entity.

```ts
const user = new User()
manager.merge(User, user, { firstName: "Timber" }, { lastName: "Saw" }) 
// same as user.firstName = "Timber"; user.lastName = "Saw";
```

<h3 class="h3color">preload</h3>
preload - Creates a new entity from the given plain javascript object. If the entity already exist in the database, then it loads it (and everything related to it), replaces all values with the new ones from the given object, and returns the new entity. The new entity is actually loaded from the database entity with all properties replaced from the new object.

```ts
const partialUser = {
    id: 1,
    firstName: "Rizzrak",
    profile: {
        id: 1,
    },
}
const user = await manager.preload(User, partialUser)
// user will contain all missing data from partialUser with partialUser property values:
// { id: 1, firstName: "Rizzrak", lastName: "Saw", profile: { id: 1, ... } }
```

<h3 class="h3color">save</h3>
save - Saves a given entity or array of entities. If the entity already exists in the database, then it's updated. If the entity does not exist in the database yet, it's inserted. It saves all given entities in a single transaction (in the case of entity manager is not transactional). Also supports partial updating since all undefined properties are skipped. In order to make a value *NULL*, you must manually set the property to equal null.

```ts
await manager.save(user)
await manager.save([category1, category2, category3])
```

<h3 class="h3color">remove</h3>
remove - Removes a given entity or array of entities. It removes all given entities in a single transaction (in the case of entity, manager is not transactional).

```ts
await manager.remove(user)
await manager.remove([category1, category2, category3])
```

<h3 class="h3color">insert</h3>
insert - Inserts a new entity, or array of entities.

```ts
await manager.insert(User, 
    { firstName: "Timber", lastName: "Timber",}
)

await manager.insert(User, [
    { firstName: "Foo", lastName: "Bar", },
    { firstName: "Rizz", lastName: "Rak", },
])
```

<h3 class="h3color">update</h3>
update - Partially updates entity by a given update options or entity id

```ts
await manager.update(User, { firstName: "Timber" }, { firstName: "Rizzrak" })
// executes UPDATE user SET firstName = Rizzrak WHERE firstName = Timber

await manager.update(User, 1, { firstName: "Rizzrak" })
// executes UPDATE user SET firstName = Rizzrak WHERE id = 1
```

<h3 class="h3color">upsert</h3>
upsert - Inserts a new entity or array of entities unless they already exist in which case they are updated instead. Supported by AuroraDataApi, Cockroach, Mysql, Postgres, and Sqlite database drivers.

```ts
await manager.upsert(
    User,
    [
        { externalId: "abc123", firstName: "Rizzrak" },
        { externalId: "bca321", firstName: "Karzzir" },
    ],
    ["externalId"],
)
/** executes
 *  INSERT INTO user
 *  VALUES
 *      (externalId = abc123, firstName = Rizzrak),
 *      (externalId = cba321, firstName = Karzzir),
 *  ON CONFLICT (externalId) DO UPDATE firstName = EXCLUDED.firstName
 **/
```

<h3 class="h3color">delete</h3>
delete - Deletes entities by entity id, ids or given conditions:

```ts
await manager.delete(User, 1)
await manager.delete(User, [1, 2, 3])
await manager.delete(User, { firstName: "Timber" })
```

<h3 class="h3color">increment</h3>
increment - Increments some column by provided value of entities that match given options.

```ts
await manager.increment(User, { firstName: "Timber" }, "age", 3)
```

<h3 class="h3color">decrement</h3>
decrement - Decrements some column by provided value that match given options.

```ts
await manager.decrement(User, { firstName: "Timber" }, "age", 3)
```

<h3 class="h3color">count</h3>
count - Counts entities that match FindOptions. Useful for pagination.

```ts
const count = await manager.count(User, {
    where: {
        firstName: "Timber",
    },
})
```

<h3 class="h3color">countBy</h3>
countBy - Counts entities that match FindOptionsWhere. Useful for pagination.

```ts
const count = await manager.countBy(User, { firstName: "Timber" })
```

<h3 class="h3color">find</h3>
find - Finds entities that match given FindOptions.

```ts
const timbers = await manager.find(User, {
    where: {
        firstName: "Timber",
    },
})
```

<h3 class="h3color">findBy</h3>
findBy - Finds entities that match given FindWhereOptions.

```ts
const timbers = await manager.findBy(User, {
    firstName: "Timber",
})
```

<h3 class="h3color">findAndCount</h3>
findAndCountBy - Finds entities that match given FindOptionsWhere. Also counts all entities that match given conditions, but ignores pagination settings (from and take options).

```ts
const [timbers, timbersCount] = await manager.findAndCount(User, {
    firstName: "Timber",
})
```

<h3 class="h3color">findAndCountBy</h3>
findAndCountBy - Finds entities that match given FindOptionsWhere. Also counts all entities that match given conditions, but ignores pagination settings (from and take options).

```ts
const [timbers, timbersCount] = await manager.findAndCount(User, {
    firstName: "Timber",
})
```

<h3 class="h3color">findOne</h3>
findOne - Finds the first entity that matches given FindOptions.

```ts
const timber = await manager.findOne(User, {
    where: {
        firstName: "Timber",
    },
})
```

<h3 class="h3color">findOneBy</h3>
findOneBy - Finds the first entity that matches given FindOptionsWhere.

```ts
const timber = await manager.findOne(User, { firstName: "Timber" })
```

<h3 class="h3color">findOneOrFail</h3>
findOneOrFail - Finds the first entity that matches some id or find options. Rejects the returned promise if nothing matches.

```ts
const timber = await manager.findOneOrFail(User, {
    where: {
        firstName: "Timber",
    },
})
```

<h3 class="h3color">clear</h3>
clear - Clears all the data from the given table (truncates/drops it).

```ts
await manager.clear(User)
```

<h3 class="h3color">getRepository</h3>
getRepository - Gets Repository to perform operations on a specific entity. Learn more about Repositories.

```ts
const userRepository = manager.getRepository(User)
```

<h3 class="h3color">getTreeRepository</h3>
getTreeRepository - Gets TreeRepository to perform operations on a specific entity. Learn more about Repositories.

```ts
const categoryRepository = manager.getTreeRepository(Category)
```

<h3 class="h3color">withRepository</h3>
withRepository - Gets custom repository instance used in a transaction. Learn more about Custom repositories.

```ts
const myUserRepository = manager.withRepository(UserRepository)
```

<h3 class="h3color">release</h3>
release - Releases query runner of an entity manager. Used only when query runner was created and managed manually.

```ts
await manager.release()
```



