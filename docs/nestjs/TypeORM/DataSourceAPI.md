<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../source.css">

<h1 style="text-align:center">TypeORM - Data Source API </h1>

<h3 class="h3color">options</h3>
Options used to create this dataSource. Learn more about DataSourceOptions.

```ts
const dataSourceOptions: DataSourceOptions = dataSource.options 
```

<h3 class="h3color">isInitialized</h3>
Indicates if DataSource was initialized and initial connection / connection pool with database was established or not.

```ts
const isInitialized: boolean = dataSource.isInitialized
```

<h3 class="h3color">driver</h3>
Underlying database driver used in this dataSource.

```ts
const driver: Driver = dataSource.driver
```

<h3 class="h3color">manager-EntityManager</h3>
used to work with entities. Learn more about Entity Manager and Repository.

```ts
const manager: EntityManager = dataSource.manager
// you can call manager methods, for example find:
const users = await manager.find()
```

<h3 class="h3color">initialize</h3>
Initializes data source and opens connection pool to the database.

```ts
await dataSource.initialize()
```

<h3 class="h3color">destroy</h3>
Destroys the DataSource and closes all database connections. Usually, you call this method when your application is shutting down.

```ts
await dataSource.destroy()
```

<h3 class="h3color">synchronize</h3>
Synchronizes database schema. When synchronize: true is set in data source options it calls this method. Usually, you call this method when your application is starting.

```ts
await dataSource.synchronize()
```

<h3 class="h3color">dropDatabase</h3>
Drops the database and all its data. Be careful with this method on production since this method will erase all your database tables and their data. Can be used only after connection to the database is established.

```ts
await dataSource.dropDatabase()
```

<h3 class="h3color">runMigrations</h3>
Runs all pending migrations.

```ts
await dataSource.runMigrations()
```

<h3 class="h3color">undoLastMigration</h3>
Reverts last executed migration.

```ts
await dataSource.undoLastMigration()
```

<h3 class="h3color">hasMetadata</h3>
Checks if metadata for a given entity is registered. Learn more about Entity Metadata.

```ts
if (dataSource.hasMetadata(User))
    const userMetadata = dataSource.getMetadata(User)
```

<h3 class="h3color">getMetadata</h3>
Gets EntityMetadata of the given entity. You can also specify a table name and if entity metadata with such table name is found it will be returned. Learn more about Entity Metadata.
const userMetadata = dataSource.getMetadata(User)

```ts
const userMetadata = dataSource.getMetadata(User)
// now you can get any information about User entity
```

<h3 class="h3color">getRepository</h3>
Gets Repository of the given entity. You can also specify a table name and if repository for given table is found it will be returned. Learn more about Repositories.

```ts
const repository = dataSource.getRepository(User)
// now you can call repository methods, for example find:
const users = await repository.find()
```

<h3 class="h3color">getTreeRepository</h3>
Gets TreeRepository of the given entity. You can also specify a table name and if repository for given table is found it will be returned. Learn more about Repositories.

```ts
const repository = dataSource.getTreeRepository(Category)
// now you can call tree repository methods, for example findTrees:
const categories = await repository.findTrees()
```

<h3 class="h3color">transaction</h3>
Provides a single transaction where multiple database requests will be executed in a single database transaction. Learn more about Transactions.

```ts
await dataSource.transaction(async (manager) => {
    // NOTE: you must perform all database operations using given manager instance
    // its a special instance of EntityManager working with this transaction
    // and don't forget to await things here
})
```

<h3 class="h3color">query</h3>
Executes a raw SQL query.

```ts
const rawData = await dataSource.query(`SELECT * FROM USERS`)
```

<h3 class="h3color">createQueryBuilder</h3>
Creates a query builder, which can be used to build queries. Learn more about QueryBuilder.

```ts
const users = await dataSource
    .createQueryBuilder()
    .select()
    .from(User, "user")
    .where("user.name = :name", { name: "John" })
    .getMany()
```

<h3 class="h3color">createQueryRunner</h3>
Creates a query runner used to manage and work with a single real database dataSource. Learn more about QueryRunner.

```ts
const queryRunner = dataSource.createQueryRunner()

// you can use its methods only after you call connect
// which performs real database connection
await queryRunner.connect()

// .. now you can work with query runner and call its methods

// very important - don't forget to release query runner once you finished working with it
await queryRunner.release()
```

