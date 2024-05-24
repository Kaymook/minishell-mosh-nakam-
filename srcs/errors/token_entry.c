#include "../includes/minishell.h"

t_token *init_token_entries() {
	t_token *entries;

	entries = (t_token *)malloc(NUM_TOKEN_TYPES * sizeof(t_token));
	if (!entries)
		return (NULL);
	entries[TOKEN_PIPE] = (t_token){TOKEN_PIPE, "|" };
	entries[TOKEN_AND] = (t_token){TOKEN_AND, "&&"};
	entries[TOKEN_OR] = (t_token){TOKEN_OR, "||"};
	// entries[TOKEN_SEMI] = (t_token){TOKEN_SEMI, ";"};
	entries[TOKEN_BACKGROUND] = (t_token){TOKEN_BACKGROUND, "&"};
	entries[TOKEN_REDIRECT_OUT] = (t_token){TOKEN_REDIRECT_OUT, ">"};
	entries[TOKEN_APPEND_OUT] = (t_token){TOKEN_APPEND_OUT, ">>"};
	entries[TOKEN_REDIRECT_IN] = (t_token){TOKEN_REDIRECT_IN, "<"};
	entries[TOKEN_LPAREN] = (t_token){TOKEN_LPAREN, "("};
	entries[TOKEN_RPAREN] = (t_token){TOKEN_RPAREN, ")"};
	entries[TOKEN_LBRACE] = (t_token){TOKEN_LBRACE, "{"};
	entries[TOKEN_RBRACE] = (t_token){TOKEN_RBRACE, "}"};
	entries[TOKEN_WORD] = (t_token){TOKEN_WORD, ""};
	return (entries);
}
