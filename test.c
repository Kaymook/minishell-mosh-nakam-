
#include "srcs/includes/minishell.h"

TokenEntry *init_token_entries() {
	TokenEntry *entries;

	entries = (TokenEntry *)malloc(NUM_TOKEN_TYPES * sizeof(TokenEntry));
	if (!entries)
		return (NULL);
	entries[TOKEN_PIPE] = (TokenEntry){TOKEN_PIPE, "|" };
	entries[TOKEN_AND] = (TokenEntry){TOKEN_AND, "&&"};
	entries[TOKEN_OR] = (TokenEntry){TOKEN_OR, "||"};
	entries[TOKEN_SEMI] = (TokenEntry){TOKEN_SEMI, ";"};
	entries[TOKEN_BACKGROUND] = (TokenEntry){TOKEN_BACKGROUND, "&"};
	entries[TOKEN_REDIRECT_OUT] = (TokenEntry){TOKEN_REDIRECT_OUT, ">"};
	entries[TOKEN_APPEND_OUT] = (TokenEntry){TOKEN_APPEND_OUT, ">>"};
	entries[TOKEN_REDIRECT_IN] = (TokenEntry){TOKEN_REDIRECT_IN, "<"};
	entries[TOKEN_LPAREN] = (TokenEntry){TOKEN_LPAREN, "("};
	entries[TOKEN_RPAREN] = (TokenEntry){TOKEN_RPAREN, ")"};
	entries[TOKEN_LBRACE] = (TokenEntry){TOKEN_LBRACE, "{"};
	entries[TOKEN_RBRACE] = (TokenEntry){TOKEN_RBRACE, "}"};
	return (entries);
}

int main() {
    // TokenEntryの初期化
    TokenEntry *token_entries = init_token_entries();

    // 使用例として、トークンの内容を表示する
    for (int i = 0; i < NUM_TOKEN_TYPES; ++i) {
        printf("Token type: %d, Text: %s\n", token_entries[i].type, token_entries[i].text);
    }

    // メモリの解放
    free(token_entries);
}

// int main() {
// 	TokenEntry **tokens;
// 	tokens = (TokenEntry **)malloc(sizeof(TokenEntry *));
// 	if (!tokens)
// 		exit(1);
// 	size_t allocated_size = sizeof(TokenEntry *);
// 	printf("Allocated size: %zu bytes\n", allocated_size);
// 	free(tokens);
// }