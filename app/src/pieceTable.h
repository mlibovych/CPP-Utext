#pragma once

#include <list>
#include <tuple>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

enum class Source {
    orig,
    added
};

struct Piece {
    int m_start; // index in the source line
    int m_len; // len of piece
    Source m_source; // original or added, true == original

    explicit Piece(int start, int len, Source source) : m_start(start), m_len(len),
                                                      m_source(source) {}
    explicit Piece(const Piece& p) : m_start(p.m_start), m_len(p.m_len),
                                     m_source(p.m_source) {}
};

class pieceTable {
    char *m_original;
    char *m_added;
    list<Piece> m_pieces;
    int m_added_size;
    int m_added_capacity;
    int m_orig_size;

    list<Piece>::iterator m_item;
    int m_index;

public:
    pieceTable();
    pieceTable(const std::string& original);
    ~pieceTable();

    const char *getOrig() const {return m_original;}
    char *getAdded() const {return m_added;}
    list<Piece> getList() const {return m_pieces;}
    int getSize() const {return m_added_size;}
    int getCapac() const {return m_added_capacity;}

    char getChar(void);
    void resetIndex(void);
    bool setIndex(int index);
    void addText(char *str, int index, int len);

private:
    char *strdup(const std::string& str, int *len) const;
    void init_variables(void);
    void realloc_added(int len);
    char *alloc_memory(int size) const;

    void splitNode(list<Piece>::iterator it, int counter, char *str, int index, int len);
    void insertNode(list<Piece>::iterator it, char *str, int len);
};
