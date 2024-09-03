
#line 1 "src/ratbox.ragel"
/// @file
/// @brief RatBox binary protocol parser (`ragel`)
/// @details https://www.colm.net/open-source/ragel/

/// @defgroup parser parser
/// @brief RatBox binary protocol parser (`ragel`)
/// @details https://www.colm.net/open-source/ragel/
/// @{

#line 22 "src/ratbox.ragel"

#line 13 "ratbox/parser.cpp"
static const int RatBox_start = 3;
static const int RatBox_first_final = 3;
static const int RatBox_error = 0;

static const int RatBox_en_main = 3;

#line 25 "src/ratbox.ragel"

/// @brief parse prepared binary buffer
/// @param[in] p packet start
/// @ingroup parser
void RatBox::parse(char *p) {
#line 22 "ratbox/parser.cpp"
    {
        cs = RatBox_start;
        ts = 0;
        te = 0;
        act = 0;
    }

#line 29 "src/ratbox.ragel"

#line 28 "ratbox/parser.cpp"
    {
        if (p == pe) goto _test_eof;
        switch (cs) {
        tr2 :
#line 19 "src/ratbox.ragel"
        {
            te = p + 1;
        }
            goto st3;
        st3 :
#line 1 "NONE"
        {
            ts = 0;
        }
            if (++p == pe) goto _test_eof3;
            case 3:
#line 1 "NONE"
            {
                ts = p;
            }
#line 42 "ratbox/parser.cpp"
                if ((*p) == 18u) goto st1;
                goto st0;
            st0:
                cs = 0;
                goto _out;
            st1:
                if (++p == pe) goto _test_eof1;
            case 1:
                if ((*p) == 52u) goto st2;
                goto st0;
            st2:
                if (++p == pe) goto _test_eof2;
            case 2:
                if ((*p) == 86u) goto tr2;
                goto st0;
        }
    _test_eof3:
        cs = 3;
        goto _test_eof;
    _test_eof1:
        cs = 1;
        goto _test_eof;
    _test_eof2:
        cs = 2;
        goto _test_eof;

    _test_eof : {}
    _out : {}
    }

#line 30 "src/ratbox.ragel"
}

/// @}
