/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 01:09:38 by mosh              #+#    #+#             */
/*   Updated: 2024/05/25 01:30:08 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/includes/minishell.h"
#include <assert.h>
#include <stdio.h>

#include "minishell.h"


#include "minishell.h"
#include <stdio.h>


// ASTノードの内容を表示する関数
void print_ast(t_ast_node *node, int level) {
    if (node == NULL) {
        return;
    }

    // インデントのためのスペースを表示
    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    // ノードのタイプに応じて情報を表示
    if (node->nodetype == NODE_COMMAND) {
        printf("Command: ");
    } else if (node->nodetype == NODE_PIPELINE) {
        printf("Pipeline: ");
    }

    // 引数を表示
    if (node->args) {
        printf("Args: ");
        for (int i = 0; node->args[i] != NULL; i++) {
            printf("'%s' ", node->args[i]);
        }
    }
    printf("\n");

    // 子ノードを再帰的に表示
    print_ast(node->left, level + 1);
    print_ast(node->right, level + 1);
}


// 引数の配列を解放するヘルパー関数
void free_args(char **args) {
    if (args) {
        for (int i = 0; args[i] != NULL; i++) {
            free(args[i]);
        }
        free(args);
    }
}

// ASTノードを解放する関数
void free_ast(t_ast_node *node) {
    if (node == NULL) {
        return;
    }

    // 再帰的に子ノードを解放
    free_ast(node->left);
    free_ast(node->right);

    // ノードが保持するリソースを解放
    free_args(node->args);

    // ノード自体を解放
    free(node);
}

// テスト対象の関数
extern t_ast_node *parse_command(t_token **tokens);

// テスト用のヘルパー関数: トークンリストを作成
t_token **create_test_tokens(const char *input) {
    // ここでは簡単のため、静的にトークンを生成します。
    // 実際にはlexerを使ってトークンを生成することが望ましいです。
    t_token **tokens = malloc(2 * sizeof(t_token*));
    tokens[0] = malloc(sizeof(t_token));
    tokens[0]->type = TOKEN_WORD;
    tokens[0]->word = strdup(input);
    tokens[1] = NULL;  // トークンリストの終端
    return tokens;
}

// テストケース1: 単一のコマンドを解析
void test_single_command() {
    t_token **tokens = create_test_tokens("ls");
    t_ast_node *ast = parse_command(tokens);

    assert(ast != NULL);
    assert(ast->nodetype == NODE_COMMAND);
    assert(strcmp(ast->args[0], "ls") == 0);

  // ASTの内容を表示
    printf("AST Structure:\n");
    print_ast(ast, 0);

    printf("test_single_command passed.\n");

    // 後片付け
    free(tokens[0]->word);
    free(tokens[0]);
    free(tokens);
    free_ast(ast);  // ASTを解放するヘルパー関数が必要
}

// メイン関数: テストランナー
int main() {
    test_single_command();
    // 他のテストケースもここに追加
    printf("All tests passed.\n");
    return 0;
}