#ifndef TOKEN_H
# define TOKEN_H

# ifndef ARGUMENT_SIZE
#  define ARGUMENT_SIZE 1024
# endif

// typedef enum {
// 	TOKEN_PIPE,
// 	TOKEN_AND,
// 	TOKEN_OR,
// 	// TOKEN_SEMI,
// 	TOKEN_BACKGROUND,
// 	TOKEN_REDIRECT_OUT,
// 	TOKEN_APPEND_OUT,
// 	TOKEN_REDIRECT_IN,
// 	TOKEN_LPAREN,
// 	TOKEN_RPAREN,
// 	TOKEN_LBRACE,
// 	TOKEN_RBRACE,
// 	TOKEN_WORD,
// 	TOKEN_UNKNOWN,
// 	NUM_TOKEN_TYPES
// } TokenType;
typedef enum {
	METACHAR_NONE,
	METACHAR_PIPE,				// |
	METACHAR_INPUT_REDIRECT,	// <
	METACHAR_OUTPUT_REDIRECT,	// >
	METACHAR_APPEND_REDIRECT,	// >>
	METACHAR_HEREDOC,			// <<
	METACHAR_SINGLE_QUOTE,		// '
	METACHAR_DOUBLE_QUOTE,		// "
	METACHAR_DOLLAR,			// $
	METACHAR_ENV_VAR,			// $ followed by characters
	METACHAR_EXIT_STATUS,		// $?
	TOKEN_WORD,
}	TokenType;

typedef struct	s_token {
	TokenType		type;
	char			*word;
}				t_token;

t_token	**ft_lexer(char *line);

#endif
