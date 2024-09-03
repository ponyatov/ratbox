
#line 1 "src/ratbox.ragel"
/// @file
/// @brief RatBox binary protocol parser (`ragel`)
/// @details https://www.colm.net/open-source/ragel/

/// @defgroup parser parser
/// @brief RatBox binary protocol parser (`ragel`)
/// @details https://www.colm.net/open-source/ragel/
/// @{

#include "ratbox.hpp"


#line 31 "src/ratbox.ragel"



#line 15 "ratbox/parser.cpp"
static const int RatBox_start = 4;
static const int RatBox_first_final = 4;
static const int RatBox_error = -1;

static const int RatBox_en_main = 4;


#line 34 "src/ratbox.ragel"

void RatBox::parse() {
    
#line 23 "ratbox/parser.cpp"
	{
	cs = RatBox_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 37 "src/ratbox.ragel"
    
#line 29 "ratbox/parser.cpp"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr0:
#line 26 "src/ratbox.ragel"
	{{p = ((te))-1;}{ token("    len"); }}
	goto st4;
tr4:
#line 25 "src/ratbox.ragel"
	{te = p+1;{ token("    mac"); }}
	goto st4;
tr5:
#line 27 "src/ratbox.ragel"
	{te = p+1;{ token("payload"); }}
	goto st4;
tr6:
#line 26 "src/ratbox.ragel"
	{te = p+1;{ token("    len"); }}
	goto st4;
tr8:
#line 26 "src/ratbox.ragel"
	{te = p;p--;{ token("    len"); }}
	goto st4;
st4:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 1 "NONE"
	{ts = p;}
#line 55 "ratbox/parser.cpp"
	if ( (*p) == 18u )
		goto tr7;
	if ( 10u <= (*p) && (*p) <= 20u )
		goto tr6;
	goto tr5;
tr7:
#line 1 "NONE"
	{te = p+1;}
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 67 "ratbox/parser.cpp"
	if ( (*p) == 52u )
		goto st0;
	goto tr8;
st0:
	if ( ++p == pe )
		goto _test_eof0;
case 0:
	if ( (*p) == 86u )
		goto st1;
	goto tr0;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	if ( (*p) == 120u )
		goto st2;
	goto tr0;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 154u )
		goto st3;
	goto tr0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	if ( (*p) == 188u )
		goto tr4;
	goto tr0;
	}
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof0: cs = 0; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 5: goto tr8;
	case 0: goto tr0;
	case 1: goto tr0;
	case 2: goto tr0;
	case 3: goto tr0;
	}
	}

	}

#line 38 "src/ratbox.ragel"
}

/// @}
