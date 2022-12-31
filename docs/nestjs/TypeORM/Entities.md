<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../source.css">

<h1 style="text-align:center">TypeORM - Entities</h1>

<h1 class="h1color">What is Entity?</h1>

Entity is a class that maps to a database table (or collection when using MongoDB). You can create an entity by defining a new class and mark it with ``@Entity()``:

```ts
import { Entity, PrimaryGeneratedColumn, Column } from "typeorm"

@Entity()
export class User {
    @PrimaryGeneratedColumn()
    id: number

    @Column()
    firstName: string

    @Column()
    lastName: string

    @Column()
    isActive: boolean
}
/* Entity
+-------------+--------------+----------------------------+
|                          user                           |
+-------------+--------------+----------------------------+
| id          | int(11)      | PRIMARY KEY AUTO_INCREMENT |
| firstName   | varchar(255) |                            |
| lastName    | varchar(255) |                            |
| isActive    | boolean      |                            |
+-------------+--------------+----------------------------+ */
```

Basic entities consist of columns and relations. Each entity *MUST have a primary column*.

Each entity must be registered in your data source options:
```ts
import { DataSource } from "typeorm"
import { User } from "./entity/User"  //Entity

const myDataSource = new DataSource({
    type: "mysql",
    ...
    entities: [User],
})
```

Or you can specify the whole directory with all entities inside - and all of them will be loaded:
```ts
import { DataSource } from "typeorm"
const dataSource = new DataSource({
    type: "mysql",
    ...
    entities: ["entity/*.js"],
})
```

## Entity columns
Since database tables consist of columns your entities must consist of columns too. Each entity class property you marked with @Column will be mapped to a database table column.

## Primary columns
Each entity must have at least one primary column. There are several types of primary columns:

``@PrimaryColumn()`` creates a primary column which takes any value of any type. You can specify the column type. If you don't specify a column type it will be inferred from the property type. The example below will create id with int as type which you must manually assign before save.

```ts
@Entity()
export class User {
    @PrimaryColumn()
    id: number
}
```

``@PrimaryGeneratedColumn()`` creates a primary column which value will be automatically generated with an auto-increment value. It will create int column with auto-increment/serial/sequence/identity (depend on the database and configuration provided). You don't have to manually assign its value before save - value will be automatically generated.

```ts
@Entity()
export class User {
    @PrimaryGeneratedColumn()
    id: number
}
```

``@PrimaryGeneratedColumn("uuid")`` creates a primary column which value will be automatically generated with uuid. Uuid is a unique string id. You don't have to manually assign its value before save - value will be automatically generated.

```ts
@Entity()
export class User {
    @PrimaryGeneratedColumn("uuid")
    id: string
}
```

## Column types
TypeORM supports all of the most commonly used database-supported column types. Column types are database-type specific - this provides more flexibility on how your database schema will look like.

You can specify column type as first parameter of ``@Column`` or in the column options of ``@Column``, for example:
```ts
@Column("int")
@Column({ type: "int" })
```

If you want to specify additional type parameters you can do it via column options. For example:
```ts
@Column("varchar", { length: 200 })
@Column({ type: int, width: 200 })
```

## Column types for mysql/mariadb
bit, int, integer, tinyint, smallint, mediumint, bigint, float, double, double precision, dec, decimal, numeric, fixed, bool, boolean, date, datetime, timestamp, time, year, char, nchar, national char, varchar, nvarchar, national varchar, text, tinytext, mediumtext, blob, longtext, tinyblob, mediumblob, longblob, enum, set, json, binary, varbinary, geometry, point, linestring, polygon, multipoint, multilinestring, multipolygon, geometrycollection


## enum column type
enum column type is supported by postgres and mysql. There are various possible column definitions:

```ts
export enum UserRole {
    ADMIN = "admin",
    EDITOR = "editor",
    GHOST = "ghost",
}

@Entity()
export class User {
    @PrimaryGeneratedColumn()
    id: number

    @Column({
        type: "enum",
        enum: UserRole,
        default: UserRole.GHOST,
    })
    role: UserRole
}

// Using array with enum values
export type UserRoleType = "admin" | "editor" | "ghost",

@Entity()
export class User {

    @PrimaryGeneratedColumn()
    id: number;

    @Column({
        type: "enum",
        enum: ["admin", "editor", "ghost"],
        default: "ghost"
    })
    role: UserRoleType
}
```

## set column type
set column type is supported by mariadb and mysql. There are various possible column definitions:

```ts
export enum UserRole {ADMIN = "admin", EDITOR = "editor", GHOST = "ghost",}

@Entity()
export class User {
    @PrimaryGeneratedColumn()
    id: number

    @Column({
        type: "set",
        enum: UserRole,
        default: [UserRole.GHOST, UserRole.EDITOR],
    })
    roles: UserRole[]
}
```

## simple-array column type
There is a special column type called simple-array which can store primitive array values in a single string column. All values are separated by a comma. For example:
```ts
@Entity()
export class User {
    @PrimaryGeneratedColumn()
    id: number

    @Column("simple-array")
    names: string[]
}
// user.names = ["Alexander", "Alex"]
```

## simple-json column type
There is a special column type called simple-json which can store any values which can be stored in database via JSON.stringify. Very useful when you do not have json type in your database and you want to store and load object without any hassle. For example:
```ts
@Entity()
export class User {
    @PrimaryGeneratedColumn()
    id: number

    @Column("simple-json")
    profile: { name: string; nickname: string }
}
// user.profile = { name:"John", nickname:"Malkovich" }
```

## Columns with generated values
You can create column with generated value using ``@Generated`` decorator. For example
```ts
@Entity()
export class User {
    @PrimaryColumn()
    id: number

    @Column()
    @Generated("uuid")
    uuid: string
}
// uuid value will be automatically generated and stored into the database.
```

## Column options
Column options defines additional options for your entity columns. You can specify column options on ``@Column``:
```ts
@Column({
    type: "int",
    length: 150,
    unique: true,
})
name: string;
```

List of available options in ColumnOptions:

* ``type: ColumnType`` - Column type. One of the type listed above.

* ``name: string`` - Column name in the database table. By default the column name is generated from the name of the property. You can change it by specifying your own name.

* ``length: number`` - Column type's length. For example if you want to create varchar(150) type you specify column type and length options.

* ``width: number`` - column type's display width. Used only for MySQL integer types

* ``onUpdate: string`` - ON UPDATE trigger. Used only in MySQL.

* ``nullable: boolean`` - Makes column NULL or NOT NULL in the database. By default column is nullable: false.

* ``update: boolean`` - Indicates if column value is updated by "save" operation. If false, you'll be able to write this value only when you first time insert the object. Default value is true.

* ``insert: boolean`` - Indicates if column value is set the first time you insert the object. Default value is true.

* ``select: boolean`` - Defines whether or not to hide this column by default when making queries. When set to false, the column data will not show with a standard query. By default column is select: true

* ``default: string`` - Adds database-level column's DEFAULT value.

* ``primary: boolean`` - Marks column as primary. Same if you use @PrimaryColumn.

* ``unique: boolean`` - Marks column as unique column (creates unique constraint).

* ``comment: string`` - Database's column comment. Not supported by all database types.

* ``precision: number`` - The precision for a decimal (exact numeric) column (applies only for decimal column), which is the maximum number of digits that are stored for the values. Used in some column types.

* ``scale: number`` - The scale for a decimal (exact numeric) column (applies only for decimal column), which represents the number of digits to the right of the decimal point and must not be greater than precision. Used in some column types.

* ``zerofill: boolean`` - Puts ZEROFILL attribute on to a numeric column. Used only in MySQL. If true, MySQL automatically adds the UNSIGNED attribute to this column.

* ``unsigned: boolean`` - Puts UNSIGNED attribute on to a numeric column. Used only in MySQL.

* ``charset: string`` - Defines a column character set. Not supported by all database types.

* ``collation: string`` - Defines a column collation.

* ``enum: string``[]|AnyEnum - Used in enum column type to specify list of allowed enum values. You can specify array of values or specify a enum class.

* ``enumName: string`` - Defines the name for the used enum.

* ``asExpression: string`` - Generated column expression. Used only in MySQL.

* ``generatedType: "VIRTUAL"|"STORED"`` - Generated column type. Used only in MySQL.

* ``hstoreType: "object"|"string"`` - Return type of HSTORE column. Returns value as string or as object. Used only in Postgres.

* ``array: boolean`` - Used for postgres and cockroachdb column types which can be array (for example int[])

``transformer: { from(value: DatabaseType): EntityType, to(value: EntityType): DatabaseType }`` - Used to marshal properties of arbitrary type **EntityType** into a type **DatabaseType** supported by the database. Array of transformers are also supported and will be applied in natural order when writing, and in reverse order when reading. e.g. ``[lowercase, encrypt]`` will first lowercase the string then encrypt it when writing, and will decrypt then do nothing when reading.

## Entity inheritace
You can reduce duplication in your code by using entity inheritance.

For example, you have ``Photo, Question, Post`` entities:
```ts
@Entity()
export class Photo {@PrimaryGeneratedColumn() id: number

    @Column()
    title: string
    @Column()
    description: string
    @Column()
    size: string
}

@Entity()
export class Question {@PrimaryGeneratedColumn() id: number

    @Column()
    title: string 
    @Column() 
    description: string
    @Column()
    answersCount: number
}

@Entity()
export class Post { @PrimaryGeneratedColumn() id: number

    @Column()
    title: string
    @Column()
    description: string
    @Column()
    viewCount: number
}
```

As you can see all those entities have common columns: ``id, title, description``. To reduce duplication and produce a better abstraction we can create a base class called Content for them:
```ts
export abstract class Content {
    @PrimaryGeneratedColumn()
    id: number

    @Column()
    title: string

    @Column()
    description: string
}
@Entity()
export class Photo extends Content {
    @Column()
    size: string
}

@Entity()
export class Question extends Content {
    @Column()
    answersCount: number
}

@Entity()
export class Post extends Content {
    @Column()
    viewCount: number
}
```

## Adjacency list
Adjacency list is a simple model with self-referencing. Benefit of this approach is simplicity, drawback is you can't load a big tree at once because of join limitations. Example:
```ts
@Entity()
export class Category {
    @PrimaryGeneratedColumn()
    id: number
    ...
    @ManyToOne((type) => Category, (category) => category.children)
    parent: Category

    @OneToMany((type) => Category, (category) => category.parent)
    children: Category[]
}
```

## Closure table
A closure table stores relations between parent and child in a separate table in a special way. Its efficient in both reads and writes. To learn more about closure table take a look at this awesome presentation by Bill Karwin. Example:
```ts
@Entity()
@Tree("closure-table")
export class Category {
    @PrimaryGeneratedColumn()
    id: number
    ...
    @TreeChildren()
    children: Category[]

    @TreeParent()
    parent: Category

    @TreeLevelColumn()
    level: number
}
```
</br></br>
<h1 class="h1color">Embedded Entities</h1>
There is an amazing way to reduce duplication in your app (using composition over inheritance) by using embedded columns. Embedded column is a column which accepts a class with its own columns and merges those columns into the current entity's database table. Example:

Let's say we have User, Employee and Student entities. All those entities have few things in common - first name and last name properties

```ts
// Embedded Entities
export class Name {
    @Column()
    first: string
    @Column()
    last: string
}

// Entities
import { Name } from "./Name"
@Entity()
export class User {
    @PrimaryGeneratedColumn()
    id: string

    @Column(() => Name)
    name: Name

    @Column()
    isActive: boolean
}
```
All columns defined in the Name entity will be merged into user:
```
+-------------+--------------+----------------------------+
|                          user                           |
+-------------+--------------+----------------------------+
| id          | int(11)      | PRIMARY KEY AUTO_INCREMENT |
| nameFirst   | varchar(255) |                            |
| nameLast    | varchar(255) |                            |
| isActive    | boolean      |                            |
+-------------+--------------+----------------------------+
```

This way code duplication in the entity classes is reduced. You can use as many columns (or relations) in embedded classes as you need. You even can have nested embedded columns inside embedded classes.

</br></br>
<h1 class="h1color">Entity Inheritance</h1>

## Concrete Table Inheritance
You can reduce duplication in your code by using entity inheritance patterns. The simplest and the most effective is concrete table inheritance.

All those entities have common columns: id, title, description. To reduce duplication and produce a better abstraction we can create a base class called Content for them:
```ts
// base class
export abstract class Content {
    @PrimaryGeneratedColumn()
    id: number

    @Column()
    title: string

    @Column()
    description: string
}

// Photo
@Entity()
export class Photo extends Content {
    @Column() size: string;
}

// Question
@Entity()
export class Question extends Content {
    @Column() answerCount: number;
}

// Post
@Entity()
export class Post extends Content {
    @Column() viewCount: number;
}
```

All columns (relations, embeds, etc.) from parent entities (parent can extend other entity as well) will be inherited and created in final entities.

## Single Table Inheritance
TypeORM also supports single table inheritance. Single table inheritance is a pattern when you have multiple classes with their own properties, but in the database they are stored in the same table.

```ts
@Entity()
@TableInheritance({ column: { type: "varchar", name: "type" } })
export class Content {
    @PrimaryGeneratedColumn()
    id: number

    @Column()
    title: string

    @Column()
    description: string
}

@ChildEntity()
export class Photo extends Content {
    @Column()
    size: string
}

@ChildEntity()
export class Question extends Content {
    @Column()
    answersCount: number
}
```

</br></br>
<h1 class="h1color">Tree Entities</h1>
TypeORM supports the Adjacency list and Closure table patterns for storing tree structures. To learn more about hierarchy table take a look at this awesome presentation by Bill Karwin.

## Adjacency list
Adjacency list is a simple model with self-referencing. The benefit of this approach is simplicity, drawback is that you can't load big trees in all at once because of join limitations. To learn more about the benefits and use of Adjacency Lists look at this article by Matthew Schinckel. Example:
```ts
@Entity()
export class Category {
    @PrimaryGeneratedColumn()
    id: number

    @Column()
    name: string

    @Column()
    description: string

    @ManyToOne((type) => Category, (category) => category.children)
    parent: Category

    @OneToMany((type) => Category, (category) => category.parent)
    children: Category[]
}
```

## Nested set
Nested set is another pattern of storing tree structures in the database. Its very efficient for reads, but bad for writes. You cannot have multiple roots in nested set. Example:
```ts
@Entity()
@Tree("nested-set")
export class Category {
    @PrimaryGeneratedColumn()
    id: number

    @Column()
    name: string

    @TreeChildren()
    children: Category[]

    @TreeParent()
    parent: Category
}
```

## Meterialized Path (aka Path Enumeration)
Materialized Path (also called Path Enumeration) is another pattern of storing tree structures in the database. Its simple and effective. Example:
```ts
@Entity()
@Tree("materialized-path")
export class Category {
    @PrimaryGeneratedColumn()
    id: number

    @Column()
    name: string

    @TreeChildren()
    children: Category[]

    @TreeParent()
    parent: Category
}
```

## Closure table
Closure table stores relations between parent and child in a separate table in a special way. It's efficient in both reads and writes. Example:
```ts
@Entity()
@Tree("closure-table")
export class Category {
    @PrimaryGeneratedColumn()
    id: number

    @Column()
    name: string

    @TreeChildren()
    children: Category[]

    @TreeParent()
    parent: Category
}
```

You can specify closure table name and / or closure table columns names by setting optional parameter options into ``@Tree("closure-table", options).ancestorColumnName`` and descandantColumnName are callback functions, which receive primary column's metadata and return column's name.

```ts
@Tree("closure-table", {
    closureTableName: "category_closure",
    ancestorColumnName: (column) => "ancestor_" + column.propertyName,
    descendantColumnName: (column) => "descendant_" + column.propertyName,
})
```

## Working with tree entities
> Document site: https://typeorm.io/tree-entities#working-with-tree-entities


</br></br>
<h1 class="h1color">View Entities</h1>

## What is View Entity?
View entity is a class that maps to a database view. You can create a view entity by defining a new class and mark it with ``@ViewEntity()``:

``@ViewEntity()`` accepts following options:
* ``name`` - view name. If not specified, then view name is generated from entity class name.
* ``database`` - database name in selected DB server.
* ``schema`` - schema name.
* ``expression`` - view definition. Required parameter.
* ``dependsOn`` - List of other views on which the current views depends. If your view uses another view in it's definition, you can add it here so that migrations are generated in the correct order.

``expression`` can be string with properly escaped columns and tables, depend on database used (postgres in example):

```ts
@ViewEntity({
    expression: `
        SELECT "post"."id" AS "id", "post"."name" AS "name", "category"."name" AS "categoryName"
        FROM "post" "post"
        LEFT JOIN "category" "category" ON "post"."categoryId" = "category"."id"
    `
})

// or an instance of QueryBuilder
@ViewEntity({
    expression: (dataSource: DataSource) => dataSource
        .createQueryBuilder()
        .select("post.id", "id")
        .addSelect("post.name", "name")
        .addSelect("category.name", "categoryName")
        .from(Post, "post")
        .leftJoin(Category, "category", "category.id = post.categoryId")
        .where("category.name = :name", { name: "Cars" })  // <-- this is wrong
        .where("category.name = 'Cars'")                   // <-- and this is right
})
```

## View Entity columns
To map data from view into the correct entity columns you must mark entity columns with ``@ViewColumn()`` decorator and specify these columns as select statement aliases.

example with string expression definition:
```ts
import { ViewEntity, ViewColumn } from "typeorm"

@ViewEntity({
    expression: (dataSource: DataSource) => dataSource
        .createQueryBuilder()
        .select("post.id", "id")
        .addSelect("post.name", "name")
        .addSelect("category.name", "categoryName")
        .from(Post, "post")
        .leftJoin(Category, "category", "category.id = post.categoryId"),
})
export class PostCategory {
    @ViewColumn()
    id: number

    @ViewColumn()
    name: string

    @ViewColumn()
    categoryName: string
}
```

## Complete example
Let create two entities and a view containing aggregated data from these entities:
```ts
import { Entity, PrimaryGeneratedColumn, Column } from "typeorm"
@Entity()
export class Category {
    @PrimaryGeneratedColumn() id: number
    @Column() name: string 
}
```

```ts
@Entity()
export class Post {
    @PrimaryGeneratedColumn() id: number
    @Column() name: string
    @Column() categoryId: number
    @ManyToOne(() => Category)
    @JoinColumn({ name: "categoryId" }) category: Category
}
```

```ts
@ViewEntity({
    expression: (dataSource: DataSource) => dataSource
        .createQueryBuilder()
        .select("post.id", "id")
        .addSelect("post.name", "name")
        .addSelect("category.name", "categoryName")
        .from(Post, "post")
        .leftJoin(Category, "category", "category.id = post.categoryId"),
})
export class PostCategory {
    @ViewColumn() id: number
    @ViewColumn() name: string
    @ViewColumn() categoryName: string
}
```
then fill these tables with data and request all data from PostCategory view:
```ts
import { Category } from "./entity/Category"
import { Post } from "./entity/Post"
import { PostCategory } from "./entity/PostCategory"

const category1 = new Category()
category1.name = "Cars"
await dataSource.manager.save(category1)

const category2 = new Category()
category2.name = "Airplanes"
await dataSource.manager.save(category2)

const post1 = new Post()
post1.name = "About BMW"
post1.categoryId = category1.id
await dataSource.manager.save(post1)

const post2 = new Post()
post2.name = "About Boeing"
post2.categoryId = category2.id
await dataSource.manager.save(post2)

const postCategories = await dataSource.manager.find(PostCategory)
const postCategory = await dataSource.manager.findOneBy(PostCategory, { id: 1 })

/* the result in postCategories ->
[ PostCategory { id: 1, name: 'About BMW', categoryName: 'Cars' },
  PostCategory { id: 2, name: 'About Boeing', categoryName: 'Airplanes' } ] 
*/

/* and in postCategory ->
PostCategory { id: 1, name: 'About BMW', categoryName: 'Cars' }
*/
```

</br></br>
<h1 class="h1color">Separating Entity Definition</h1>

## Defining Schemas
You can define an entity and its columns right in the model, using decorators. But some people prefer to define an entity and its columns inside separate files which are called "entity schemas" in TypeORM.

Simple definition example:
```ts
import { EntitySchema } from "typeorm"
export const CategoryEntity = new EntitySchema({
    name: "category",
    columns: {
        id: {
            type: Number,
            primary: true,
            generated: true,
        },
        name: {
            type: String,
        },
    },
})
```

Complex example:
```ts
import { EntitySchema } from "typeorm"

export const PersonSchema = new EntitySchema({
    name: "person",
    columns: {
        id: {
            primary: true,
            type: "int",
            generated: "increment",
        },
        firstName: {
            type: String,
            length: 30,
        },
        lastName: {
            type: String,
            length: 50,
            nullable: false,
        },
        age: {
            type: Number,
            nullable: false,
        },
    },
    checks: [
        { expression: `"firstName" <> 'John' AND "lastName" <> 'Doe'` },
        { expression: `"age" > 18` },
    ],
    indices: [
        {
            name: "IDX_TEST",
            unique: true,
            columns: ["firstName", "lastName"],
        },
    ],
    uniques: [
        {
            name: "UNIQUE_TEST",
            columns: ["firstName", "lastName"],
        },
    ],
})
```

## Extending Schemas
When using the Decorator approach it is easy to extend basic columns to an abstract class and simply extend this. For example, your id, createdAt and updatedAt columns may be defined in such a BaseEntity. For more details, see the documentation on concrete table inheritance.

When using the EntitySchema approach, this is not possible. However, you can use the Spread Operator (...) to your advantage.

Reconsider the Category example from above. You may want to extract basic column descriptions and reuse it across your other schemas. This may be done in the following way:

```ts
import { EntitySchemaColumnOptions } from "typeorm"
export const BaseColumnSchemaPart = {
    id: {
        type: Number,
        primary: true,
        generated: true,
    } as EntitySchemaColumnOptions,
    createdAt: {
        name: "created_at",
        type: "timestamp with time zone",
        createDate: true,
    } as EntitySchemaColumnOptions,
    updatedAt: {
        name: "updated_at",
        type: "timestamp with time zone",
        updateDate: true,
    } as EntitySchemaColumnOptions,
}
```

Now you can use the BaseColumnSchemaPart in your other schema models, like this:
```ts
export const CategoryEntity = new EntitySchema<Category>({
    name: "category",
    columns: {
        ...BaseColumnSchemaPart,
        // the CategoryEntity now has the defined id, createdAt, updatedAt columns!
        // in addition, the following NEW fields are defined
        name: {
            type: String,
        },
    },
})
```

You can use **embedded entities in schema models**, like this:
```ts
export interface Name { first: string last: string}
export const NameEntitySchema = new EntitySchema<Name>({
    name: "name",
    columns: {
        first: {
            type: "varchar",
        },
        last: {
            type: "varchar",
        },
    },
})

export interface User { id: string name: Name isActive: boolean }
export const UserEntitySchema = new EntitySchema<User>({
    name: "user",
    columns: {
        id: {
            primary: true,
            generated: "uuid",
            type: "uuid",
        },
        isActive: {
            type: "boolean",
        },
    },
    embeddeds: {
        name: {
            schema: NameEntitySchema,
            prefix: "name_",
        },
    },
})
```







