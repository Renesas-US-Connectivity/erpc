/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 34 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"

#include "ErpcLexer.hpp"
#include "AstNode.hpp"
#include "Logging.hpp"
#include "format_string.hpp"

using namespace erpcgen;

/*! Our special location type. */
#define YYLTYPE token_loc_t

// this indicates that we're using our own type. it should be unset automatically
// but that's not working for some reason with the .hpp file.
#if defined(YYLTYPE_IS_TRIVIAL)
    #undef YYLTYPE_IS_TRIVIAL
    #define YYLTYPE_IS_TRIVIAL 0
#endif

/*! Default location action */
#define YYLLOC_DEFAULT(Current, Rhs, N) \
    do {        \
        if (N)  \
        {       \
            (Current).m_firstLine = YYRHSLOC(Rhs, 1).m_firstLine;   \
            (Current).m_lastLine = YYRHSLOC(Rhs, N).m_lastLine;     \
        }       \
        else    \
        {       \
            (Current).m_firstLine = (Current).m_lastLine = YYRHSLOC(Rhs, 0).m_lastLine; \
        }       \
    } while (0)

#line 104 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "erpcgen_parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOK_IDENT = 3,                  /* "identifier"  */
  YYSYMBOL_TOK_STRING_LITERAL = 4,         /* "string"  */
  YYSYMBOL_TOK_INT_LITERAL = 5,            /* "integer"  */
  YYSYMBOL_TOK_FLOAT_LITERAL = 6,          /* "float"  */
  YYSYMBOL_7_ = 7,                         /* '@'  */
  YYSYMBOL_8_ = 8,                         /* '('  */
  YYSYMBOL_9_ = 9,                         /* ')'  */
  YYSYMBOL_10_ = 10,                       /* '{'  */
  YYSYMBOL_11_ = 11,                       /* '}'  */
  YYSYMBOL_12_ = 12,                       /* '['  */
  YYSYMBOL_13_ = 13,                       /* ']'  */
  YYSYMBOL_14_ = 14,                       /* '<'  */
  YYSYMBOL_15_ = 15,                       /* '>'  */
  YYSYMBOL_16_ = 16,                       /* '='  */
  YYSYMBOL_17_ = 17,                       /* ','  */
  YYSYMBOL_18_ = 18,                       /* ';'  */
  YYSYMBOL_19_ = 19,                       /* ':'  */
  YYSYMBOL_20_ = 20,                       /* '+'  */
  YYSYMBOL_21_ = 21,                       /* '-'  */
  YYSYMBOL_22_ = 22,                       /* '*'  */
  YYSYMBOL_23_ = 23,                       /* '/'  */
  YYSYMBOL_24_ = 24,                       /* '%'  */
  YYSYMBOL_25_ = 25,                       /* '^'  */
  YYSYMBOL_26_ = 26,                       /* '~'  */
  YYSYMBOL_27_ = 27,                       /* '&'  */
  YYSYMBOL_28_ = 28,                       /* '|'  */
  YYSYMBOL_TOK_LSHIFT = 29,                /* "<<"  */
  YYSYMBOL_TOK_RSHIFT = 30,                /* ">>"  */
  YYSYMBOL_TOK_ARROW = 31,                 /* "->"  */
  YYSYMBOL_TOK_OPTIONS = 32,               /* "options"  */
  YYSYMBOL_TOK_CONST = 33,                 /* "const"  */
  YYSYMBOL_TOK_IMPORT = 34,                /* "import"  */
  YYSYMBOL_TOK_ENUM = 35,                  /* "enum"  */
  YYSYMBOL_TOK_STRUCT = 36,                /* "struct"  */
  YYSYMBOL_TOK_UNION = 37,                 /* "union"  */
  YYSYMBOL_TOK_SWITCH = 38,                /* "switch"  */
  YYSYMBOL_TOK_CASE = 39,                  /* "case"  */
  YYSYMBOL_TOK_DEFAULT = 40,               /* "default"  */
  YYSYMBOL_TOK_OPTIONAL = 41,              /* "optional"  */
  YYSYMBOL_TOK_BYREF = 42,                 /* "byref"  */
  YYSYMBOL_TOK_TYPE = 43,                  /* "type"  */
  YYSYMBOL_TOK_INTERFACE = 44,             /* "interface"  */
  YYSYMBOL_TOK_VERSION = 45,               /* "version"  */
  YYSYMBOL_TOK_IN = 46,                    /* "in"  */
  YYSYMBOL_TOK_OUT = 47,                   /* "out"  */
  YYSYMBOL_TOK_INOUT = 48,                 /* "inout"  */
  YYSYMBOL_TOK_ASYNC = 49,                 /* "async"  */
  YYSYMBOL_TOK_ONEWAY = 50,                /* "oneway"  */
  YYSYMBOL_TOK_LIST = 51,                  /* "list"  */
  YYSYMBOL_TOK_REF = 52,                   /* "ref"  */
  YYSYMBOL_TOK_TRUE = 53,                  /* "true"  */
  YYSYMBOL_TOK_FALSE = 54,                 /* "false"  */
  YYSYMBOL_TOK_VOID = 55,                  /* "void"  */
  YYSYMBOL_TOK_ML_COMMENT = 56,            /* "doxygen ml. comment"  */
  YYSYMBOL_TOK_IL_COMMENT = 57,            /* "doxygen il. comment"  */
  YYSYMBOL_TOK_PROGRAM = 58,               /* "program"  */
  YYSYMBOL_TOK_IFACE_SCOPE = 59,           /* "::"  */
  YYSYMBOL_TOK_CHILDREN = 60,              /* TOK_CHILDREN  */
  YYSYMBOL_TOK_ENUM_MEMBER = 61,           /* TOK_ENUM_MEMBER  */
  YYSYMBOL_TOK_STRUCT_MEMBER = 62,         /* TOK_STRUCT_MEMBER  */
  YYSYMBOL_TOK_UNION_CASE = 63,            /* TOK_UNION_CASE  */
  YYSYMBOL_TOK_FUNCTION = 64,              /* TOK_FUNCTION  */
  YYSYMBOL_TOK_PARAM = 65,                 /* TOK_PARAM  */
  YYSYMBOL_TOK_RETURN = 66,                /* TOK_RETURN  */
  YYSYMBOL_TOK_EXPR = 67,                  /* TOK_EXPR  */
  YYSYMBOL_TOK_ANNOTATION = 68,            /* TOK_ANNOTATION  */
  YYSYMBOL_TOK_UNARY_NEGATE = 69,          /* TOK_UNARY_NEGATE  */
  YYSYMBOL_TOK_ARRAY = 70,                 /* TOK_ARRAY  */
  YYSYMBOL_UNARY_OP = 71,                  /* UNARY_OP  */
  YYSYMBOL_YYACCEPT = 72,                  /* $accept  */
  YYSYMBOL_root_def = 73,                  /* root_def  */
  YYSYMBOL_program = 74,                   /* program  */
  YYSYMBOL_def_list = 75,                  /* def_list  */
  YYSYMBOL_definition = 76,                /* definition  */
  YYSYMBOL_definition_base = 77,           /* definition_base  */
  YYSYMBOL_import_stmt = 78,               /* import_stmt  */
  YYSYMBOL_const_def = 79,                 /* const_def  */
  YYSYMBOL_enum_def = 80,                  /* enum_def  */
  YYSYMBOL_enumerator_list_opt = 81,       /* enumerator_list_opt  */
  YYSYMBOL_comma_opt = 82,                 /* comma_opt  */
  YYSYMBOL_semi_opt = 83,                  /* semi_opt  */
  YYSYMBOL_comma_semi_opt = 84,            /* comma_semi_opt  */
  YYSYMBOL_enumerator_list = 85,           /* enumerator_list  */
  YYSYMBOL_enumerator = 86,                /* enumerator  */
  YYSYMBOL_interface_def = 87,             /* interface_def  */
  YYSYMBOL_function_def_list_opt = 88,     /* function_def_list_opt  */
  YYSYMBOL_function_def_list = 89,         /* function_def_list  */
  YYSYMBOL_function_cb_type_def = 90,      /* function_cb_type_def  */
  YYSYMBOL_function_cb_type_list = 91,     /* function_cb_type_list  */
  YYSYMBOL_function_def = 92,              /* function_def  */
  YYSYMBOL_function_type_base_def = 93,    /* function_type_base_def  */
  YYSYMBOL_function_type_def = 94,         /* function_type_def  */
  YYSYMBOL_function_return_type = 95,      /* function_return_type  */
  YYSYMBOL_param_list_opt = 96,            /* param_list_opt  */
  YYSYMBOL_param_list_opt_in = 97,         /* param_list_opt_in  */
  YYSYMBOL_param_list = 98,                /* param_list  */
  YYSYMBOL_param_list_in = 99,             /* param_list_in  */
  YYSYMBOL_param_def = 100,                /* param_def  */
  YYSYMBOL_param_def_in = 101,             /* param_def_in  */
  YYSYMBOL_param_dir_in = 102,             /* param_dir_in  */
  YYSYMBOL_param_dir = 103,                /* param_dir  */
  YYSYMBOL_callback_def = 104,             /* callback_def  */
  YYSYMBOL_callback_param_list_opt = 105,  /* callback_param_list_opt  */
  YYSYMBOL_callback_param_list = 106,      /* callback_param_list  */
  YYSYMBOL_callback_param = 107,           /* callback_param  */
  YYSYMBOL_typedef_def = 108,              /* typedef_def  */
  YYSYMBOL_struct_def = 109,               /* struct_def  */
  YYSYMBOL_struct_member_list = 110,       /* struct_member_list  */
  YYSYMBOL_struct_member = 111,            /* struct_member  */
  YYSYMBOL_struct_member_options_list = 112, /* struct_member_options_list  */
  YYSYMBOL_struct_member_options = 113,    /* struct_member_options  */
  YYSYMBOL_struct_data_type = 114,         /* struct_data_type  */
  YYSYMBOL_union_def = 115,                /* union_def  */
  YYSYMBOL_union_type_def = 116,           /* union_type_def  */
  YYSYMBOL_union_case_list = 117,          /* union_case_list  */
  YYSYMBOL_union_case = 118,               /* union_case  */
  YYSYMBOL_union_case_expr_list = 119,     /* union_case_expr_list  */
  YYSYMBOL_union_member_list_opt = 120,    /* union_member_list_opt  */
  YYSYMBOL_union_member_list = 121,        /* union_member_list  */
  YYSYMBOL_union_member = 122,             /* union_member  */
  YYSYMBOL_simple_data_type_scope = 123,   /* simple_data_type_scope  */
  YYSYMBOL_simple_data_type = 124,         /* simple_data_type  */
  YYSYMBOL_data_type = 125,                /* data_type  */
  YYSYMBOL_typename = 126,                 /* typename  */
  YYSYMBOL_name_opt = 127,                 /* name_opt  */
  YYSYMBOL_list_type = 128,                /* list_type  */
  YYSYMBOL_array_type = 129,               /* array_type  */
  YYSYMBOL_annotation_list_opt = 130,      /* annotation_list_opt  */
  YYSYMBOL_annotation_list = 131,          /* annotation_list  */
  YYSYMBOL_annotation = 132,               /* annotation  */
  YYSYMBOL_annotation_value_opt = 133,     /* annotation_value_opt  */
  YYSYMBOL_const_expr = 134,               /* const_expr  */
  YYSYMBOL_doxy_ml_comment_opt = 135,      /* doxy_ml_comment_opt  */
  YYSYMBOL_doxy_ml_comment = 136,          /* doxy_ml_comment  */
  YYSYMBOL_doxy_il_comment_opt = 137,      /* doxy_il_comment_opt  */
  YYSYMBOL_int_const_expr = 138,           /* int_const_expr  */
  YYSYMBOL_expr = 139,                     /* expr  */
  YYSYMBOL_unary_expr = 140,               /* unary_expr  */
  YYSYMBOL_int_value = 141,                /* int_value  */
  YYSYMBOL_float_value = 142,              /* float_value  */
  YYSYMBOL_string_literal = 143,           /* string_literal  */
  YYSYMBOL_ident = 144,                    /* ident  */
  YYSYMBOL_ident_opt = 145                 /* ident_opt  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 80 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"

/*! Forward declaration of yylex(). */
static int yylex(YYSTYPE * lvalp, YYLTYPE * yylloc, ErpcLexer * lexer);

/*! Forward declaration of error handling function. */
static void yyerror(YYLTYPE * yylloc, ErpcLexer * lexer, AstNode ** resultAST, const char * error);
#line 88 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"

/*! Function for merge two strings */
static AstNode * mergeString(Token * t1, Token * t2);

/*! Function for merge two token locations */
token_loc_t mergeLocation(const token_loc_t & l1, const token_loc_t & l2);

#line 299 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   337

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  263

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    24,    27,     2,
       8,     9,    22,    20,    17,    21,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    19,    18,
      14,    16,    15,     2,     7,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    12,     2,    13,    25,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    10,    28,    11,    26,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   260,   260,   266,   272,   277,   291,   300,   310,   314,
     322,   326,   330,   334,   338,   342,   348,   358,   370,   379,
     384,   389,   390,   393,   394,   397,   398,   399,   405,   411,
     421,   430,   444,   453,   458,   467,   472,   477,   485,   496,
     501,   508,   519,   523,   532,   540,   556,   562,   570,   574,
     579,   585,   590,   598,   603,   610,   615,   625,   636,   650,
     655,   659,   663,   667,   676,   684,   695,   700,   706,   711,
     718,   732,   743,   749,   760,   765,   775,   788,   793,   799,
     803,   810,   814,   820,   828,   835,   843,   848,   856,   862,
     871,   876,   884,   888,   894,   900,   906,   913,   926,   932,
     939,   943,   947,   953,   957,   961,   967,   973,   978,   986,
     996,  1006,  1011,  1019,  1024,  1034,  1041,  1051,  1055,  1060,
    1065,  1069,  1076,  1081,  1086,  1096,  1103,  1115,  1123,  1130,
    1134,  1138,  1142,  1148,  1154,  1160,  1166,  1172,  1178,  1184,
    1190,  1196,  1202,  1206,  1213,  1217,  1222,  1229,  1233,  1237,
    1243,  1249,  1253,  1259,  1265,  1270
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"identifier\"",
  "\"string\"", "\"integer\"", "\"float\"", "'@'", "'('", "')'", "'{'",
  "'}'", "'['", "']'", "'<'", "'>'", "'='", "','", "';'", "':'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'^'", "'~'", "'&'", "'|'", "\"<<\"",
  "\">>\"", "\"->\"", "\"options\"", "\"const\"", "\"import\"", "\"enum\"",
  "\"struct\"", "\"union\"", "\"switch\"", "\"case\"", "\"default\"",
  "\"optional\"", "\"byref\"", "\"type\"", "\"interface\"", "\"version\"",
  "\"in\"", "\"out\"", "\"inout\"", "\"async\"", "\"oneway\"", "\"list\"",
  "\"ref\"", "\"true\"", "\"false\"", "\"void\"",
  "\"doxygen ml. comment\"", "\"doxygen il. comment\"", "\"program\"",
  "\"::\"", "TOK_CHILDREN", "TOK_ENUM_MEMBER", "TOK_STRUCT_MEMBER",
  "TOK_UNION_CASE", "TOK_FUNCTION", "TOK_PARAM", "TOK_RETURN", "TOK_EXPR",
  "TOK_ANNOTATION", "TOK_UNARY_NEGATE", "TOK_ARRAY", "UNARY_OP", "$accept",
  "root_def", "program", "def_list", "definition", "definition_base",
  "import_stmt", "const_def", "enum_def", "enumerator_list_opt",
  "comma_opt", "semi_opt", "comma_semi_opt", "enumerator_list",
  "enumerator", "interface_def", "function_def_list_opt",
  "function_def_list", "function_cb_type_def", "function_cb_type_list",
  "function_def", "function_type_base_def", "function_type_def",
  "function_return_type", "param_list_opt", "param_list_opt_in",
  "param_list", "param_list_in", "param_def", "param_def_in",
  "param_dir_in", "param_dir", "callback_def", "callback_param_list_opt",
  "callback_param_list", "callback_param", "typedef_def", "struct_def",
  "struct_member_list", "struct_member", "struct_member_options_list",
  "struct_member_options", "struct_data_type", "union_def",
  "union_type_def", "union_case_list", "union_case",
  "union_case_expr_list", "union_member_list_opt", "union_member_list",
  "union_member", "simple_data_type_scope", "simple_data_type",
  "data_type", "typename", "name_opt", "list_type", "array_type",
  "annotation_list_opt", "annotation_list", "annotation",
  "annotation_value_opt", "const_expr", "doxy_ml_comment_opt",
  "doxy_ml_comment", "doxy_il_comment_opt", "int_const_expr", "expr",
  "unary_expr", "int_value", "float_value", "string_literal", "ident",
  "ident_opt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-183)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-124)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,    32,  -183,    42,   -12,    17,  -183,  -183,    59,    -2,
    -183,  -183,    19,    59,  -183,    71,   162,    59,  -183,  -183,
     234,  -183,    37,    25,    71,    71,    71,    71,    71,    71,
      93,  -183,  -183,  -183,  -183,  -183,  -183,  -183,    26,    71,
    -183,   119,    97,  -183,  -183,  -183,  -183,   124,  -183,   128,
     134,   136,   135,   149,    93,  -183,  -183,  -183,  -183,  -183,
     188,  -183,   188,   188,   188,  -183,  -183,   164,  -183,   259,
    -183,  -183,  -183,   173,  -183,   179,    25,   188,   174,    13,
     151,    82,    61,     9,  -183,   132,   236,  -183,  -183,  -183,
    -183,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,  -183,  -183,   133,   198,    99,   181,    13,  -183,    71,
      14,  -183,  -183,   188,   197,   116,  -183,  -183,  -183,   215,
    -183,   217,    22,  -183,   151,  -183,    59,  -183,  -183,   145,
     145,  -183,  -183,  -183,   281,   292,   270,   201,   201,  -183,
    -183,  -183,  -183,  -183,    94,  -183,  -183,    40,    43,  -183,
      84,  -183,  -183,  -183,  -183,    59,  -183,  -183,    56,   188,
     212,   222,  -183,  -183,  -183,    71,  -183,   215,   188,    84,
    -183,  -183,   102,  -183,  -183,    18,    18,    71,   163,  -183,
    -183,   127,    59,  -183,  -183,    71,    59,  -183,  -183,  -183,
      47,   163,   224,   227,  -183,  -183,  -183,   117,   230,   212,
     132,   253,    93,    97,  -183,    46,   132,  -183,  -183,  -183,
    -183,   263,   226,  -183,  -183,    25,    71,  -183,   229,  -183,
      59,   132,   264,   251,  -183,    25,   243,   156,    71,   215,
     216,   267,    31,  -183,  -183,   132,    82,   132,    93,  -183,
     239,    71,    30,  -183,  -183,    59,    71,  -183,    71,   143,
    -183,  -183,    59,  -183,  -183,    25,  -183,  -183,  -183,  -183,
     132,  -183,   215
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     123,     0,   124,     0,   123,   123,     6,     8,   112,   122,
      16,     1,   123,   112,     7,     0,     0,   111,   113,   125,
       0,   153,   119,     0,   108,   108,     0,     0,     0,     0,
      24,    10,    11,    15,    14,    12,    13,   114,     0,     0,
     116,     0,     0,   102,   100,   101,   106,     0,   107,     0,
      73,    85,     0,     0,    24,    23,   127,   151,   147,   150,
       0,   118,     0,     0,     0,   148,   149,     0,   120,   128,
     142,   129,   130,   121,   131,   119,     0,     0,     0,    20,
     123,     0,     0,   123,     5,     9,     0,   144,   145,   146,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   152,   115,     0,     0,     0,     0,    19,    28,     0,
     123,    74,    78,     0,     0,     0,    86,   105,   104,   103,
      71,     0,   123,    39,   123,    36,   112,   126,   143,   132,
     133,   134,   135,   136,   139,   137,   138,   140,   141,   109,
     110,    17,    18,    29,   112,    72,    75,     0,     0,    90,
     123,    84,    87,    32,    37,   112,    40,    35,     0,     0,
      22,     0,    79,    80,    77,     0,    82,    81,     0,   123,
      93,    89,   123,    95,    78,     0,     0,     0,    27,    42,
      43,     0,   112,    21,   127,     0,   112,    91,    88,    96,
       0,    27,     0,     0,    25,    26,   127,    60,    64,    22,
      31,     0,    24,     0,   127,    60,    41,    59,    62,    63,
      49,     0,    48,    53,    61,     0,    67,   127,     0,   127,
     112,    38,     0,    51,    55,     0,     0,    60,   155,    99,
     106,     0,    22,    68,    70,    30,     0,    76,    24,    45,
      60,   155,   112,    54,   154,   112,     0,    65,     0,     0,
     127,    56,   112,    47,    44,     0,    57,    98,    69,    83,
      97,    58,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,  -183,  -183,   294,   103,  -183,  -183,  -183,   214,  -183,
    -116,   -53,   115,  -183,   200,  -183,  -183,  -183,   185,  -183,
      62,  -183,   141,  -183,  -183,  -183,  -183,  -183,    91,    79,
    -182,  -183,  -183,  -183,  -183,    72,  -183,   241,  -183,   218,
     150,  -183,  -183,  -183,  -183,    89,  -112,  -183,   157,  -183,
     158,   104,   -19,  -183,    81,   306,  -183,  -183,    -8,  -183,
     315,   258,   231,     7,  -183,  -178,   -75,   155,  -183,  -183,
    -183,  -183,   -15,    96
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,     6,    30,     7,    31,    32,   106,
     184,    56,   196,   107,   108,    33,   121,   122,   123,   124,
     125,   178,   179,   254,   211,   222,   212,   223,   213,   224,
     214,   215,   180,   231,   232,   233,    34,    35,   110,   111,
     147,   164,   165,   166,    36,   115,   116,   148,   171,   172,
     173,   228,   229,   120,    43,    47,    44,    45,    16,    17,
      18,    40,    67,    13,     9,    85,    68,    69,    70,    71,
      72,    73,    74,   245
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      22,    84,   104,   152,    42,    20,   200,     8,    46,    48,
      50,    51,    52,    53,    54,    -4,  -123,    -3,   206,    -2,
     -34,    21,     1,   225,    75,   145,   221,    78,    21,    21,
      57,    58,    59,   -33,    60,    61,    10,    15,   149,   235,
     -66,   237,    11,    21,     2,    38,    62,    63,   183,     1,
      21,     1,    64,     1,    19,   -52,    39,   103,   225,    21,
     168,    46,   169,   119,    21,     2,    15,    46,   177,     2,
       2,     2,   260,     2,    21,     2,    41,   161,     2,    65,
      66,   162,   163,   217,   182,   253,   109,   112,   162,   163,
     126,    41,   207,   187,   144,   -94,    24,    25,    41,   176,
      21,    15,    21,    57,    58,    59,   177,    60,    14,    77,
     159,    55,    41,   -92,   109,    14,   248,   112,   158,    62,
      63,   113,   114,   -94,   -94,    64,   -50,   151,   167,   155,
      21,   126,    46,    76,    79,   197,   160,   152,    80,   170,
       2,   -92,   -92,   181,  -107,    77,    81,   175,   139,   219,
     186,    82,    65,    66,   259,   113,   114,   174,     2,    83,
     181,   192,   193,   207,   208,   209,   198,    93,    94,    95,
     201,   203,   210,    90,   199,    46,   174,   101,   202,   174,
     194,   195,   113,   114,   154,   250,   157,    38,   220,   127,
     105,    21,   142,    58,    59,    23,    60,    24,    25,    26,
     230,   234,   207,   208,   209,    27,    28,     2,    62,    63,
     230,   140,   238,   244,    64,    86,   150,    87,    88,    89,
      29,    91,    92,    93,    94,    95,   244,    77,   153,   183,
     185,    46,   197,   234,   255,   205,   262,   256,   216,   236,
      46,    65,    66,   227,   261,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,    91,    92,    93,    94,
      95,    96,   218,    97,    98,    99,   100,    23,   240,    24,
      25,    26,   226,   239,   242,   246,   247,    27,    28,    91,
      92,    93,    94,    95,    96,   207,    97,    98,    99,   100,
      91,    92,    93,    94,    95,    96,   117,    97,    12,    99,
     100,    91,    92,    93,    94,    95,   204,   143,    97,   156,
      99,   100,    91,    92,    93,    94,    95,   191,   243,   251,
     258,    99,   100,   118,   190,   249,   188,   257,   146,   241,
     189,    49,    37,   102,     0,     0,   141,   252
};

static const yytype_int16 yycheck[] =
{
      15,    54,    77,   115,    23,    13,   184,     0,    23,    24,
      25,    26,    27,    28,    29,     0,     3,     0,   196,     0,
      11,     3,    34,   205,    39,    11,   204,    42,     3,     3,
       4,     5,     6,    11,     8,     9,     4,     7,   113,   217,
       9,   219,     0,     3,    56,     8,    20,    21,    17,    34,
       3,    34,    26,    34,    56,     9,    19,    76,   240,     3,
      17,    76,    19,    82,     3,    56,     7,    82,    50,    56,
      56,    56,   250,    56,     3,    56,    51,    37,    56,    53,
      54,    41,    42,   199,   159,    55,    79,    80,    41,    42,
      83,    51,    46,   168,   109,    11,    35,    36,    51,    43,
       3,     7,     3,     4,     5,     6,    50,     8,     5,    12,
      16,    18,    51,    11,   107,    12,   232,   110,   126,    20,
      21,    39,    40,    39,    40,    26,     9,    11,   147,   122,
       3,   124,   147,    14,    10,     8,   144,   249,    10,    55,
      56,    39,    40,   158,    10,    12,    10,   155,    15,   202,
     165,    16,    53,    54,    11,    39,    40,   150,    56,    10,
     175,   176,   177,    46,    47,    48,   181,    22,    23,    24,
     185,   190,    55,     9,   182,   190,   169,     4,   186,   172,
      17,    18,    39,    40,   122,   238,   124,     8,   203,    57,
      16,     3,    11,     5,     6,    33,     8,    35,    36,    37,
     215,   216,    46,    47,    48,    43,    44,    56,    20,    21,
     225,    13,   220,   228,    26,    60,    19,    62,    63,    64,
      58,    20,    21,    22,    23,    24,   241,    12,    11,    17,
       8,   246,     8,   248,   242,     8,   255,   245,     8,    10,
     255,    53,    54,    17,   252,     9,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    20,    21,    22,    23,
      24,    25,     9,    27,    28,    29,    30,    33,    17,    35,
      36,    37,     9,     9,    31,    59,     9,    43,    44,    20,
      21,    22,    23,    24,    25,    46,    27,    28,    29,    30,
      20,    21,    22,    23,    24,    25,    82,    27,     4,    29,
      30,    20,    21,    22,    23,    24,   191,   107,    27,   124,
      29,    30,    20,    21,    22,    23,    24,   176,   227,   240,
     248,    29,    30,    82,   174,   236,   169,   246,   110,   225,
     172,    25,    17,    75,    -1,    -1,   105,   241
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    56,    73,    74,    75,    76,    78,   135,   136,
       4,     0,    75,   135,    76,     7,   130,   131,   132,    56,
     130,     3,   144,    33,    35,    36,    37,    43,    44,    58,
      77,    79,    80,    87,   108,   109,   116,   132,     8,    19,
     133,    51,   124,   126,   128,   129,   144,   127,   144,   127,
     144,   144,   144,   144,   144,    18,    83,     4,     5,     6,
       8,     9,    20,    21,    26,    53,    54,   134,   138,   139,
     140,   141,   142,   143,   144,   144,    14,    12,   144,    10,
      10,    10,    16,    10,    83,   137,   139,   139,   139,   139,
       9,    20,    21,    22,    23,    24,    25,    27,    28,    29,
      30,     4,   133,   124,   138,    16,    81,    85,    86,   135,
     110,   111,   135,    39,    40,   117,   118,    80,   109,   124,
     125,    88,    89,    90,    91,    92,   135,    57,     9,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,    15,
      13,   134,    11,    86,   144,    11,   111,   112,   119,   138,
      19,    11,   118,    11,    92,   135,    90,    92,   130,    16,
     130,    37,    41,    42,   113,   114,   115,   124,    17,    19,
      55,   120,   121,   122,   135,   130,    43,    50,    93,    94,
     104,   144,   138,    17,    82,     8,   144,   138,   120,   122,
     112,    94,   144,   144,    17,    18,    84,     8,   144,   130,
     137,   144,   130,   124,    84,     8,   137,    46,    47,    48,
      55,    96,    98,   100,   102,   103,     8,    82,     9,    83,
     144,   137,    97,    99,   101,   102,     9,    17,   123,   124,
     144,   105,   106,   107,   144,   137,    10,   137,   130,     9,
      17,   123,    31,   100,   144,   145,    59,     9,    82,   117,
      83,   101,   145,    55,    95,   130,   130,   126,   107,    11,
     137,   130,   124
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    73,    73,    74,    75,    75,    76,    76,
      77,    77,    77,    77,    77,    77,    78,    79,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    84,    85,    85,
      86,    86,    87,    88,    88,    89,    89,    89,    90,    91,
      91,    92,    93,    93,    94,    94,    95,    95,    96,    96,
      96,    97,    97,    98,    98,    99,    99,   100,   101,   102,
     102,   103,   103,   103,   104,   104,   105,   105,   106,   106,
     107,   108,   109,   109,   110,   110,   111,   112,   112,   113,
     113,   114,   114,   115,   116,   116,   117,   117,   118,   118,
     119,   119,   120,   120,   120,   121,   121,   122,   123,   123,
     124,   124,   124,   125,   125,   125,   126,   127,   127,   128,
     129,   130,   130,   131,   131,   132,   132,   133,   133,   133,
     134,   134,   135,   135,   136,   136,   137,   137,   138,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   140,   140,   140,   141,   141,   141,
     142,   143,   143,   144,   145,   145
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     0,     5,     1,     2,     1,     5,
       1,     1,     1,     1,     1,     1,     2,     5,     5,     1,
       0,     1,     0,     1,     0,     1,     1,     0,     1,     2,
       7,     5,     5,     1,     0,     2,     1,     2,     6,     1,
       2,     5,     1,     1,     6,     5,     2,     1,     1,     1,
       0,     1,     0,     1,     3,     1,     3,     4,     4,     1,
       0,     1,     1,     1,     2,     5,     1,     0,     1,     3,
       1,     4,     5,     2,     1,     2,     7,     2,     0,     1,
       1,     1,     1,     7,     5,     2,     1,     2,     4,     3,
       1,     3,     1,     1,     0,     1,     2,     7,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     4,
       4,     1,     0,     1,     2,     5,     3,     3,     2,     0,
       1,     1,     1,     0,     1,     2,     2,     0,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     2,     2,     2,     1,     1,     1,
       1,     1,     2,     1,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, lexer, resultAST, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, lexer, resultAST); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, erpcgen::ErpcLexer * lexer, erpcgen::AstNode ** resultAST)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (lexer);
  YY_USE (resultAST);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, erpcgen::ErpcLexer * lexer, erpcgen::AstNode ** resultAST)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, lexer, resultAST);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, erpcgen::ErpcLexer * lexer, erpcgen::AstNode ** resultAST)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), lexer, resultAST);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, lexer, resultAST); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, erpcgen::ErpcLexer * lexer, erpcgen::AstNode ** resultAST)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (lexer);
  YY_USE (resultAST);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_TOK_IDENT: /* "identifier"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1582 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_STRING_LITERAL: /* "string"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1588 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_INT_LITERAL: /* "integer"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1594 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_FLOAT_LITERAL: /* "float"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1600 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_7_: /* '@'  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1606 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_8_: /* '('  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1612 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_9_: /* ')'  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1618 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_10_: /* '{'  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1624 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_11_: /* '}'  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1630 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_12_: /* '['  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1636 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_13_: /* ']'  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1642 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_14_: /* '<'  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1648 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_15_: /* '>'  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1654 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_16_: /* '='  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1660 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_17_: /* ','  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1666 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_18_: /* ';'  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1672 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_19_: /* ':'  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1678 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_20_: /* '+'  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1684 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_21_: /* '-'  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1690 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_22_: /* '*'  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1696 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_23_: /* '/'  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1702 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_24_: /* '%'  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1708 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_25_: /* '^'  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1714 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_26_: /* '~'  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1720 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_27_: /* '&'  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1726 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_28_: /* '|'  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1732 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_LSHIFT: /* "<<"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1738 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_RSHIFT: /* ">>"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1744 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_ARROW: /* "->"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1750 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_OPTIONS: /* "options"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1756 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_CONST: /* "const"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1762 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_IMPORT: /* "import"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1768 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_ENUM: /* "enum"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1774 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_STRUCT: /* "struct"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1780 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_UNION: /* "union"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1786 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_SWITCH: /* "switch"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1792 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_CASE: /* "case"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1798 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_DEFAULT: /* "default"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1804 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_OPTIONAL: /* "optional"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1810 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_BYREF: /* "byref"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1816 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_TYPE: /* "type"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1822 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_INTERFACE: /* "interface"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1828 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_VERSION: /* "version"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1834 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_IN: /* "in"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1840 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_OUT: /* "out"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1846 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_INOUT: /* "inout"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1852 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_ASYNC: /* "async"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1858 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_ONEWAY: /* "oneway"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1864 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_LIST: /* "list"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1870 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_REF: /* "ref"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1876 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_TRUE: /* "true"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1882 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_FALSE: /* "false"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1888 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_VOID: /* "void"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1894 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_ML_COMMENT: /* "doxygen ml. comment"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1900 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_IL_COMMENT: /* "doxygen il. comment"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1906 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_PROGRAM: /* "program"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1912 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_IFACE_SCOPE: /* "::"  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1918 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_CHILDREN: /* TOK_CHILDREN  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1924 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_ENUM_MEMBER: /* TOK_ENUM_MEMBER  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1930 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_STRUCT_MEMBER: /* TOK_STRUCT_MEMBER  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1936 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_UNION_CASE: /* TOK_UNION_CASE  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1942 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_FUNCTION: /* TOK_FUNCTION  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1948 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_PARAM: /* TOK_PARAM  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1954 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_RETURN: /* TOK_RETURN  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1960 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_EXPR: /* TOK_EXPR  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1966 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_ANNOTATION: /* TOK_ANNOTATION  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1972 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_UNARY_NEGATE: /* TOK_UNARY_NEGATE  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1978 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_TOK_ARRAY: /* TOK_ARRAY  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1984 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_param_dir_in: /* param_dir_in  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1990 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

    case YYSYMBOL_param_dir: /* param_dir  */
#line 255 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
            { if (((*yyvaluep).m_token)) { delete ((*yyvaluep).m_token); } }
#line 1996 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (erpcgen::ErpcLexer * lexer, erpcgen::AstNode ** resultAST)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, lexer);
    }

  if (yychar <= END)
    {
      yychar = END;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* root_def: program def_list  */
#line 261 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            *resultAST = new AstNode(Token(TOK_CHILDREN));
                            (*resultAST)->appendChild((yyvsp[-1].m_ast));
                            (*resultAST)->appendChild((yyvsp[0].m_ast));
                        }
#line 2306 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 3: /* root_def: def_list  */
#line 267 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            *resultAST = new AstNode(Token(TOK_CHILDREN));
                            (*resultAST)->appendChild((yyvsp[0].m_ast));
                        }
#line 2315 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 4: /* root_def: %empty  */
#line 272 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            *resultAST = new AstNode(Token(TOK_CHILDREN));
                        }
#line 2323 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 5: /* program: doxy_ml_comment_opt annotation_list_opt "program" ident semi_opt  */
#line 278 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            AstNode * prog  = new AstNode(Token(TOK_PROGRAM));
                            prog->appendChild(new AstNode(*(yyvsp[-1].m_ast)));
                            prog->appendChild((yyvsp[-3].m_ast));
                            prog->appendChild((yyvsp[-4].m_ast));
                            (yyval.m_ast) = prog;
                        }
#line 2335 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 6: /* def_list: definition  */
#line 292 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            AstNode * l = new AstNode(Token(TOK_CHILDREN));
                            if ((yyvsp[0].m_ast))
                            {
                                l->appendChild((yyvsp[0].m_ast));
                            }
                            (yyval.m_ast) = l;
                        }
#line 2348 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 7: /* def_list: def_list definition  */
#line 301 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            if ((yyvsp[0].m_ast))
                            {
                                (yyvsp[-1].m_ast)->appendChild((yyvsp[0].m_ast));
                            }
                            (yyval.m_ast) = (yyvsp[-1].m_ast);
                        }
#line 2360 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 8: /* definition: import_stmt  */
#line 311 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = NULL;
                        }
#line 2368 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 9: /* definition: doxy_ml_comment_opt annotation_list_opt definition_base semi_opt doxy_il_comment_opt  */
#line 315 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[-2].m_ast);
                            (yyval.m_ast)->appendChild((yyvsp[-3].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-4].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 2379 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 10: /* definition_base: const_def  */
#line 323 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 2387 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 11: /* definition_base: enum_def  */
#line 327 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 2395 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 12: /* definition_base: struct_def  */
#line 331 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 2403 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 13: /* definition_base: union_type_def  */
#line 335 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 2411 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 14: /* definition_base: typedef_def  */
#line 339 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 2419 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 15: /* definition_base: interface_def  */
#line 343 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 2427 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 16: /* import_stmt: "import" "string"  */
#line 349 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            std::string s = (yyvsp[0].m_token)->getStringValue();
                            lexer->pushFile(s);
                        }
#line 2436 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 17: /* const_def: "const" simple_data_type ident '=' const_expr  */
#line 359 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-4].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[-3].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 2447 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 18: /* enum_def: "enum" name_opt '{' enumerator_list_opt '}'  */
#line 371 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-4].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[-3].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-1].m_ast));
                        }
#line 2457 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 19: /* enumerator_list_opt: enumerator_list  */
#line 380 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 2465 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 20: /* enumerator_list_opt: %empty  */
#line 384 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = NULL;
                        }
#line 2473 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 28: /* enumerator_list: enumerator  */
#line 406 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            AstNode * n = new AstNode(Token(TOK_CHILDREN));
                            n->appendChild((yyvsp[0].m_ast));
                            (yyval.m_ast) = n;
                        }
#line 2483 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 29: /* enumerator_list: enumerator_list enumerator  */
#line 412 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyvsp[-1].m_ast)->appendChild((yyvsp[0].m_ast));
                            (yyval.m_ast) = (yyvsp[-1].m_ast);
                        }
#line 2492 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 30: /* enumerator: doxy_ml_comment_opt ident '=' int_const_expr annotation_list_opt comma_opt doxy_il_comment_opt  */
#line 422 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_ENUM_MEMBER, NULL, (yylsp[-6])));
                            (yyval.m_ast)->appendChild((yyvsp[-5].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-3].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-6].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 2505 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 31: /* enumerator: doxy_ml_comment_opt ident annotation_list_opt comma_opt doxy_il_comment_opt  */
#line 431 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_ENUM_MEMBER, NULL, (yylsp[-4])));
                            (yyval.m_ast)->appendChild((yyvsp[-3].m_ast));
                            (yyval.m_ast)->appendChild(NULL);
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-4].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 2518 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 32: /* interface_def: "interface" ident '{' function_def_list_opt '}'  */
#line 445 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-4].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[-3].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-1].m_ast));
                        }
#line 2528 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 33: /* function_def_list_opt: function_def_list  */
#line 454 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 2536 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 34: /* function_def_list_opt: %empty  */
#line 458 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = NULL;
                        }
#line 2544 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 35: /* function_def_list: function_cb_type_list function_def  */
#line 468 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyvsp[-1].m_ast)->appendChild((yyvsp[0].m_ast));
                            (yyval.m_ast) = (yyvsp[-1].m_ast);
                        }
#line 2553 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 36: /* function_def_list: function_def  */
#line 473 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_CHILDREN));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 2562 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 37: /* function_def_list: function_def_list function_def  */
#line 478 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyvsp[-1].m_ast)->appendChild((yyvsp[0].m_ast));
                            (yyval.m_ast) = (yyvsp[-1].m_ast);
                        }
#line 2571 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 38: /* function_cb_type_def: doxy_ml_comment_opt annotation_list_opt "type" function_type_def comma_semi_opt doxy_il_comment_opt  */
#line 486 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[-2].m_ast);
                            (yyval.m_ast)->appendChild(new AstNode(*(yyvsp[-3].m_token)));
                            (yyval.m_ast)->appendChild((yyvsp[-4].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-5].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 2583 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 39: /* function_cb_type_list: function_cb_type_def  */
#line 497 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_CHILDREN));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 2592 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 40: /* function_cb_type_list: function_cb_type_list function_cb_type_def  */
#line 502 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyvsp[-1].m_ast)->appendChild((yyvsp[0].m_ast));
                            (yyval.m_ast) = (yyvsp[-1].m_ast);
                        }
#line 2601 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 41: /* function_def: doxy_ml_comment_opt annotation_list_opt function_type_base_def comma_semi_opt doxy_il_comment_opt  */
#line 509 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[-2].m_ast);
                            (yyval.m_ast)->appendChild(NULL);  /* Compatibility with function type definition */
                            (yyval.m_ast)->appendChild((yyvsp[-3].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-4].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 2613 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 42: /* function_type_base_def: function_type_def  */
#line 520 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 2621 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 43: /* function_type_base_def: callback_def  */
#line 524 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 2629 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 44: /* function_type_def: ident '(' param_list_opt ')' "->" function_return_type  */
#line 533 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_FUNCTION, NULL, (yylsp[-5])));
                            (yyval.m_ast)->appendChild((yyvsp[-5].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                            (yyval.m_ast)->appendChild(NULL);  // function type null to recognize function and callback
                            (yyval.m_ast)->appendChild((yyvsp[-3].m_ast));
                        }
#line 2641 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 45: /* function_type_def: "oneway" ident '(' param_list_opt_in ')'  */
#line 541 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_FUNCTION, NULL, (yylsp[-3])));
                            (yyval.m_ast)->appendChild((yyvsp[-3].m_ast));
                            AstNode * returnAst = new AstNode(Token(TOK_RETURN));
                            returnAst->appendChild(new AstNode(*(yyvsp[-4].m_token)));
                            returnAst->appendChild(NULL);
                            (yyval.m_ast)->appendChild(returnAst);
                            (yyval.m_ast)->appendChild(NULL);  // function type null to recognize function and callback
                            (yyval.m_ast)->appendChild((yyvsp[-1].m_ast));
                        }
#line 2656 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 46: /* function_return_type: annotation_list_opt simple_data_type  */
#line 557 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_RETURN));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-1].m_ast));
                        }
#line 2666 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 47: /* function_return_type: "void"  */
#line 563 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_RETURN));
                            (yyval.m_ast)->appendChild(new AstNode(*(yyvsp[0].m_token)));
                            (yyval.m_ast)->appendChild(NULL);
                        }
#line 2676 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 48: /* param_list_opt: param_list  */
#line 571 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 2684 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 49: /* param_list_opt: "void"  */
#line 575 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = NULL;
                        }
#line 2692 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 50: /* param_list_opt: %empty  */
#line 579 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = NULL;
                        }
#line 2700 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 51: /* param_list_opt_in: param_list_in  */
#line 586 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 2708 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 52: /* param_list_opt_in: %empty  */
#line 590 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = NULL;
                        }
#line 2716 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 53: /* param_list: param_def  */
#line 599 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_CHILDREN));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 2725 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 54: /* param_list: param_list ',' param_def  */
#line 604 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyvsp[-2].m_ast)->appendChild((yyvsp[0].m_ast));
                            (yyval.m_ast) = (yyvsp[-2].m_ast);
                        }
#line 2734 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 55: /* param_list_in: param_def_in  */
#line 611 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_CHILDREN));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 2743 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 56: /* param_list_in: param_list_in ',' param_def_in  */
#line 616 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyvsp[-2].m_ast)->appendChild((yyvsp[0].m_ast));
                            (yyval.m_ast) = (yyvsp[-2].m_ast);
                        }
#line 2752 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 57: /* param_def: param_dir simple_data_type_scope ident_opt annotation_list_opt  */
#line 626 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_PARAM, NULL, (yylsp[-1])));
                            (yyval.m_ast)->appendChild((yyvsp[-1].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            AstNode *n = ((yyvsp[-3].m_token)) ? new AstNode(*(yyvsp[-3].m_token)) : NULL;
                            (yyval.m_ast)->appendChild(n);
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 2765 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 58: /* param_def_in: param_dir_in simple_data_type_scope ident_opt annotation_list_opt  */
#line 637 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_PARAM, NULL, (yylsp[-1])));
                            (yyval.m_ast)->appendChild((yyvsp[-1].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            AstNode *n = ((yyvsp[-3].m_token)) ? new AstNode(*(yyvsp[-3].m_token)) : NULL;
                            (yyval.m_ast)->appendChild(n);
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 2778 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 59: /* param_dir_in: "in"  */
#line 651 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_token) = (yyvsp[0].m_token);
                        }
#line 2786 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 60: /* param_dir_in: %empty  */
#line 655 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_token) = NULL;
                        }
#line 2794 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 61: /* param_dir: param_dir_in  */
#line 660 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_token) = (yyvsp[0].m_token);
                        }
#line 2802 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 62: /* param_dir: "out"  */
#line 664 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_token) = (yyvsp[0].m_token);
                        }
#line 2810 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 63: /* param_dir: "inout"  */
#line 668 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_token) = (yyvsp[0].m_token);
                        }
#line 2818 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 64: /* callback_def: ident ident  */
#line 677 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_FUNCTION, NULL, (yylsp[0])));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                            (yyval.m_ast)->appendChild(NULL);  // return type null to recognize function and callback
                            (yyval.m_ast)->appendChild((yyvsp[-1].m_ast));
                            (yyval.m_ast)->appendChild(NULL);
                        }
#line 2830 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 65: /* callback_def: ident ident '(' callback_param_list_opt ')'  */
#line 685 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_FUNCTION, NULL, (yylsp[-3])));
                            (yyval.m_ast)->appendChild((yyvsp[-3].m_ast));
                            (yyval.m_ast)->appendChild(NULL);  // return type null to recognize function and callback
                            (yyval.m_ast)->appendChild((yyvsp[-4].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-1].m_ast));
                        }
#line 2842 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 66: /* callback_param_list_opt: callback_param_list  */
#line 696 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 2850 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 67: /* callback_param_list_opt: %empty  */
#line 700 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = NULL;
                        }
#line 2858 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 68: /* callback_param_list: callback_param  */
#line 707 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_CHILDREN));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 2867 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 69: /* callback_param_list: callback_param_list comma_opt callback_param  */
#line 712 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[-2].m_ast);
                            (yyvsp[-2].m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 2876 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 70: /* callback_param: ident  */
#line 719 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_PARAM, NULL, (yylsp[0])));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                            /* To be commaptible with param_def. */
                            (yyval.m_ast)->appendChild(NULL);
                            (yyval.m_ast)->appendChild(NULL);
                            (yyval.m_ast)->appendChild(NULL);
                        }
#line 2889 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 71: /* typedef_def: "type" ident '=' data_type  */
#line 733 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-3].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 2899 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 72: /* struct_def: "struct" name_opt '{' struct_member_list '}'  */
#line 744 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-4].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[-3].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-1].m_ast));
                        }
#line 2909 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 73: /* struct_def: "struct" ident  */
#line 750 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-1].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 2918 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 74: /* struct_member_list: struct_member  */
#line 761 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_CHILDREN));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 2927 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 75: /* struct_member_list: struct_member_list struct_member  */
#line 766 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyvsp[-1].m_ast)->appendChild((yyvsp[0].m_ast));
                            (yyval.m_ast) = (yyvsp[-1].m_ast);
                        }
#line 2936 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 76: /* struct_member: doxy_ml_comment_opt struct_member_options_list struct_data_type ident annotation_list_opt semi_opt doxy_il_comment_opt  */
#line 776 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_STRUCT_MEMBER));
                            (yyval.m_ast)->appendChild((yyvsp[-3].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-4].m_ast));
                            (yyval.m_ast)->appendChild(new AstNode(Token(TOK_INT_LITERAL, new IntegerValue((yyvsp[-5].m_int)))));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-6].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 2950 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 77: /* struct_member_options_list: struct_member_options_list struct_member_options  */
#line 789 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_int) = (yyvsp[-1].m_int) | (yyvsp[0].m_int);
                        }
#line 2958 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 78: /* struct_member_options_list: %empty  */
#line 793 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_int) = 0;
                        }
#line 2966 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 79: /* struct_member_options: "optional"  */
#line 800 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_int) = 1;
                        }
#line 2974 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 80: /* struct_member_options: "byref"  */
#line 804 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_int) = 2;
                        }
#line 2982 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 81: /* struct_data_type: simple_data_type  */
#line 811 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 2990 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 82: /* struct_data_type: union_def  */
#line 815 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 2998 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 83: /* union_def: "union" '(' ident ')' '{' union_case_list '}'  */
#line 821 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-6].m_token));
                            (yyval.m_ast)->appendChild(NULL);
                            (yyval.m_ast)->appendChild((yyvsp[-4].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-1].m_ast));
                        }
#line 3009 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 84: /* union_type_def: "union" ident '{' union_case_list '}'  */
#line 829 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-4].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[-3].m_ast));
                            (yyval.m_ast)->appendChild(NULL);
                            (yyval.m_ast)->appendChild((yyvsp[-1].m_ast));
                        }
#line 3020 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 85: /* union_type_def: "union" ident  */
#line 836 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-1].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                            (yyval.m_ast)->appendChild(NULL);
                        }
#line 3030 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 86: /* union_case_list: union_case  */
#line 844 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_CHILDREN));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3039 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 87: /* union_case_list: union_case_list union_case  */
#line 849 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyvsp[-1].m_ast)->appendChild((yyvsp[0].m_ast));
                            (yyval.m_ast) = (yyvsp[-1].m_ast);
                        }
#line 3048 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 88: /* union_case: "case" union_case_expr_list ':' union_member_list_opt  */
#line 857 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_UNION_CASE));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3058 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 89: /* union_case: "default" ':' union_member_list_opt  */
#line 863 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_UNION_CASE));
                            (yyval.m_ast)->appendChild(new AstNode(*(yyvsp[-2].m_token)));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3068 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 90: /* union_case_expr_list: int_const_expr  */
#line 872 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_CHILDREN));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3077 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 91: /* union_case_expr_list: union_case_expr_list ',' int_const_expr  */
#line 877 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyvsp[-2].m_ast)->appendChild((yyvsp[0].m_ast));
                            (yyval.m_ast) = (yyvsp[-2].m_ast);
                        }
#line 3086 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 92: /* union_member_list_opt: union_member_list  */
#line 885 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3094 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 93: /* union_member_list_opt: "void"  */
#line 889 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_CHILDREN));
                            (yyval.m_ast)->appendChild(new AstNode(Token(*(yyvsp[0].m_token))));
                        }
#line 3103 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 94: /* union_member_list_opt: %empty  */
#line 894 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = NULL;
                        }
#line 3111 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 95: /* union_member_list: union_member  */
#line 901 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_CHILDREN));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));

                        }
#line 3121 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 96: /* union_member_list: union_member_list union_member  */
#line 907 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyvsp[-1].m_ast)->appendChild((yyvsp[0].m_ast));
                            (yyval.m_ast) = (yyvsp[-1].m_ast);
                        }
#line 3130 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 97: /* union_member: doxy_ml_comment_opt struct_member_options_list simple_data_type ident annotation_list_opt semi_opt doxy_il_comment_opt  */
#line 914 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_CHILDREN));
                            (yyval.m_ast)->appendChild((yyvsp[-3].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-4].m_ast));
                            (yyval.m_ast)->appendChild(new AstNode(Token(TOK_INT_LITERAL, new IntegerValue((yyvsp[-5].m_int)))));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-6].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3144 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 98: /* simple_data_type_scope: ident "::" typename  */
#line 927 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_IFACE_SCOPE));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3154 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 99: /* simple_data_type_scope: simple_data_type  */
#line 933 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3162 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 100: /* simple_data_type: list_type  */
#line 940 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3170 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 101: /* simple_data_type: array_type  */
#line 944 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3178 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 102: /* simple_data_type: typename  */
#line 948 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3186 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 103: /* data_type: simple_data_type  */
#line 954 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3194 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 104: /* data_type: struct_def  */
#line 958 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3202 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 105: /* data_type: enum_def  */
#line 962 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3210 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 106: /* typename: ident  */
#line 968 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3218 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 107: /* name_opt: ident  */
#line 974 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3226 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 108: /* name_opt: %empty  */
#line 978 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = NULL;
                        }
#line 3234 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 109: /* list_type: "list" '<' simple_data_type '>'  */
#line 987 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-3].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[-1].m_ast));
                        }
#line 3243 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 110: /* array_type: simple_data_type '[' int_const_expr ']'  */
#line 997 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_ARRAY));
                            (yyval.m_ast)->appendChild((yyvsp[-3].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-1].m_ast));
                            (yyval.m_ast)->reverseExpr();
                        }
#line 3254 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 111: /* annotation_list_opt: annotation_list  */
#line 1007 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3262 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 112: /* annotation_list_opt: %empty  */
#line 1011 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = NULL;
                        }
#line 3270 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 113: /* annotation_list: annotation  */
#line 1020 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_CHILDREN));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3279 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 114: /* annotation_list: annotation_list annotation  */
#line 1025 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyvsp[-1].m_ast)->appendChild((yyvsp[0].m_ast));
                            (yyval.m_ast) = (yyvsp[-1].m_ast);
                        }
#line 3288 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 115: /* annotation: '@' ident ':' ident annotation_value_opt  */
#line 1035 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_ANNOTATION));
                            (yyval.m_ast)->appendChild((yyvsp[-3].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[-1].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3299 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 116: /* annotation: '@' ident annotation_value_opt  */
#line 1042 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_ANNOTATION));
                            (yyval.m_ast)->appendChild(NULL);
                            (yyval.m_ast)->appendChild((yyvsp[-1].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3310 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 117: /* annotation_value_opt: '(' const_expr ')'  */
#line 1052 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[-1].m_ast);
                        }
#line 3318 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 118: /* annotation_value_opt: '(' ')'  */
#line 1056 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = NULL;
                        }
#line 3326 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 119: /* annotation_value_opt: %empty  */
#line 1060 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = NULL;
                        }
#line 3334 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 120: /* const_expr: int_const_expr  */
#line 1066 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3342 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 121: /* const_expr: string_literal  */
#line 1070 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3350 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 122: /* doxy_ml_comment_opt: doxy_ml_comment  */
#line 1077 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3358 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 123: /* doxy_ml_comment_opt: %empty  */
#line 1081 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = NULL;
                        }
#line 3366 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 124: /* doxy_ml_comment: "doxygen ml. comment"  */
#line 1087 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            // Merge string literals into one string. Remove first '\n'
                            Value * v = (yyvsp[0].m_token)->getValue();
                            StringValue * s = dynamic_cast<StringValue *>(v);
                            assert(s);
                            s = new StringValue(s->toString().substr(1, s->toString().size() - 1));
                            (yyvsp[0].m_token)->setValue(s);
                            (yyval.m_ast) = new AstNode(*(yyvsp[0].m_token));
                        }
#line 3380 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 125: /* doxy_ml_comment: doxy_ml_comment "doxygen ml. comment"  */
#line 1097 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) =  mergeString(&(yyvsp[-1].m_ast)->getToken(), (yyvsp[0].m_token));
                        }
#line 3388 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 126: /* doxy_il_comment_opt: doxy_il_comment_opt "doxygen il. comment"  */
#line 1104 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            if((yyvsp[-1].m_ast))
                            {
                                (yyval.m_ast) =  mergeString(&(yyvsp[-1].m_ast)->getToken(), (yyvsp[0].m_token));
                            }
                            else
                            {
                                (yyval.m_ast) =  new AstNode(*(yyvsp[0].m_token));
                            }
                        }
#line 3403 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 127: /* doxy_il_comment_opt: %empty  */
#line 1115 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = NULL;
                        }
#line 3411 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 128: /* int_const_expr: expr  */
#line 1124 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_EXPR, NULL, (yylsp[0])));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3420 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 129: /* expr: int_value  */
#line 1131 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3428 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 130: /* expr: float_value  */
#line 1135 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3436 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 131: /* expr: ident  */
#line 1139 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3444 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 132: /* expr: expr '+' expr  */
#line 1143 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-1].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3454 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 133: /* expr: expr '-' expr  */
#line 1149 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-1].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3464 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 134: /* expr: expr '*' expr  */
#line 1155 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-1].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3474 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 135: /* expr: expr '/' expr  */
#line 1161 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-1].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3484 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 136: /* expr: expr '%' expr  */
#line 1167 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-1].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3494 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 137: /* expr: expr '&' expr  */
#line 1173 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-1].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3504 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 138: /* expr: expr '|' expr  */
#line 1179 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-1].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3514 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 139: /* expr: expr '^' expr  */
#line 1185 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-1].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3524 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 140: /* expr: expr "<<" expr  */
#line 1191 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-1].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3534 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 141: /* expr: expr ">>" expr  */
#line 1197 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-1].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[-2].m_ast));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3544 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 142: /* expr: unary_expr  */
#line 1203 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                            {
                                (yyval.m_ast) = (yyvsp[0].m_ast);
                            }
#line 3552 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 143: /* expr: '(' expr ')'  */
#line 1207 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[-1].m_ast);
                            //$$->setLocation(@1, @3);
                        }
#line 3561 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 144: /* unary_expr: '+' expr  */
#line 1214 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3569 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 145: /* unary_expr: '-' expr  */
#line 1218 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_UNARY_NEGATE, NULL, (yylsp[-1])));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3578 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 146: /* unary_expr: '~' expr  */
#line 1223 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[-1].m_token));
                            (yyval.m_ast)->appendChild((yyvsp[0].m_ast));
                        }
#line 3587 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 147: /* int_value: "integer"  */
#line 1230 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[0].m_token));
                        }
#line 3595 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 148: /* int_value: "true"  */
#line 1234 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_INT_LITERAL, new IntegerValue(1), (yylsp[0])));
                        }
#line 3603 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 149: /* int_value: "false"  */
#line 1238 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(Token(TOK_INT_LITERAL, new IntegerValue(0), (yylsp[0])));
                        }
#line 3611 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 150: /* float_value: "float"  */
#line 1244 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[0].m_token));
                        }
#line 3619 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 151: /* string_literal: "string"  */
#line 1250 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[0].m_token));
                        }
#line 3627 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 152: /* string_literal: string_literal "string"  */
#line 1254 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) =  mergeString(&(yyvsp[-1].m_ast)->getToken(), (yyvsp[0].m_token));
                        }
#line 3635 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 153: /* ident: "identifier"  */
#line 1260 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = new AstNode(*(yyvsp[0].m_token));
                        }
#line 3643 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 154: /* ident_opt: ident  */
#line 1266 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = (yyvsp[0].m_ast);
                        }
#line 3651 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;

  case 155: /* ident_opt: %empty  */
#line 1270 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"
                        {
                            (yyval.m_ast) = NULL;
                        }
#line 3659 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"
    break;


#line 3663 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/build/erpcgen/erpcgen_parser.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, lexer, resultAST, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= END)
        {
          /* Return failure if at end of input.  */
          if (yychar == END)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, lexer, resultAST);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, lexer, resultAST);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, lexer, resultAST, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, lexer, resultAST);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, lexer, resultAST);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1275 "/home/patrick/erpc/server/ra_wifi_erpc_server/r_wifi_erpc_server/erpc/erpcgen/src/erpcgen_parser.y"


/* code goes here */

static int yylex(YYSTYPE * lvalp, YYLTYPE * yylloc, ErpcLexer * lexer)
{
    Token * token = lexer->getNextToken();
    if (!token)
    {
        return END;
    }

    lvalp->m_token = token;
    *yylloc = token->getLocation();
    return token->getToken();
}

static void yyerror(YYLTYPE * yylloc, ErpcLexer * lexer, AstNode ** resultAST, const char * error)
{
    (void)resultAST;
    throw syntax_error(format_string("file %s:%d:%d: %s\n", lexer->getFileName().c_str(),
        yylloc->m_firstLine, yylloc->m_firstChar, error));
}

const char * get_token_name(int tok)
{
    return yytname[YYTRANSLATE(tok)];
}

static AstNode * mergeString(Token * t1, Token * t2)
{
    // Merge string literals into one string.
    Value * v1 = t1->getValue();
    Value * v2 = t2->getValue();

    if (v1 && v2)
    {
        StringValue * s1 = dynamic_cast<StringValue *>(v1);
        StringValue * s2 = dynamic_cast<StringValue *>(v2);
        if (s1 && s2)
        {
            StringValue * s = new StringValue(std::string(s1->toString()) + std::string(s2->toString()));
            token_loc_t newTokLocation = mergeLocation(t1->getLocation(), t2->getLocation());
            return new AstNode(Token(t2->getToken(), s, newTokLocation));
        }
    }

    return new AstNode(*t2);
}

token_loc_t mergeLocation(const token_loc_t & l1, const token_loc_t & l2)
{
    token_loc_t newTokLocation;
    newTokLocation.m_firstLine = l1.m_firstLine;
    newTokLocation.m_firstChar = l1.m_firstChar;
    newTokLocation.m_lastLine = l2.m_lastLine;
    newTokLocation.m_lastChar = l2.m_lastChar;
    return newTokLocation;
}
