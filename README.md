# optimizer
This is test query plan optimizer from source Postgres 14 make as extension. Only for experiment.


## interface

```
SELECT op_version();    // product version
 op_version
------------
 0.1
(1 row)
```

```
    SELECT op_on(); // set enable optimizer
```

```
    SELECT op_off(); // set disable optimizer
```

```
    SELECT op_off(); // set disable optimizer
```

```
	SELECT op_check();   // check on optimizer
	 op_check
	----------
	        0			 // 0 - off / 1 - on
	(1 row)
```
