require "mytestlib"


-- bogon:libLua chris$ gcc -c -I /usr/local/include test.c    //编译不连接
-- bogon:libLua chris$ gcc -bundle -undefined dynamic_lookup -o mytestlib.so test.o  //连接生成动态库


local ret = mytestlib.add(100.0, 200.0)
print(ret)

local ret2 = mytestlib.sub(200.0, 10)
print(ret2)

local ret3 = mytestlib.sum(200.0, 10)
print(ret3)

local ret3 = mytestlib.addstring("hello")
print(ret3)