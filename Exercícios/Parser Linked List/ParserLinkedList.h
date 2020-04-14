#ifndef __ParserLinkedList_H__
#define __ParserLinkedList_H__

typedef struct tList *List;
typedef union Value Value;
typedef enum TokenType TokenType;
List add(Value value, TokenType type);
#endif