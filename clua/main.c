#include <stdio.h>

#include "lauxlib.h"
#include "lualib.h"
#include "lua.h"

//编译 gcc main.c -o main -I /usr/local/include -llua 
//gcc main.c -o main -llua

lua_State *L;

//c中调用lua获取结果
int luaadd(int x, int y){
    lua_getglobal(L, "dispatch"); //把全局变量 dispatch 里的值压栈，返回该值的类型。  
	lua_pushstring(L, "addv#1#2");
    int r = lua_pcall(L, 1, 2, 0);  
    if(r!=0){
    	printf("call lua function error %s\n",lua_tostring(L,-1));//返回错误，将错误压入到栈顶
		lua_close(L);
    }

 	int status = lua_toboolean(L, -1);
    printf("luaadd status:%d\n", status); 

   	int sum = (int)lua_tonumber(L, -2);
   	printf("%d\n",sum);

   	printf("-1: %s\n",lua_tostring(L,-1));
   	printf("-2: %s\n",lua_tostring(L,-2));
   	printf("-3: %s\n",lua_tostring(L,-3));
   	printf("-4: %s\n",lua_tostring(L,-4));

	//lua_pop(L,1);
	return sum;
}


int luasub(int x,int y){
	lua_getglobal(L, "dispatch");       
	lua_pushstring(L, "subv#1#2");
    int r = lua_pcall(L, 1, 2, 0);  

 	int status = lua_toboolean(L, -1);
    printf("lua sub status:%d\n", status); 

   	int sum = (int)lua_tonumber(L, -2);
   	printf("%d\n",sum);

	printf("-1: %s\n",lua_tostring(L,-1));
   	printf("-2: %s\n",lua_tostring(L,-2));
   	printf("-3: %s\n",lua_tostring(L,-3));
   	printf("-4: %s\n",lua_tostring(L,-4));

	//lua_pop(L,1);
	return sum;
}


const char * appendstr(int x,int y){
	lua_getglobal(L, "dispatch");       
	lua_pushstring(L, "appendV#haha");
    int r = lua_pcall(L, 1, 2, 0);  

 	int status = lua_toboolean(L, -1);
    printf("append status:%d\n", status); 

   	const char *sum = lua_tostring(L, -2);
   	printf("%s\n",sum);

	printf("-1: %s\n",lua_tostring(L,-1));
   	printf("-2: %s\n",lua_tostring(L,-2));
   	printf("-3: %s\n",lua_tostring(L,-3));
   	printf("-4: %s\n",lua_tostring(L,-4));

	//lua_pop(L,1);
	return sum;
}

//待Lua调用的C注册函数
int Getfunc(lua_State* L){
	lua_pushstring(L, "hello from c");
	return 1;
}

const char *regFunc(){ //c里调用 lua函数， lua函数包含了c函数
	lua_pushcfunction(L, Getfunc);
	lua_setglobal(L,"Getfunc");

	lua_getglobal(L, "dispatch");

	lua_pushstring(L, "getfunc#haha");
    int r = lua_pcall(L, 1, 2, 0);  //当函数调用完毕后，所有的参数以及函数本身都会出栈,而函数的返回值这时则被压栈

 	int status = lua_toboolean(L, -1);
    printf("regFunc status:%d\n", status); 

   	const char *sum = lua_tostring(L, -2);
   	printf("%s\n",sum);

	printf("-1: %s\n",lua_tostring(L,-1));
   	printf("-2: %s\n",lua_tostring(L,-2));
   	printf("-3: %s\n",lua_tostring(L,-3));
   	printf("-4: %s\n",lua_tostring(L,-4));

	//lua_pop(L,1);
	return sum;
}

int execluastr(){
	char *s = "local num=10000;print(num);";
	luaL_dostring(L, s); //如果没有错误，函数返回假； 有错则返回真。
	return 0;
}
	

int main(int argc, char **argv){
	L = luaL_newstate();
	
    luaL_openlibs(L);
	luaL_dofile(L, "/Users/ray/Documents/C/clua/dispatch.lua");
    //luaL_loadfile(L, "/Users/ray/Documents/C/clua/dispatch.lua");    

    int ret = luaadd(1,2);
    printf("add ret:%d\n", ret);


    int ret2 = luasub(1,2);
    printf("sub ret2:%d\n", ret2);


    const char *ret3 = appendstr(1,2);
    printf("append ret3:%s\n", ret3);


	const char *ret4 = regFunc();
    printf("regFunc ret4:%s\n", ret4);
    

    execluastr();

	// lua_pushstring(L, "subv#1#2");
 //    int r = lua_pcall(L, 1, 2, 0);      

	// int ret = lua_toboolean(L, -1);//最后返回的在栈顶
 //    printf("ret_status:%d\n", ret);

	// lua_pop(L, 1);
 //    const char *result = lua_tostring(L, -1);
 //    if(NULL!=result) {
 //        printf("ret:%s\n", result);
 //    }

    //或者不pop，直接获取栈中第二个元素
    // const char *result = lua_tostring(L, -2);
    // if(NULL!=result) {
    //     printf("ret:%s\n", result);
    // }

    lua_close(L);
	return 0;
}



















