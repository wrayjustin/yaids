---
title: Data Queues
permalink: /technical/queues
sort: 3
---
![YAIDS](/yaids.png)
# Data Queues

Data queues are created via a series of `structs` with a pointer to the subsequent `struct`.
This is combined with a separate "queue" `struct` containing pointers to the *first* and *last* data `structs`.
```
+-----------------+     +-----------------+     +-----------------+     +-----------------+
|                 |     |                 |     |                 |     |                 |
|  DATA           |     |  DATA           |     |  DATA           |     |  DATA           |
|                 |     |                 |     |                 |     |                 |
|          Next*-------->          Next*-------->          Next*-------->          Next*-------->NULL
+------^----------+     +-----------------+     +-----------------+     +------^----------+
       |                                                                       |
       |                                                                       |
+------|-----------------------------------------------------------------------|----------+
| First*                                                                   Last*          |
|                                                                                         |
|                                          QUEUE                                          |
|                                                                                         |
+-----------------------------------------------------------------------------------------+

```
