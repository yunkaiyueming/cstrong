#include "lauxlib.h"
#include "lualib.h"
#include "lua.h"

//待注册的C函数，该函数的声明形式在上面的例子中已经给出。
static int add(lua_State* L)
{
    double op1 = luaL_checknumber(L,1);
    double op2 = luaL_checknumber(L,2);
    lua_pushnumber(L,op1 + op2);
    return 1;
}

static int sub(lua_State* L)
 {
    double op1 = luaL_checknumber(L,1);
    double op2 = luaL_checknumber(L,2);
    lua_pushnumber(L,op1 - op2);
    return 1;
}

static int sum(lua_State* L)
{
    double op1 = luaL_checknumber(L,1);
    double op2 = luaL_checknumber(L,2);
    lua_pushnumber(L, op1 * op2);
    return 1;
}


static int addstring(lua_State* L)
{
    const char *str1 = luaL_checkstring(L,1);
    lua_pushnumber(L, 1);
    return 1;
}

//luaL_Reg结构体的第一个字段为字符串，在注册时用于通知Lua该函数的名字。
//第一个字段为C函数指针。
//结构体数组中的最后一个元素的两个字段均为NULL，用于提示Lua注册函数已经到达数组的末尾。
static const struct  luaL_Reg mylibs[] = {
    {"add", add},
    {"sub", sub},
    {"sum", sum},
    {"addstring", addstring},
    {NULL, NULL}
};

//该C库的唯一入口函数。其函数签名等同于上面的注册函数。见如下几点说明：
//1. 我们可以将该函数简单的理解为模块的工厂函数。
//2. 其函数名必须为luaopen_xxx，其中xxx表示library名称。Lua代码require "xxx"需要与之对应。
//3. 在luaL_register的调用中，其第一个字符串参数为模块名"xxx"，第二个参数为待注册函数的数组。
//4. 需要强调的是，所有需要用到"xxx"的代码，不论C还是Lua，都必须保持一致，这是Lua的约定，
//   否则将无法调用。
int luaopen_mytestlib(lua_State* L)
{
    const char* libName = "mytestlib";
    luaL_newlib(L,mylibs);
    lua_pushvalue(L,-1);
    lua_setglobal(L,libName);
    return 1;
}
