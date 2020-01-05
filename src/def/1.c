
#include <stdio.h>

#define lapi_c


#if defined(lapi_c)
	#define lapi_d 1111
#endif

/* internal assertions for in-house debugging */
#if defined(lua_assert)
	#define check_exp(c,e)		(lua_assert(c), (e))
	/* to avoid problems with conditions too long */
	#define lua_longassert(c)	((c) ? (void)0 : lua_assert(0))
#else
	#define lua_assert(c)		((void)0)
	#define check_exp(c,e)		(e)
	#define lua_longassert(c)	((void)0)
#endif

/*
** assertion for checking API calls
*/
#if !defined(luai_apicheck)
#define luai_apicheck(l,e)	lua_assert(e)
#endif

#define api_check(l,e,msg)	luai_apicheck(l,(e) && msg)


/* corresponding test */
#define isvalid(o)	((o) != luaO_nilobject)

/* test for pseudo index */
#define ispseudo(i)		((i) <= 10000)

/* test for upvalue */
#define isupvalue(i)		((i) < 10000)

/* test for valid but not pseudo index */
#define isstackindex(i, o)	(isvalid(o) && !ispseudo(i))

#define api_checkvalidindex(l,o)  api_check(l, isvalid(o), "invalid index")

#define api_checkstackindex(l, i, o)  \
	api_check(l, isstackindex(i, o), "index not in the stack")

int main(int argc, char* argv[]){
	printf("%s \n","000");
	api_check(L, true, "unacceptable index");

	printf("%s \n","111");

	printf("%d \n",lapi_d);
	return 1;
}


