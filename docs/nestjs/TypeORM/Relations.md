<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../../source.css">

<h1 style="text-align:center">TypeORM - Relations</h1>

<h1 class="h1color">What are Relations?</h1>

## Relation options
There are several options you can specify for relations:

* ``eager: boolean`` - If set to true, the relation will always be loaded with the main entity when using find* methods or QueryBuilder on this entity
* ``cascade: boolean | ("insert" | "update")[]`` - If set to true, the related object will be inserted and updated in the database. You can also specify an array of cascade options.
* ``onDelete: "RESTRICT"|"CASCADE"|"SET NULL"`` - specifies how foreign key should behave when referenced object is deleted
* ``nullable: boolean`` - Indicates whether this relation's column is nullable or not. By default it is nullable.
* ``orphanedRowAction: "nullify" | "delete" | "soft-delete" | disable`` - When a parent is saved (cascading enabled) without a child/children that still exists in database, this will control what shall happen to them. delete will remove these children from database. soft-delete will mark children as soft-deleted. nullify will remove the relation key. disable will keep the relation intact. To delete, one has to use their own repository.

## Cascades
```ts
import { Entity, PrimaryGeneratedColumn, Column, ManyToMany } from "typeorm"
import { Question } from "./Question"

@Entity()
export class Category {
    @PrimaryGeneratedColumn() id: number
    @Column() name: string
    @ManyToMany((type) => Question, (question) => question.categories) 
    questions: Question[]
}
```

```ts
import { Category } from "./Category"

@Entity()
export class Question {
    @PrimaryGeneratedColumn() id: number
    @Column() title: string
    @Column() text: string
    @ManyToMany((type) => Category, (category) => category.questions, {
        cascade: true,
    })
    @JoinTable() 
    categories: Category[]
}
```

```ts
 const category1 = new Category()
category1.name = "ORMs"

const category2 = new Category()
category2.name = "Programming"

const question = new Question()
question.title = "How to ask questions?"
question.text = "Where can I ask TypeORM-related questions?"
question.categories = [category1, category2]
await dataSource.manager.save(question)
```
As you can see in this example we did not call save for category1 and category2. They will be automatically inserted, because we set cascade to true.

Keep in mind - great power comes with great responsibility. Cascades may seem like a good and easy way to work with relations, but they may also bring bugs and security issues when some undesired object is being saved into the database. Also, they provide a less explicit way of saving new objects into the database.

## Cascade Options
The cascade option can be set as a boolean or an array of cascade options ``("insert" | "update" | "remove" | "soft-remove" | "recover")[]``.

```ts
@Entity(Post)
export class Post {
    @PrimaryGeneratedColumn() id: number
    @Column() title: string
    @Column() text: string

    // Full cascades on categories.
    @ManyToMany((type) => PostCategory, {
        cascade: true,
    })
    @JoinTable()
    categories: PostCategory[]

    // Cascade insert here means if there is a new PostDetails instance set
    // on this relation, it will be inserted automatically to the db when you save this Post entity
    @ManyToMany((type) => PostDetails, (details) => details.posts, {
        cascade: ["insert"],
    })
    @JoinTable()
    details: PostDetails[]

    // Cascade update here means if there are changes to an existing PostImage, it
    // will be updated automatically to the db when you save this Post entity
    @ManyToMany((type) => PostImage, (image) => image.posts, {
        cascade: ["update"],
    })
    @JoinTable()
    images: PostImage[]

    // Cascade insert & update here means if there are new PostInformation instances
    // or an update to an existing one, they will be automatically inserted or updated
    // when you save this Post entity
    @ManyToMany((type) => PostInformation, (information) => information.posts, {
        cascade: ["insert", "update"],
    })
    @JoinTable()
    informations: PostInformation[]
}
```

## @JoinColumn options
``@JoinColumn`` not only defines which side of the relation contains the join column with a foreign key, but also allows you to customize join column name and referenced column name.

When we set ``@JoinColumn``, it automatically creates a column in the database named propertyName + referencedColumnName. For example:
```ts
@ManyToOne(type => Category)
@JoinColumn() // this decorator is optional for @ManyToOne, but required for @OneToOne
category: Category;
```

</br></br>
<h1 class="h1color">One-to-One</h1>

One-to-one is a relation where A contains only one instance of B, and B contains only one instance of A. Let's take for example User and Profile entities. User can have only a single profile, and a single profile is owned by only a single user.

```ts
import { Entity, PrimaryGeneratedColumn, Column } from "typeorm"

@Entity()
export class Profile {
    @PrimaryGeneratedColumn() id: number
    @Column() gender: string
    @Column() photo: string
}
```

```ts
import { Profile } from "./Profile"

@Entity()
export class User {
    @PrimaryGeneratedColumn() id: number
    @Column() name: string

    @OneToOne(() => Profile)
    @JoinColumn()
    profile: Profile
}
```
This example will produce following tables:
```
+-------------+--------------+----------------------------+
|                        profile                          |
+-------------+--------------+----------------------------+
| id          | int(11)      | PRIMARY KEY AUTO_INCREMENT |
| gender      | varchar(255) |                            |
| photo       | varchar(255) |                            |
+-------------+--------------+----------------------------+

+-------------+--------------+----------------------------+
|                          user                           |
+-------------+--------------+----------------------------+
| id          | int(11)      | PRIMARY KEY AUTO_INCREMENT |
| name        | varchar(255) |                            |
| profileId   | int(11)      | FOREIGN KEY                |
+-------------+--------------+----------------------------+
```

Example how to save such a relation:
```ts
const profile = new Profile()
profile.gender = "male"
profile.photo = "me.jpg"
await dataSource.manager.save(profile)

const user = new User()
user.name = "Joe Smith"
user.profile = profile
await dataSource.manager.save(user)
```

To load user with profile inside you must specify relation in FindOptions:
```ts
const users = await dataSource.getRepository(User).find({
    relations: {
        profile: true,
    },
})
```

</br></br>
<h1 class="h1color">Many-to-One and One-to-Many</h1>

Many-to-one / one-to-many is a relation where A contains multiple instances of B, but B contains only one instance of A. Let's take for example User and Photo entities. User can have multiple photos, but each photo is owned by only one single user.

```ts
import { User } from "./User"

@Entity()
export class Photo {
    @PrimaryGeneratedColumn() id: number
    @Column() url: string

    @ManyToOne(() => User, (user) => user.photos)
    user: User
}
```

```ts
import { Photo } from "./Photo"

@Entity()
export class User {
    @PrimaryGeneratedColumn() id: number
    @Column() name: string

    @OneToMany(() => Photo, (photo) => photo.user)
    photos: Photo[]
}
```

Here we added ``@OneToMany`` to the photos property and specified the target relation type to be Photo. You can omit ``@JoinColumn`` in a ``@ManyToOne / @OneToMany`` relation. ``@OneToMany`` cannot exist without ``@ManyToOne``. If you want to use ``@OneToMany``, ``@ManyToOne`` is required. However, the inverse is not required: If you only care about the ``@ManyToOne`` relationship, you can define it without having ``@OneToMany`` on the related entity. Where you set ``@ManyToOne`` - its related entity will have "relation id" and foreign key.

This example will produce following tables:
```
+-------------+--------------+----------------------------+
|                         photo                           |
+-------------+--------------+----------------------------+
| id          | int(11)      | PRIMARY KEY AUTO_INCREMENT |
| url         | varchar(255) |                            |
| userId      | int(11)      | FOREIGN KEY                |
+-------------+--------------+----------------------------+

+-------------+--------------+----------------------------+
|                          user                           |
+-------------+--------------+----------------------------+
| id          | int(11)      | PRIMARY KEY AUTO_INCREMENT |
| name        | varchar(255) |                            |
+-------------+--------------+----------------------------+
```

Example how to save such relation:
```ts
const photo1 = new Photo()
photo1.url = "me.jpg"
await dataSource.manager.save(photo1)

const photo2 = new Photo()
photo2.url = "me-and-bears.jpg"
await dataSource.manager.save(photo2)

const user = new User()
user.name = "John"
user.photos = [photo1, photo2]
await dataSource.manager.save(user)
```

To load a user with photos inside you must specify the relation in FindOptions:
```ts
const userRepository = dataSource.getRepository(User)
const users = await userRepository.find({
    relations: {
        photos: true,
    },
})
```

</br></br>
<h1 class="h1color">Many-to-many relations</h1>

## What are many-to-many relations
Many-to-many is a relation where A contains multiple instances of B, and B contain multiple instances of A. Let's take for example Question and Category entities. A question can have multiple categories, and each category can have multiple questions.

```ts
import { Entity, PrimaryGeneratedColumn, Column } from "typeorm"

@Entity()
export class Category {
    @PrimaryGeneratedColumn() id: number
    @Column() name: string
}
```

```ts
import { Category } from "./Category"

@Entity()
export class Question {
    @PrimaryGeneratedColumn() id: number
    @Column() title: string
    @Column() text: string

    @ManyToMany(() => Category)
    @JoinTable()
    categories: Category[]
}
```
@JoinTable() is required for @ManyToMany relations. You must put @JoinTable on one (owning) side of relation.

This example will produce following tables:
```
+-------------+--------------+----------------------------+
|                        category                         |
+-------------+--------------+----------------------------+
| id          | int(11)      | PRIMARY KEY AUTO_INCREMENT |
| name        | varchar(255) |                            |
+-------------+--------------+----------------------------+

+-------------+--------------+----------------------------+
|                        question                         |
+-------------+--------------+----------------------------+
| id          | int(11)      | PRIMARY KEY AUTO_INCREMENT |
| title       | varchar(255) |                            |
| text        | varchar(255) |                            |
+-------------+--------------+----------------------------+

+-------------+--------------+----------------------------+
|              question_categories_category               |
+-------------+--------------+----------------------------+
| questionId  | int(11)      | PRIMARY KEY FOREIGN KEY    |
| categoryId  | int(11)      | PRIMARY KEY FOREIGN KEY    |
+-------------+--------------+----------------------------+
```

### Saving many-to-many relations
With cascades enabled, you can save this relation with only one save call.
```ts
const category1 = new Category()
category1.name = "animals"
await dataSource.manager.save(category1)

const category2 = new Category()
category2.name = "zoo"
await dataSource.manager.save(category2)

const question = new Question()
question.title = "dogs"
question.text = "who let the dogs out?"
question.categories = [category1, category2]
await dataSource.manager.save(question)
```

### Loading many-to-many relations
To load questions with categories inside you must specify the relation in FindOptions:
```ts
const questionRepository = dataSource.getRepository(Question)
const questions = await questionRepository.find({
    relations: {
        categories: true,
    },
})

// Or using QueryBuilder:
const questions = await dataSource
    .getRepository(Question)
    .createQueryBuilder("question")
    .leftJoinAndSelect("question.categories", "category")
    .getMany()
```

</br></br>
<h1 class="h1color">Eager relations</h1>

Eager relations are loaded automatically each time you load entities from the database. For example:
```ts
import { Question } from "./Question"

@Entity()
export class Category {
    @PrimaryGeneratedColumn() id: number
    @Column() name: string

    @ManyToMany((type) => Question, (question) => question.categories)
    questions: Question[]
}
```

```ts
@Entity()
export class Question {
    @PrimaryGeneratedColumn() id: number
    @Column() title: string
    @Column() text: string

    @ManyToMany((type) => Category, (category) => category.questions, {
        eager: true,
    })
    @JoinTable()
    categories: Category[]
}
```

Now when you load questions you don't need to join or specify relations you want to load. They will be loaded automatically:
```ts
const questionRepository = dataSource.getRepository(Question)

// questions will be loaded with its categories
const questions = await questionRepository.find()
```



















