<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.5.0/font/bootstrap-icons.css">
<link rel="stylesheet" href="../source.css">

<h1 style="text-align:center">Modules</h1>

A module is a class annotated with a ``@Module()`` decorator. The ``@Module()`` decorator provides metadata that Nest makes use of to organize the application structure.

Each application has at least one module, a root module. The root module is the starting point Nest uses to build the application graph - the internal data structure Nest uses to resolve module and provider relationships and dependencies. While very small applications may theoretically have just the root module, this is not the typical case. We want to emphasize that modules are strongly recommended as an effective way to organize your components. Thus, for most applications, the resulting architecture will employ multiple modules, each encapsulating a closely related set of capabilities.

The ``@Module()`` decorator takes a single object whose properties describe the module:
* providers
* controllers
* imports
* exports

## Shared modules
In Nest, modules are singletons by default, and thus you can share the same instance of any provider between multiple modules effortlessly.

Every module is automatically a shared module. Once created it can be reused by any module. Let's imagine that we want to share an instance of the CatsService between several other modules. In order to do that, we first need to export the CatsService provider by adding it to the module's exports array, as shown below:
```ts
@Module({
  controllers: [CatsController],
  providers: [CatsService],
  exports: [CatsService]
})
export class CatsModule {}
```

## Dynamic modules
The Modules chapter covers the basics of Nest modules, and includes a brief introduction to dynamic modules. This chapter expands on the subject of dynamic modules. Upon completion, you should have a good grasp of what they are and how and when to use them.

The challenge is that the configuration module itself, since it's generic (similar to a "plugin"), needs to be customized by its consuming module. This is where dynamic modules come into play. Using dynamic module features, we can make our configuration module dynamic so that the consuming module can use an API to control how the configuration module is customized at the time it is imported.

In other words, dynamic modules provide an API for importing one module into another, and customizing the properties and behavior of that module when it is imported, as opposed to using the static bindings we've seen so far.

............









