void
dump_stack (lua_State *l)
{
	int i;
	int top = lua_gettop (l);
	for (i = 1; i <= top; i++) {	/* repeat for each level */
		int t = lua_type (l, i);
		switch (t) {
			case LUA_TSTRING:	/* strings */
				printf ("`%s'", lua_tostring (l, i));
				break;

			case LUA_TBOOLEAN:	/* booleans */
				printf (lua_toboolean (l, i) ? "true" : "false");
				break;

			case LUA_TNUMBER:	/* numbers */
				printf ("%g", lua_tonumber (l, i));
				break;

			default:	/* other values */
				printf ("%s", lua_typename (l, t));
				break;
		}
		printf ("	");	/* put a separator */
	}
	printf ("\n");	/* end the listing */
}

