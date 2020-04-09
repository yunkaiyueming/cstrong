#include <stdio.h>

#include "lauxlib.h"
#include "lualib.h"
#include "lua.h"

//编译 gcc main.c -o main -I /usr/local/include -llua 
//gcc main.c -o main -llua

lua_State *L;
	

// #define LUA_TNIL    0
// #define LUA_TBOOLEAN    1
// #define LUA_TLIGHTUSERDATA  2
// #define LUA_TNUMBER   3
// #define LUA_TSTRING   4
// #define LUA_TTABLE    5
// #define LUA_TFUNCTION   6
// #define LUA_TUSERDATA   7
// #define LUA_TTHREAD   8
void printLInfo(){
  int num = lua_gettop(L);

  printf("=====ptb======\n");
  for(int i=1;i<=num;i++){

    if(lua_type(L, -i)==LUA_TBOOLEAN){
        printf("%d:%d %s \n", -i, lua_toboolean(L, -i), lua_typename(L, lua_type(L, -i)));
    }else if (lua_type(L, -i)==LUA_TNUMBER){
      printf("%d:%f %s \n", -i, lua_tonumber(L, -i), lua_typename(L, lua_type(L, -i)));
    }else if (lua_type(L, -i)==LUA_TSTRING){
      printf("%d:%s %s  \n", -i, lua_tostring(L, -i), lua_typename(L, lua_type(L, -i)));
    }else if (lua_type(L, -i)==LUA_TFUNCTION){
      printf("%d:%s %s \n", -i, lua_tostring(L, -i), lua_typename(L, lua_type(L, -i)));
    }else{
      printf("%d:%s %s \n", -i, lua_tostring(L, -i), lua_typename(L, lua_type(L, -i)));
    }
  }
  printf("=====ptb======\n");
}

int main(int argc, char **argv){
	L = luaL_newstate();

  lua_pushstring(L, "aaaa");
  lua_pushstring(L, "bbbb");
  lua_pushstring(L, "cccc");
  lua_pushstring(L, "dddd");

  printLInfo();

  luaL_openlibs(L);
  luaL_dofile(L, "/Users/ray/Documents/C/clua/dispatch.lua");
  lua_getglobal(L, "dispatch");   //把全局变量 dispatch 里的值压栈，返回该值的类型。  
  lua_pushstring(L, "subv#1#2");


  printLInfo();

  printf("%d\n",lua_iscfunction(L, -2));
  if(lua_isfunction(L, -2)){
      printf("是lua函数\n");
  }else{
      printf("不是函数\n");
  }

  int r = lua_pcall(L, 1, 2, 0);  
  printLInfo();


  char *s = "local st = os.time();return (tostring(st))";
  luaL_dostring(L, s);

  printLInfo();

  lua_close(L);

	return 0;
}



















