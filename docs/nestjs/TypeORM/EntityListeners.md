<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../source.css">

<h1 style="text-align:center">TypeORM - Entity Listeners and Subscribers</h1>

<h1 class="h1color">What is an Entity Listener?</h1>
Any of your entities can have methods with custom logic that listen to specific entity events. You must mark those methods with special decorators depending on what event you want to listen to.

**Note:** Do not make any database calls within a listener, opt for subscribers instead.

## @AfterLoad
You can define a method with any name in entity and mark it with ``@AfterLoad`` and TypeORM will call it each time the entity is loaded using QueryBuilder or repository/manager find methods. Example:
```ts
@Entity()
export class Post {
    @AfterLoad()
    updateCounters() {
        if (this.likesCount === undefined) this.likesCount = 0
    }
}
```

## @BeforeInsert
You can define a method with any name in entity and mark it with ``@BeforeInsert`` and TypeORM will call it before the entity is inserted using repository/manager save. Example:
```ts
@Entity()
export class Post {
    @BeforeInsert()
    updateDates() {
        this.createdDate = new Date()
    }
}
```

## @AfterUpdate
You can define a method with any name in the entity and mark it with ``@AfterUpdate`` and TypeORM will call it after an existing entity is updated using repository/manager save. Example:
```ts
@Entity()
export class Post {
    @AfterUpdate()
    updateCounters() {
        this.counter = 0
    }
}
```

## @BeforeRemove
You can define a method with any name in the entity and mark it with ``@BeforeRemove`` and TypeORM will call it before a entity is removed using repository/manager remove. Example:
```ts
@Entity()
export class Post {
    @BeforeRemove()
    updateStatus() {
        this.status = "removed"
    }
}
```

## @BeforeSoftRemove
You can define a method with any name in the entity and mark it with ``@BeforeSoftRemove`` and TypeORM will call it before a entity is soft removed using repository/manager softRemove. Example:
```ts
@Entity()
export class Post {
    @BeforeSoftRemove()
    updateStatus() {
        this.status = "soft-removed"
    }
}
```

## @AfterSoftRemove
You can define a method with any name in the entity and mark it with ``@AfterSoftRemove`` and TypeORM will call it after the entity is soft removed using repository/manager softRemove. Example:
```ts
@Entity()
export class Post {
    @AfterSoftRemove()
    updateStatus() {
        this.status = "soft-removed"
    }
}
```

## @BeforeRecover
You can define a method with any name in the entity and mark it with ``@BeforeRecover`` and TypeORM will call it before a entity is recovered using repository/manager recover. Example:
```ts
@Entity()
export class Post {
    @BeforeRecover()
    updateStatus() {
        this.status = "recovered"
    }
}
```

## @AfterRecover
You can define a method with any name in the entity and mark it with ``@AfterRecover`` and TypeORM will call it after the entity is recovered using repository/manager recover. Example:
```ts
@Entity()
export class Post {
    @AfterSoftRemove()
    updateStatus() {
        this.status = "recovered"
    }
}
```

</br></br>
<h1 class="h1color">Entity Subscriber</h1>
Marks a class as an event subscriber which can listen to specific entity events or any entity events. Events are firing using QueryBuilder and repository/manager methods. Example:

```ts
@EventSubscriber()
export class PostSubscriber implements EntitySubscriberInterface<Post> {
    /**
     * Indicates that this subscriber only listen to Post events.
     */
    listenTo() {
        return Post
    }

    /**
     * Called before post insertion.
     */
    beforeInsert(event: InsertEvent<Post>) {
        console.log(`BEFORE POST INSERTED: `, event.entity)
    }
}
```

You can implement any method from EntitySubscriberInterface. To listen to any entity you just omit listenTo method and use any:
```ts
@EventSubscriber()
export class PostSubscriber implements EntitySubscriberInterface {
    afterLoad(entity: any) {
        console.log(`AFTER ENTITY LOADED: `, entity)
    }
    beforeInsert(event: InsertEvent<any>) {
        console.log(`BEFORE POST INSERTED: `, event.entity)
    }
    afterInsert(event: InsertEvent<any>) {
        console.log(`AFTER ENTITY INSERTED: `, event.entity)
    }
    beforeUpdate(event: UpdateEvent<any>) {
        console.log(`BEFORE ENTITY UPDATED: `, event.entity)
    }
    afterUpdate(event: UpdateEvent<any>) {
        console.log(`AFTER ENTITY UPDATED: `, event.entity)
    }
    beforeRemove(event: RemoveEvent<any>) {
        console.log(
            `BEFORE ENTITY WITH ID ${event.entityId} REMOVED: `,
            event.entity,
        )
    }
    afterRemove(event: RemoveEvent<any>) {
        console.log(
            `AFTER ENTITY WITH ID ${event.entityId} REMOVED: `,
            event.entity,
        )
    }
    beforeSoftRemove(event: SoftRemoveEvent<any>) {
        console.log(
            `BEFORE ENTITY WITH ID ${event.entityId} SOFT REMOVED: `,
            event.entity,
        )
    }
    afterSoftRemove(event: SoftRemoveEvent<any>) {
        console.log(
            `AFTER ENTITY WITH ID ${event.entityId} SOFT REMOVED: `,
            event.entity,
        )
    }
    beforeRecover(event: RecoverEvent<any>) {
        console.log(
            `BEFORE ENTITY WITH ID ${event.entityId} RECOVERED: `,
            event.entity,
        )
    }
    afterRecover(event: RecoverEvent<any>) {
        console.log(
            `AFTER ENTITY WITH ID ${event.entityId} RECOVERED: `,
            event.entity,
        )
    }
    beforeTransactionStart(event: TransactionStartEvent) {
        console.log(`BEFORE TRANSACTION STARTED: `, event)
    }
    afterTransactionStart(event: TransactionStartEvent) {
        console.log(`AFTER TRANSACTION STARTED: `, event)
    }
    beforeTransactionCommit(event: TransactionCommitEvent) {
        console.log(`BEFORE TRANSACTION COMMITTED: `, event)
    }
    afterTransactionCommit(event: TransactionCommitEvent) {
        console.log(`AFTER TRANSACTION COMMITTED: `, event)
    }
    beforeTransactionRollback(event: TransactionRollbackEvent) {
        console.log(`BEFORE TRANSACTION ROLLBACK: `, event)
    }
    afterTransactionRollback(event: TransactionRollbackEvent) {
        console.log(`AFTER TRANSACTION ROLLBACK: `, event)
    }
}
```

## Event Object
Excluding ``listenTo``, all ``EntitySubscriberInterface`` methods are passed an event object that has the following base properties:

* dataSource: DataSource - DataSource used in the event.
* queryRunner: QueryRunner - QueryRunner used in the event transaction.
* manager: EntityManager - EntityManager used in the event transaction.

**Note:** All database operations in the subscribed event listeners should be performed using the event object's queryRunner or manager instance.






















